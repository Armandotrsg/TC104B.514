#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0){
        printf("Soy el proceso hijo\n");
        // * execl("/workspace/TC104B.514/hola.exe","hola.exe",NULL); //Ruta, nombre del ejecutable, NULL porque\
        ya no hay más argumentos
        execlp("hola.exe","hola.exe",NULL); //Después de haber agregado en el path la carpeta con\
        export PATH=$PATH:$pwd
        sleep(5); //Ya no se ejecuta porque el execl reemplazó los procesos siguientes
        
    } else {
        printf("Soy el proceso padre\n");
        wait(NULL); //Espera a que acaben los procesos hijos    
    }
    return 0;
}