#include <iostream>

using namespace std;

auto sub(auto a, auto b) {
    return a - b;
}

int main() {

    cout << sub(8, 5) << '\n';

    return 0;
}