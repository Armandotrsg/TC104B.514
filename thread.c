#include <pthread.h>
#include <stdio.h>

// Para compilar:\
gcc thread.c -lpthread -o thread.exe

typedef struct thread_data {
    int threadId;
    char name[20];
    //...

} ThreadData;

void* holaMundo(void *arg){ //Regresa un apuntador a la nada y recibe un apuntador cualquiera
    ThreadData *myData = (ThreadData *)arg;
    printf("Hola desde el hilo y mi id es %d\n",myData->threadId);
    pthread_exit(NULL); //Avisa que el hilo terminó
}

int main() {
    for(int i = 0; i < 100; i++) {
        ThreadData myData;
        pthread_t threadId;
        myData.threadId = i;
        pthread_create(&threadId,NULL,holaMundo, (void *) &myData); //Si el hilo principal muere, los hilos dejan de ejecutarse
        //Hacemos un cast del myData a void *
    }
    pthread_exit(NULL); //Se espera a que todos los hilos hayan terminado
    printf("NUNCA LLEGA\n");
    //return 0;
}