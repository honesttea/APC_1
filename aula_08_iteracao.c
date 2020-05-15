#include <stdio.h>
int conta(int base, int potencia){
    int resultado = 1;
    for(int i=0; i<potencia;i++){
        resultado = resultado*base;
    }
    return resultado;
}

int main(int argc, char const *argv[]){
    int base;
    int potencia;
    int resultado;
    scanf("%d %d", &base, &potencia);
    
    resultado = conta(base, potencia);
    
    printf("%d\n", resultado);
}
