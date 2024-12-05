#include<bits/stdc++.h>

#define N 50000
#define M 3000

// mul(a,b)

int compute(char buffer[]) {
    const int inf = '0';
    const int sup = '9';
    bool can = true;

    int i = 0, j = 0, res = 0;
    int a = 0, b = 0;

    char pattern[9] = {'m', 'u', 'l', '(', 'a', ',', 'b',')', '\0'};
    std::vector<char> number = {};
    
    while (buffer[i] != '\0') {

        if (int(buffer[i]) >= inf && int(buffer[i]) <= sup && (j == 4 || j == 6)) {
            number.push_back(buffer[i]);
        } else if(buffer[i] == ',' && j == 4) {
            j += 2;
            number.push_back('\0');
            a = std::atoi(number.data());
            number.clear();
        } else if(buffer[i] == ')' && j == 6) {
            j += 2;
            number.push_back('\0');
            b = std::atoi(number.data());
            number.clear();
        } else if(buffer[i] == pattern[j]) {
            j++;
        } else if (buffer[i] != '\n' && buffer[i] != pattern[j]) {
            if (buffer[i] == 'm')
                j = 1;
            else 
                j = 0;
            number.clear();
        }

        if (j == 8) {
            res += a*b;
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