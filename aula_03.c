#include <stdio.h>

int main(int argc, char const *argv[])
{
    int douglas, rafael, gabriel, fellippe, maior, need_douglas, need_rafael, need_gabriel, sum_fellippe, left_total;
    
    scanf("%d" "%d" "%d" "%d", &douglas, &rafael, &gabriel, &fellippe);

    maior = 0;

    if (douglas > maior){
        maior = douglas;
    }
    else{
        maior = maior;
    }

    if(rafael > maior){
        maior = rafael;
    }
    else{
        maior = maior;
    }

    if(gabriel > maior){
        maior = gabriel;
    }
    else{
        maior = maior;
    }
    
    need_douglas = maior - douglas;

    need_gabriel = maior - gabriel;

    need_rafael = maior - rafael;

    sum_fellippe = need_douglas + need_gabriel + need_rafael;

    if(sum_fellippe >= maior){
        left_total = sum_fellippe - maior;
        if (left_total % 3 == 0) {
        printf("consegue\n");
        }
        else {
        printf("impossivel\n");
        }
    }
    else{
        printf("impossivel\n");
    }
    
    return 0;
}