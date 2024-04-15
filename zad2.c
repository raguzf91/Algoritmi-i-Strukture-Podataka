#include <stdio.h>

int main() {
    int polje[] = {2,4,8,8,4,2,12};
    int c = 16, brojac = 0;

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(i!=j) {
                if(polje[i] + polje[j] == c) {
                    printf("%d (%d) + %d (%d) = %d\n",polje[i],i,polje[j],j,c);
                }
            }
        }
    }
}