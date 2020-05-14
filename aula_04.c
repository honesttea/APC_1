#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero, total, proposicao;
    
    scanf("%d", &numero);
    
    total = 0;
    
    for (proposicao = 1; proposicao <= numero; proposicao++){
        if (numero % proposicao == 0) {
            total++;
        }
    }

    if(total>2){
        printf("nao primo\n");
    }
    else{
        printf("primo\n");
    }

    return 0;
}