#include <stdio.h>
#include <unistd.h>

/*

####### Objetivos ##########
5 individuos começam com a doenca;
Leva 60s para o individuo ficar doente;
Durante os 60s, o individuo pode passar a doença;
Disseminacao ocorre num raio de 3;
Sem isolamento social: 100% de movimento a cada 2s;
Isolamento social parcial: 50% a cada 2s;
Isolamento social maximo: 20% se move a cada 2s;
36 segundos para a cura;
A cura demora 36s;
Cura = 90%;
Quem nao e curado, morre, nao trasmite e sai da matriz;
A simulacao ocorre em 3600s;
Ao final deve apresentar a quantidade de pessoas infectadas para cada 2s, e o total de mortos;


####### Termos ##########
Infectados assintomaticos = 'I';
Infectados sintomaticos = 'D';
Curado = 'C';
Saudavel = 'S';
Mortos = 'M';


###### Quem tá em isolamento em cada nivel? #######

Saudavel c/ isolamento maximo = 'Q'
Saudavel c/ isolamento parcial = 'W'
Saudavel sem isolamento = 'E'
Infectado c/ isolamento maximo = 'U'
Infectado c/ isolamento parcial = 'Y'
Infectado sem isolamento = 'T'
*/


//Randomizadores

//20%, check da movimentacao, isolamento social maximo.
int random20(int semente, int multiplicador, int entrada){
    int conta = ((multiplicador*semente)* semente + entrada) % 100;
    if(conta>=20){
        
        return 0;
    }
    else{
        return 1;
    }
}

//50%, check da movimentacao, isolamento social parcial.
int random50(int semente, int multiplicador, int entrada){
    int conta = ((multiplicador*semente) * semente + entrada) % 100;
    if(conta>=50){
        return 1;
    }
    else{
        return 0;
    }
}

//90%, check da morte.
int random90(int semente, int multiplicador, int entrada){
    int conta = ((multiplicador*semente) * semente + entrada) % 100;
    if(conta>=90){
        return 1;
    }
    else{
        return 0;
    }
}


//Funcao Principal
int main(){
    int entrada;
    char demografico[100][100];
    int contas=0;
    int mortos=0;
    int infectados=0;
    scanf("Coloque qualquer numero(de 1 a 30.000):%d", &entrada);

    //Colocar as pessoas na matriz
    for(int i=0; i<100; i++){
        if(contas<500){
            for(int j=0; j<100; j++){
                if (random50(i,entrada,j)!=1){
                    demografico[i][j] = ' ';
                    entrada++;
                }
                else{
                    demografico[i][j] = 'S';
                    contas++;
                }
            }
        }
    }


    //Colocar os doentes.
    for(int i = 0;i<100 && contas<5;i=i+20){
        for(int j=0;j<100;j=j+20){
            demografico[i][j] = 'I';
            contas++;
        }
    }

    for(int i=0;i<3600;i+=2){
        
        //Infeccao
        for(int i;i<100;i++){
            for(int j;j<100;j++){ 
                if(demografico[i][j]=='I'){
                    //Cima
                    if(demografico[i+1][j] == 'S' && i<100){
                        demografico[i+1][j]='I';
                    }
                    if( demografico[i+2][j]=='S' && i<100){
                        demografico[i+2][j]='I';
                    }
                    if(demografico[i+3][j] == 'S' && i<100){
                        demografico[i+3][j]='I';
                    }
                    //Baixo
                    if(demografico[i-1][j] == 'S' && i>0){
                        demografico[i-1][j]='I';
                    }
                    if( demografico[i-2][j]=='S' && i>0){
                        demografico[i-2][j]='I';
                    }
                    if(demografico[i-3][j] == 'S' && i>0){
                        demografico[i-3][j]='I';
                    }
                    //Direita
                    if(demografico[i][j+1]){
                        demografico[i][j+1]='I';
                    }
                    if(demografico[i][j+2]){
                        demografico[i][j+2]='I';
                    }
                    if(demografico[i][j+3]){
                        demografico[i][j+3]='I';
                    }
                    //Esquerda
                    if(demografico[i][j-1]){
                        demografico[i][j-1]='I';
                    }
                    if(demografico[i][j-2]){
                        demografico[i][j-2]='I';
                    }
                    if(demografico[i][j-3]){
                        demografico[i][j-3]='I';
                    }
                    }
                }
            }

        //Loop pra tirar os mortos da funcao e contar a quantidade de mortos.
        for(int i=0;i<100;i++){
            for(int j;j<100;j++){
                if(demografico[i][j]=='M'){
                    demografico[i][j]=' ';
                    mortos++;
                }

            }
        }

        //Loop pra contar quantos infectados tem.
        for(int i;i<100;i++){
            for(int j; j<100; j++){
                if(demografico[i][j]=='I'){
                    infectados++;
                }
            }
        }
        sleep(2);
        printf("Infectadas:%d Mortas:%d", infectados,mortos);
    }
        
        
        
    return 0;
}
