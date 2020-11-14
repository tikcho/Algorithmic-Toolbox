#include <iostream>

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

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    
    long long p = n % 60;

    for (int i = 2; i < p + 3; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 60;
    }

    return (current - 1) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    
//    std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n)<<std::endl;
}
