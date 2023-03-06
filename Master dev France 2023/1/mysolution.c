#include <stdlib.h>
#include <stdio.h>

int main() {
    int N;
    if(scanf("%d", &N)==EOF){
        return 0;
    }
    int sacha_deck[2*N], your_deck[2*N];
    for (int i = 0; i < N; i++) {
        if(scanf("%d", &sacha_deck[i])==EOF){
            return 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if(scanf("%d", &your_deck[i])==EOF){
            return 1;
        }
    }
    int x=0;
    int NP = N, NG = N;
    int i =0,ip,ig;
    while(1){
        if (sacha_deck[i] > your_deck[i]) {
           NP--;
           sacha_deck[N+ip]=sacha_deck[i];
           ip++;
        } else if (your_deck[i] > sacha_deck[i]) {
            NG--;
            your_deck[N+ig]=your_deck[i];
            ig++;
        }else{
            NP--;
            NG--;
        }
        if(NP==0 && NG ==0){
        printf("N");
        return 0;
        }else if(NP==0){
            printf("P");
            return 0;
        }else if (NG==0){
            printf("G");
            return 0;
        }
        i++;
    }
    return 0;
}