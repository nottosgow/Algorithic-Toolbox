#include <iostream>
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast (long long n) {
    if (n <= 1) return n;
    
    long long fib[n];
    int sum = 1;
    fib[0] = 0, fib[1] = 1;
    for (long long i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << fib[i] << endl;
        sum += fib[i] % 10;
    }
    return sum % 10;
}

int main() {
    long long n;
    cin >> n;
    cout << "naive: " << fibonacci_sum_naive (n);
//    cout << " fast: " << fibonacci_sum_fast (n);
    cout << '\b';
    return 0;
}
