#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool cond = false;

void hola(int signalDumb) {
    printf("Recibí la señal %d\n", signalDumb);
}

void senalDoce(int signalDumb) {
    cond = true;
}

int main() {
    signal(12,senalDoce);
    signal(2,hola);
    while(!cond){
        printf("Trabajando\n");
        sleep(1);
    }
    printf("Aquí nunca llega\n");
    return 0;
}