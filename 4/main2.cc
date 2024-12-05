#include<bits/stdc++.h>

#define N 1000
#define M 500

int n = 0, m;

bool check(char a, char b) {
    return ((a == 'M' && b == 'S') || (a == 'S' && b == 'M'));
}

bool bounds(const int x, const int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int compute(int mat[N][M]) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (mat[i][j] == 'A') {
                if(bounds(i-1, j-1) && bounds(i-1, j+1) && (bounds(i+1, j-1) && bounds(i+1, j+1))) {
                    if (check(mat[i-1][j-1], mat[i+1][j+1]) && check(mat[i-1][j+1], mat[i+1][j-1]))
                        res++;
                }
            }
        }
    }
    return res;
}

int main(void) {
    FILE* in = fopen("input.txt", "r");

    int mat[N][M] = {};
    int c;

    int j = 0;
    while (1) {
        c = fgetc(in);
        if (c == EOF) 
            break;
        mat[n][j++] = (char) c;
        if(c == '\n') {
            n++;
            m = j;
            j = 0;
        }
    }

    int res = compute(mat);
    printf("%d\n", res);

    fclose(in);

    return 0;
}