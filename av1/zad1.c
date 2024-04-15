#include <stdio.h>

// O((m-1)(n-1))
int main(void) {
    int m = 4, n = 4;
    int matrica[4][4] = {{0,1,1,1},{0,1,1,1},{1,1,0,0},{0,0,1,1}};

    int brojac = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i != m - 1 && j != n - 1) { // ne smije biti zadnji red / stupac
                if(matrica[i][j] == 1 && matrica[i][j + 1] == 1 && matrica[i + 1][j] == 1 && matrica[i + 1][j + 1] == 1) {
                    brojac++;
                }
            }
        }
    }

    printf("ima ukupno %d", brojac);
}