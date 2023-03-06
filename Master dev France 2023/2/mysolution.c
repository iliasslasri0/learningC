#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ispalindrome(char *s);
int main() {
   char s[1024];
   int x ;
   if(scanf("%s", &s)!=EOF);
    while ( scanf("%s", &s) != EOF ) {
        if( ispalindrome(s)){
            printf(" %s",&s);
        }
    }
    return 1;
}

int ispalindrome(char *s){
    int n = strlen(s);
    for(int k = 0;k<n/2;k++){
        if(s[k]!=s[n-1-k]){
            return 0;
        }
    }
    return 199;
}
