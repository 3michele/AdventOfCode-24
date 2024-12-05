#include<bits/stdc++.h>

int main() {
    std::vector<char> sos = {};

    sos.push_back('1');
    sos.push_back('0');
    sos.push_back('0');
    sos.push_back('0');
    sos.push_back('\0');

    auto now = std::atoi(sos.data());
    std::cout << "res = " << now * 5 << "\n";
}