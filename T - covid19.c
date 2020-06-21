#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
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


int random20(int entrada){
    srand(time(0));
    int conta = rand()%100;
    if(entrada==1){
        if(conta > 20){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(entrada==2){
      if(conta > 50){
            return 0;
        }
        else{
            return 1;
        }  
    }
    else{
        return 1;
    }
}

int random75(){
    int conta = rand()%100;
    if(conta >= 75){
        return 0;
    }
    if(conta >= 50 && conta < 75){
        return 1;
    }
    if(conta >= 25 && conta < 50){
        return 2;
    }
    else{
        return 3;    
    }
}

int random90(){
    int conta = rand()%100;
    if(conta > 90){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char const *argv[]){
    int demografico[100][100];
    int contas=0;
    int checagem=0;
    int mortos=0;
    int infectados=0;
    int rand1=0;
    int rand2=0;
    int infectados_j=0;
    int infectados_i=0;
    int j=0;
    int i=0;
    int cenario=0;
    int numero_infectados=0;
    int contagem;
    srand(time(0));

    printf("Cenario('1' isolamento social total;'2' isolamento social parcial;'3' sem isolamento social):");
    scanf("%d", &cenario);
    
    for(int i = 0; i<100; i++){
        for(int j=0; j<100 ;j++){
            demografico[i][j] = -2;
        }
    }
 
    for(;contas<5000;){
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100 && contas<5000; j++){
                if(rand()%100<20){
                    demografico[i][j] = -1;
                    contas++;
                }
            }
        }
    }
    
    while(numero_infectados<5){
        rand1=rand()%100;
        rand2=rand()%100;
        if(demografico[rand1][rand2]==-1){
            demografico[rand1][rand2]=0;
            numero_infectados++;
        }
    }

    for(int contador = 0; contador < 3600 ; contador+=2){
        infectados=0;

        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                if(random20(cenario)==1 && demografico[i][j]<60){
                    if (demografico[i+1][j] == -2 || demografico[i-1][j] == -2 || demografico[i][j+1] == -2 || demografico[i][j-1] == -2){
                        checagem=0;
                        while (checagem != 1){
                            if(random75() == 0 && demografico[i][j-1] == -2){
                                demografico[i][j-1] = demografico[i][j];
                                demografico[i][j] = -2 ;
                                checagem = 1;
                            }
                            else if(random75() == 1 && demografico[i-1][j] == -2){
                                demografico[i-1][j] = demografico[i][j];
                                demografico[i][j] = -2 ;
                                checagem = 1;
                            }
                            else if(random75() == 2 && demografico[i][j+1] == -2){
                                demografico[i][j+1] = demografico[i][j];
                                demografico[i][j] = -2 ;
                                checagem = 1;
                            }
                            else if(random75() == 3 && demografico[i+1][j] == -2){
                                demografico[i+1][j] = demografico[i][j];
                                demografico[i][j] = -2 ;
                                checagem = 1;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i < 100;i++){
            for(int j=0;j < 100;j++){
                if(demografico[i][j] == 96){
                    if(random90()==1){
                        demografico[i][j]= -2;
                        mortos++;
                    }else{
                        demografico[i][j]+=1;
                    }
                }
            }
        }

        for(int i=0;i < 100;i++){
            for(int j=0; j < 100; j++){
                if(demografico[i][j] > -1 && demografico[i][j] <= 96){
                    infectados++;
                }
            }
        }

        for(int i=0;i < 100;i++){
            for(int j=0; j < 100; j++){
                if(demografico[i][j] > -1){
                    demografico[i][j] += 2;
                }
            }
        }

        printf("Infectadas:%d Mortas:%d\n", infectados, mortos);
        sleep(2);

        for(int i=0;i < 100;i++){
            for(int j=0;j < 100;j++){ 
                if(demografico[i][j]>-1){
                    if(demografico[i+1][j] == -1 && i < 100 &&rand()%100>75){
                        demografico[i+1][j]=0;
                    }
                    if( demografico[i+2][j]==-1 && i < 100&&rand()%100>75){
                        demografico[i+2][j]=0;
                    }
                    if(demografico[i+3][j] == -1 && i < 100&&rand()%100>75){
                        demografico[i+3][j]=0;
                    }
                    if(demografico[i-1][j] == -1 && i>0&&rand()%100>75){
                        demografico[i-1][j]=0;
                    }
                    if( demografico[i-2][j]==-1 && i>0&&rand()%100>75){
                        demografico[i-2][j]=0;
                    }
                    if(demografico[i-3][j] == -1 && i>0&&rand()%100>75){
                        demografico[i-3][j]=0;
                    }
                    if(demografico[i][j+1] == -1 && j < 100&&rand()%100>75){
                        demografico[i][j+1]=0;
                    }
                    if(demografico[i][j+2] == -1 && j < 100&&rand()%100>75){
                        demografico[i][j+2]=0;
                    }
                    if(demografico[i][j+3] == -1 && j < 100&&rand()%100>75){
                        demografico[i][j+3]=0;
                    }
                    if(demografico[i][j-1] == -1 && j>0&&rand()%100>75){
                        demografico[i][j-1]=0;
                    }
                    if(demografico[i][j-2] == -1 && j>0&&rand()%100>75){
                        demografico[i][j-2]=0;
                    }
                    if(demografico[i][j-3] == -1 && j>0&&rand()%100>75){
                        demografico[i][j-3]=0;
                    }
                }
            }
        }
    }
    return 0;             
}
