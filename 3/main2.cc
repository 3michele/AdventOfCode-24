#include<bits/stdc++.h>

#define N 50000
#define M 3000

// mul(a,b)
// don't()
// do()

int compute(char buffer[]) {
    const int inf = '0';
    const int sup = '9';
    bool can = true;

    int i = 0, res = 0;
    int j = 0, k = 0, x = 0; // indexes of MUL, DONT, DO respectively
    int a = 0, b = 0;

    char MUL[9] = {'m', 'u', 'l', '(', 'a', ',', 'b',')', '\0'};
    char DONT[8] = {'d', 'o', 'n', '\'', 't', '(', ')', '\0'};
    char DO[5] = {'d', 'o', '(', ')', '\0'};
    std::vector<char> number = {};
    
    while (buffer[i] != '\0') {
        // printf("char = %c\n", buffer[i]);

        // DONT 
        if (buffer[i] == DONT[k]) {
            k++;
        } else if (buffer[i] != '\n') {
            if (buffer[i] == 'd')
                k = 1;
            else 
                k = 0;
        }

        // DO
        if (buffer[i] == DO[x]) {
            x++;
        } else if (buffer[i] != '\n') {
            if (buffer[i] == 'd') 
                x = 1;
            else 
                x = 0;
        }

        // MUL
        if (int(buffer[i]) >= inf && int(buffer[i]) <= sup && (j == 4 || j == 6)) {
            // printf("1 IF\n");
            number.push_back(buffer[i]);
        } else if(buffer[i] == ',' && j == 4) {
            // printf("2 IF\n");
            j += 2;
            number.push_back('\0');
            a = std::atoi(number.data());
            number.clear();
        } else if(buffer[i] == ')' && j == 6) {
            // printf("3 IF\n");
            j += 2;
            number.push_back('\0');
            b = std::atoi(number.data());
            number.clear();
        } else if(buffer[i] == MUL[j]) {
            j++;
            // printf("4 IF\n");
        } else if (buffer[i] != '\n') {
            // printf("5 IF\n");
            if (buffer[i] == 'm')
                j = 1;
            else 
                j = 0;
            number.clear();
        }

        if (k == 7) {
            can = false;
            k = 0;
        }

        if (x == 4) {
            can = true;
            x = 0;
        }

        if (j == 8) {
            res += (can ? a*b : 0);
            j = 0;
        }
        i++;
    }

    return res;
}

int main(void) {
    FILE*  in = fopen("input.txt", "r");
    int c = 0;
    int index = 0;
    char buffer[N];
    while (1) {
        c = fgetc(in);
        if (c == EOF) 
            break;
        buffer[index++] = (char) c;
    }

    int res = compute(buffer);
    buffer[index] = '\0';
    printf("%d\n", res);

    fclose(in);

    return 0;
}