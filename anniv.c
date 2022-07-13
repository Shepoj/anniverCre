#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int concat(int a, int b){
    char s1[20];
    char s2[20];
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    strcat(s1, s2);
    int c = atoi(s1);
    return c;
}

int compare (void const *a, void const *b){
   int const *pa = a;
   int const *pb = b;
   return *pa - *pb;
}

int anniv() {
    srand(time(NULL));
    int L[100];
    for (int i = 0; i < 100; ++i){
        int j = rand()%30;
        int m = rand()%11;
        if (m<9) L[i] = concat(concat(j,0),m+1);
        else L[i] = concat(j+1,m+1);
    }
    qsort (L, sizeof L / sizeof *L, sizeof *L, compare);
    for (int k = 1; k < 100; ++k){
        if (L[k-1]==L[k]) return 1; 
    }
    return 0;
}

int main(){
    int ind = 0;
    for (int z = 0; z<100; ++z){
        if (anniv()==1) ind+=1;
    }
    printf("%d", ind);
    return 0;
}
