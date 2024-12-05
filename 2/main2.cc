#include<bits/stdc++.h>

#define N 500

typedef std::vector<int> vi;

bool compute_check(vi& arr) {
    bool ok = true;
    bool inc = true;
    bool dec = true;

    for (size_t i = 0; i + 1 < arr.size(); i++) {
        int diff = arr[i+1] - arr[i];
        if (diff > 0) 
            dec = false;
        if (diff < 0)
            inc = false;
        if(std::abs(diff) == 0 || std::abs(diff) > 3) {
            ok = false;
            break;
        }
    }
    return (ok && (inc || dec));
}

void compute_second_chance(vi& a, bool* OK, const int index) {
    vi b = {};
    for (size_t i = 0; i < a.size(); i++) {
        if ((int) i == index) 
            continue;
        b.push_back(a[i]);
    }

    if(compute_check(b)) 
        *OK = true;
}

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
            bool ok = false;
            // Trying to remove the first element 
            compute_second_chance(arr, &ok, 0);

            if (!ok) 
                for (size_t i = 0; i + 1 < arr.size(); i++) {
                    int diff = arr[i+1] - arr[i];
                    if (std::abs(diff) < 1 || std::abs(diff) > 3) {
                        compute_second_chance(arr, &ok, i);
                        compute_second_chance(arr, &ok, i+1);
                        break;
                    }
                    if (i + 2 < arr.size()) {
                        int diff2 = arr[i+2] - arr[i+1];

                        // (up && low) || (low && up)
                        if ((diff > 0) != (diff2 > 0)) {
                            compute_second_chance(arr, &ok, i);
                            compute_second_chance(arr, &ok, i+1);
                            compute_second_chance(arr, &ok, i+2);
                            break;
                        }
                    }
                }

            if (ok) 
                res++;
        } else {
            buffer[index++] = (char) c;
        }
    }

    printf("%d\n", res);

    return 0;
}