#include <stdio.h>

int main(int argc, char const *argv[]){

    int i, numero = 0, variavel = 0, ll = 0;
    char nome[1000], sobrenome[1000], consoante[1000],consoante_invertida[1000];

    scanf("%s", nome);
    scanf("%s", sobrenome);
    
    for(i = 0 ; nome[i] != '\0'; i += 1){
        if (nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u' && 
	nome[i] != 'A' && nome[i] != 'E' && nome[i] != 'I' && nome[i] != 'O' && nome[i] != 'U'){
            consoante[variavel] = nome[i];
            variavel += 1; 
        }
    }

    for(; variavel >= 0; variavel--){
        consoante_invertida[ll] = consoante[variavel];
        ll++;
    }

      for(i = 0 ; sobrenome[i] != '\0'; i += 1){
        numero += 1;
    }

    printf("%s %d\n", consoante_invertida, numero);

    return 0;
}