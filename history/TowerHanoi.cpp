#include <iostream>
#include <cmath>

void solve(int n, int src, int aux, int dest) {
    if (n == 1) {
        std::cout << src << " " << dest << std::endl;
        return;
    }
    solve(n - 1, src, dest, aux);
    std::cout << src << " " << dest << std::endl;
    solve(n - 1, aux, src, dest);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << (1 << n) - 1 << std::endl;
    solve(n, 1, 2, 3);
    return 0;
}
