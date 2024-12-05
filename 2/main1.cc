#include<bits/stdc++.h>

#define N 500

typedef std::vector<int> vi;

int main(void) {
    FILE* in = fopen("input.txt", "r");

    char c;
    int index = 0;
    int res = 0;

    while(1) {
        char buffer[N];
        c = fgetc(in);

        if (c == EOF) {
            break;
        } else if (c == '\n') {
            // Processing row
            buffer[index] = '\0';
            vi arr = {};
            char* token = std::strtok(buffer, " ");
            while (token != nullptr) {
                arr.push_back(std::atoi(token));
                token = std::strtok(nullptr, " ");
            }
            index = 0;

            // Computing 
            bool flag = true;

            if (arr.size() > 1) {
                bool inc, dec;
                if (arr[0] - arr[1] >= 0) {
                    inc = false;
                    dec = true;
                } else {
                    inc = true; 
                    dec = false;
                }
                for (size_t i = 0; i + 1 < arr.size() && flag; i++) {
                    if (std::abs(arr[i] - arr[i+1]) == 0 || std::abs(arr[i] - arr[i+1]) > 3) {
                        flag = false;
                    }
                    if (inc && !(arr[i+1] - arr[i] > 0))
                        flag = false;
                    if (dec && !(arr[i] - arr[i+1] > 0))
                        flag = false;
                }
            }
            if (flag) 
                ++res;
        } else {
            buffer[index++] = (char)c;
        }
    }

    fprintf(stdout, "%d\n", res);

    fclose(in);

    return 0;
}