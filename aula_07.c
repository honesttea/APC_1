#include <stdio.h>

int main(int argc, char const *argv[]){
    /*Definir as variaveis*/
    char trilha[1000][1000];
    int caminho_i, caminho_j, i=0;
    int  linha, coluna,j, teste=0, ocorrencia, maximo;
    char final;

    scanf("%d %d", &linha,&coluna);

    /*Input do caminho*/
    for(int i=0; i<linha; i++){
        scanf("%s", &trilha[i][0]);
    }

    /*Onde o Gabriel ta*/
    caminho_i = 0;
    while (teste!=1){
    	caminho_j=0;
    	while(trilha[i][j]!='G' && caminho_j<coluna){
            caminho_j++;
    	}
        if(trilha[caminho_i][caminho_j]=='G'){
            teste=1;
        }
        if(teste==0){
            caminho_i++;
        }
    }


    maximo = linha*coluna;
    linha--;
    coluna--;
    
    /*check do caminho*/
    for(ocorrencia = 0;final!='S' && ocorrencia<maximo; ocorrencia++) {

        /*check do caminho livre*/
        if(trilha[caminho_i-1][caminho_j]=='V' && trilha[caminho_i-1][caminho_j]!='T' && caminho_i>0){
            trilha[caminho_i][caminho_j]='C';
            caminho_i=caminho_i-1;
        }
        else if(trilha[caminho_i+1][caminho_j]=='V' && trilha[caminho_i+1][caminho_j]!='T' && caminho_i<linha){
            trilha[caminho_i][caminho_j]='C';
            caminho_i=caminho_i+1;
        }
        else if(trilha[caminho_i][caminho_j+1]=='V' && trilha[caminho_i][caminho_j+1]!='T'&& caminho_j<coluna){
            trilha[caminho_i][caminho_j]='C';
            caminho_j=caminho_j+1;
        }
        else if(trilha[caminho_i][caminho_j-1]=='V' && trilha[caminho_i][caminho_j-1]!='T'&& caminho_j>0){
            trilha[caminho_i][caminho_j]='C';
            caminho_j=caminho_j-1;
        }
        else{
            /*se for beco sem saida*/
            if(trilha[caminho_i-1][caminho_j]=='C' && trilha[caminho_i-1][caminho_j]!='T' && caminho_i>0){
                trilha[caminho_i][caminho_j]='P';
                caminho_i=caminho_i-1;
            }
            else if(trilha[caminho_i+1][caminho_j]=='C' && trilha[caminho_i+1][caminho_j]!='T' && caminho_i<linha){
                trilha[caminho_i][caminho_j]='P';
                caminho_i=caminho_i+1;
            }
            else if(trilha[caminho_i][caminho_j+1]=='C' && trilha[caminho_i][caminho_j+1]!='T'&& caminho_j<coluna){
                trilha[caminho_i][caminho_j]='P';
                caminho_j=caminho_j+1;
            }
            else if(trilha[caminho_i][caminho_j-1]=='C' && trilha[caminho_i][caminho_j-1]!='T'&& caminho_j>0){
                trilha[caminho_i][caminho_j]='P';
                caminho_j=caminho_j-1;
            }
        }
        /*Se ele tá no final*/
        if(trilha[caminho_i-1][caminho_j]=='S' || trilha[caminho_i+1][caminho_j]=='S' || trilha[caminho_i][caminho_j+1]=='S' || trilha[caminho_i][caminho_j-1]=='S'){
            final = 'S';
        }
    }
    /*Tem final?*/
    if(final=='S'){
        printf("sim\n");
    }
    else{
        printf("nao\n");
    }

    return 0;
}