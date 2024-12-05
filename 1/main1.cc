#include <bits/stdc++.h>

int main(void) {
    FILE* in;

    in = fopen("input.txt", "r");

    std::vector<int> left = {};
    std::vector<int> right = {};

    int a, b;
    while(fscanf(in, "%d %d\n", &a, &b) != EOF) {
        left.push_back(a);
        right.push_back(b);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int res = 0;

    for (size_t i = 0; i < left.size(); i++) {
        res += std::abs(left[i] - right[i]);
    }

    fprintf(stdout, "%d\n", res);

    fclose(in);

    return 0;
}