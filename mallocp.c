#include <stdio.h>
#include <stdlib.h>

int stringlen(char * str);

int main(int argc, char*argv[]) {
     if(argc != 2) {
        printf("Usage : %s <string>\n", argv[0]);
        exit(1);
    }
    
    int ret = stringlen(argv[1]);
    int x = ret * sizeof( char );
    printf("Taille de la chaine a copier : %d\n", x);

    // Dynamically allocate memory using malloc()
    char *copy = (char *)malloc(x);

    if (copy == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }
    int i;

   
    for(i=0; i< ret ; ++i) {
        copy[i]=argv[1][i];
    }
    printf("Taille de la chaine à copier : %d\n", ret);
    printf("copy : %s\n", copy);
    free(copy);
    return 0;
}

int stringlen(char * str) {
    int i = 0;
    while(str[i]!='\0') {
        i++;
    }
    return i;
}