#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main() {
    char c,
         may;
    int n;
    do {
        n = read(STDIN_FILENO,&c,1);
        if (toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'U') {
            may = '1';
            write(STDOUT_FILENO,&may,1);
        }
        
        
    } while (n != 0);
}