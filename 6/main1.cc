#include<bits/stdc++.h>

#define N 500
#define M 200

// UP, RIGHT, DOWN, LEFT
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

int rotate(const int index) {
    return (index + 1) % 4;
}

/// O(n*m), in-place
void compute(char map[N][M], const int i, const int j, const int n, const int m, int* res, int index) {
    if (map[i][j] != '*')
        (*res)++;
    map[i][j] = '*';

    int x = i + X[index];
    int y = j + Y[index];
    if (x < n && x >= 0 && y < m && y >= 0) {
        if (map[x][y] == '#') {
            do {
                int next = rotate(index);
                x += X[next] - X[index];
                y += Y[next] - Y[index];
                index = next;

                if (!(x < n && x >= 0 && y < m && y >= 0))  
                    return;
            } while (map[x][y] == '#');
        }
        compute(map, x, y, n, m, res, index);
    } 
}

int main(void) {
    FILE* in = fopen("input.txt", "r");
    int c = 0;
    int n = 0, col = 0, m;
    int a = 0, b = 0;

    // Processing input 
    char map[N][M] = {};
    while (1) {
        c = fgetc(in);
        if (c == EOF) 
            break;
        else if (c == '\n') {
            map[n++][col] = '\0';
            m = col;
            col = 0;
        } else {
            // Starting position
            if (c == '^') {
                a = n;
                b = col;
            }
            map[n][col++] = (char) c;
        }
    }

    // Compute 
    int res = 0;
    compute(map, a, b, n, m, &res, 0);

    fprintf(stdout, "%d\n", res);

    fclose(in);

    return 0;
}