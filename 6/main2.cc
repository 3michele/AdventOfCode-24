#include<bits/stdc++.h>

#define N 500
#define M 200

int X[4] = {-1, 0, +1, 0};
int Y[4] = {0, +1, 0, -1};

int rotate(const int index) {
    return (index + 1) % 4;
}

struct Pair {
    int a;
    int b;

    public : 
        Pair() : a(0), b(0) {}

        bool operator == (const Pair& other) const {
            return (this->a == other.a && this->b == other.b);
        }
};

// O(n*m)
bool compute(
    char map[N][M],
    Pair visited[N][M],
    const int i,
    const int j, 
    const int n, 
    const int m, 
    const int session, 
    int index) 
{
    auto now = visited[i][j];
    if (now.a == session && now.b == index) 
        return true;

    visited[i][j].a = session; 
    visited[i][j].b = index; 

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
                    return false;
            } while (map[x][y] == '#');
        }
        return compute(map, visited, x, y, n, m, session, index);
    } 
    return false;
}

int main(void) {
    FILE* in = fopen("input.txt", "r");
    int c = 0;
    int n = 0, m, col = 0; 
    char map[N][M];
    Pair visited[N][M];
    int a, b;

    // Process input
    while (1) {
        c = fgetc(in);
        if (c == EOF) 
            break;
        else if (c == '\n') {
            m = col;
            col = 0;
            n++;
        } else {
            if (c == '^') {
                a = n;
                b = col;
            }
            map[n][col++] = (char) c;
        }
    }

    // Compute: O(n^2 * m^2)
    int session = 0; // Same time complexity but better constant factors
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ++session;
            if (map[i][j] == '^' || map[i][j] == '#') 
                continue;
            map[i][j] = '#'; 
            res += (compute(map, visited, a, b, n, m, session, 0) ? 1 : 0);
            map[i][j] = '.';
        }
    }

    fprintf(stdout, "%d\n", res);
    fclose(in);

    return 0;
}