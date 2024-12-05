#include<bits/stdc++.h>

#define N 200

///`O(n*logn)`
int compute(std::vector<int>& a, std::unordered_map<int, std::unordered_set<int>>& m) {
    auto cmp = [&](int a, int b) {
        if (m.count(a) && m[a].count(b))
            return true;
        return false;
    };

    // Building the priority queue in this way would be O(n*logn)
    // std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
    // for (auto &v : a) 
    //     pq.emplace(v); or pq.push(v);

    // We can achieve that in O(n), using make_heap()
    std::vector<int> b = a; // O(1), since it is a reference
    std::make_heap(b.begin(), b.end(), cmp); // O(n)
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp, std::move(b));

    std::vector<int> c = {};
    // O(n*logn)    
    while (!pq.empty()) {
        int d = pq.top();
        pq.pop();
        c.push_back(d);
    }

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != c[i]) {
            return c[c.size() >> 1];
        }
    }
    return 0;
}

int main(void) {
    FILE* in = fopen("input.txt", "r");

    std::unordered_map<int, std::unordered_set<int>> m = {};
    int index = 0;
    int c = 0;
    char buffer[N] = {};

    // First processing 
    while (1) {
        c = fgetc(in); // Can never be EOF
        if (index == 0 && c == '\n')
            break;
        if (c == '\n') {
            buffer[index] = '\0';
            index = 0;

            char* token = std::strtok(buffer, "|");
            int a = std::atoi(token);
            token = std::strtok(nullptr, "|");
            int b = std::atoi(token);

            m[b].insert(a);
        } else 
            buffer[index++] = (char) c;
    }

    int res = 0;
    // Second processing 
    while (1) {
        c = fgetc(in);
        if (c == EOF) 
            break;
        if (c == '\n') {
            buffer[index] = '\0';
            std::vector<int> a = {};
            index = 0;

            char* token = std::strtok(buffer, ",");
            while (token != nullptr) {
                a.push_back(std::atoi(token));
                token = std::strtok(nullptr, ",");
            }

            res += compute(a, m);
        } else 
            buffer[index++] = (char) c;
    }

    fprintf(stdout, "%d\n", res);

    fclose(in);

    return 0;
}