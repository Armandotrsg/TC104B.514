// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/9.14.0/firebase-app.js";
import {
    collection,
    doc,
    getFirestore,
    onSnapshot
} from "https://www.gstatic.com/firebasejs/9.14.0/firebase-firestore.js";

const firebaseConfig = {
    apiKey: "AIzaSyB0SyWk0wpjyKhxKkvi0mgJro2gYP7p21Y",
    authDomain: "rescue-helper.firebaseapp.com",
    projectId: "rescue-helper",
    storageBucket: "rescue-helper.appspot.com",
    messagingSenderId: "38108453413",
    appId: "1:38108453413:web:72298d3350a99d84247dcc",
};

const app = initializeApp(firebaseConfig);

const db = getFirestore(app);

let peopleCounter = document.getElementById("peopleCounter");
let vibraciones = document.getElementById("vibraciones");

const unsub = onSnapshot(doc(db, "Edificio1", "Salon1"), (doc) => {
    peopleCounter.innerHTML = doc.data().people;
    let sensacion = "";
    //Round doc.data().vibrations to 4 decimals and absolute value
    let vib = Math.abs(Math.round(doc.data().vibrations * 10000) / 10000);
    let text = "text-success";
    if (vib < 0.0017) {
        sensacion = "Ninguna";
    } else if (vib < 0.014) {
        sensacion = "Débil";
    } else if (vib < 0.039) {
        sensacion = "Ligera";
        text = "text-warning";
    } else if (vib < 0.092) {
        sensacion = "Moderada";
        text = "text-warning";
    } else if (vib < 0.18) {
        sensacion = "Fuerte";
        text = "text-danger";
    } else if (vib < 0.34) {
        sensacion = "Muy fuerte";
        text = "text-danger";
    } else if (vib < 0.65) {
        sensacion = "Severa";
        text = "text-danger";
    } else if (vib < 1.24) {
        sensacion = "Muy severa";
        text = "text-danger";
    } else {
        sensacion = "Extrema";
        text = "text-danger";
    }
    vibraciones.innerHTML = String(vib) + " g" + "&nbsp&nbsp&nbspSensación: " + sensacion;
    vibraciones.className = "text-center mb-5" + " " + text;
});
