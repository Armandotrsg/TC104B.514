from http.server import BaseHTTPRequestHandler, HTTPServer
import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore
import time
from datetime import datetime

cred = credentials.Certificate('credentials.json')

app = firebase_admin.initialize_app(cred)

db = firestore.client()

class MyServer(BaseHTTPRequestHandler):
    def _set_response(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()

    def do_GET(self):
        print("Hola desde el get")
        if "/sensor1_temp" in self.path:
            current_date = datetime.now()
            date = current_date.strftime('%Y-%m-%d')
            hour = current_date.strftime('%H')
            minute = current_date.strftime('%M')
            collectionName = f'temperatura_{date}'

            sensor1_temp = self.path.split("=")[1]
            print(f"La temperatura es {sensor1_temp}")
            temperatura = db.collection(collectionName).document(f'temp_{hour}')
            temp_doc = temperatura.get()
            temp_data = temp_doc.to_dict()

            if temp_data == None:
                temperatura.set({
                    u'temperatura_{}'.format(minute): sensor1_temp
                })
            """ else:
                if encendido:
                    temperatura.update({
                        u'temperatura': sensor1_temp
                    }) """

        self._set_response()
        self.wfile.write("Hola este es mi super server. GET request for {}".format(self.path).encode('utf-8'))

port = 8080
server_address = ('', port)
httpd = HTTPServer(server_address, MyServer)
httpd.serve_forever()