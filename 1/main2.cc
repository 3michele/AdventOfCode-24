#include <bits/stdc++.h>

int main(void) {
    FILE* in;

    in = fopen("input.txt", "r");

    std::vector<int> left = {};
    std::vector<int> right = {};

    std::unordered_map<int, int> map = {};

    int a, b;
    while(fscanf(in, "%d %d\n", &a, &b) != EOF) {
        left.push_back(a);
        right.push_back(b);
        if (!map.count(b)) {
            map[b] = 1;
        } else {
            map[b] += 1;
        }
    }

    int res = 0;
    for(auto &v : left) {
        if(map.count(v)) {
            res += map[v] * v;
        }
    }    

    fprintf(stdout, "%d\n", res);

    fclose(in);

    return 0;
}