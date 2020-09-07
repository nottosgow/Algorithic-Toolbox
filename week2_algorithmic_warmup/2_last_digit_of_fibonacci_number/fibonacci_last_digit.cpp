#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast (int n) {

    int fib[n + 1];
    fib[0] = 0, fib[1] = 1, fib[2] = 1;
    for (int i = 3; i <= n; i++) {

        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= 10;
    }
    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_fast(n)<<'\n';
}
