#include <stdio.h>

int main(int argc, char const *argv[]){

    int numb=-1;
    int numero;
    int i;
    int rotacao;

    scanf("%d", &i);
    
    while(i>0){
        char nome[1001];
        char final[1001];
        char varia[1001];
        char snome[1001];      
        scanf("%s", nome);
        scanf("%s", snome);
        
        numero=0;
        for(rotacao=0; nome[rotacao] !='\0';rotacao++){
            if(nome[rotacao]!='a' && nome[rotacao]!='e'&& nome[rotacao]!='i'&& nome[rotacao]!='o'&& nome[rotacao]!='u'){
                numb+=1;
                varia[numb]=nome[rotacao];   
            }
        }

        for(rotacao=0; numb>=0;rotacao++){
            final[rotacao]=varia[numb];   
            numb--;
        }
        final[rotacao]='\0';

        for(rotacao=0; snome[rotacao] !='\0';rotacao++){
            numero++;
        }
        
        printf("%s%d\n", final,numero);
        i--;
    }

    return 0;
}