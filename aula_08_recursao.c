#include <stdio.h>
int conta(int base, int potencia, int resultado){
    if(potencia==0){
        return resultado;
    }
    else{
        return conta(base,potencia-1, base*resultado);
    }
}

int main(int argc, char const *argv[]){
    int base;
    int potencia;
    int resultado;
    scanf("%d %d", &base, &potencia);
    
    resultado = conta(base, potencia, 1);
    
    printf("%d\n", resultado);
}