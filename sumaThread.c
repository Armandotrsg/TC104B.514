#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define NUM_THREADS 10

// Para compilar:\
gcc sumaThread.c -lpthread -o sumaThread.exe

int saldo;
sem_t protecSaldo;

void *suma (void *arg) {
    sem_wait(&protecSaldo);
    printf("El saldo inicial es %d\n",saldo);
    saldo += 100;
    printf("El saldo después es %d\n",saldo);
    sem_post(&protecSaldo);
    pthread_exit(NULL);
}

int main() {
    saldo = 0;
    pthread_t threadsInfo[NUM_THREADS];
    sem_init(&protecSaldo,0,1); //0 es un semáforo global para hilos
    //Create threads
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threadsInfo[i],NULL,suma,NULL); //Si el hilo principal muere, los hilos dejan de ejecutarse
        //Hacemos un cast del myData a void *
    }
    //Wait fir threads
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threadsInfo[i],NULL);
    }
    printf("El saldo final es %d\n",saldo);
    pthread_exit(NULL); //Se espera a que todos los hilos hayan terminado
    printf("NUNCA LLEGA\n");
    //return 0;
}