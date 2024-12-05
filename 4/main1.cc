#include<bits/stdc++.h>

#define N 1000
#define M 500

int compute(char mat[N][M], const int n, const int m) {
    int res = 0;
    const int X[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    const int Y[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    const char MAS[3] = {'M', 'A', 'S'};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'X') {
                for (int w = 0; w < 8; w++) {
                    bool inc = true;
                    for (int u = 1; u <= 3 && inc; u++) {
                        int x = i + u*X[w];
                        int y = j + u*Y[w];
                        if (!(x < n && x >= 0 && y < m && y >= 0))
                            inc = false;
                        else if (mat[x][y] != MAS[u-1]) 
                            inc = false;
                    }
                    res += (inc ? 1 : 0);
                }
            }
        }
    }
    return res;
}

int main(void) {
    FILE* in = fopen("input.txt", "r");

    char mat[N][M] = {};

    int c;
    int n = 0, m = 0, col = 0;
    while (1) {
        c = fgetc(in);
        if (c == EOF) 
            break;
        mat[n][col++] = (char) c;
        if(c == '\n'){
            m = col;
            col = 0;
            n++;
        }
    }

    int res = compute(mat, n, m);
    
    printf("%d\n", res);
    fclose(in);

    return 0;
}