#include <iostream>
#include<cmath>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int tmp = 0;
    int sum = 1;

    for (int i = 0; i < n; ++i) {
        tmp = previous;
        previous = current;
        current = (tmp + current) % 10;
    }

    sum = current * previous;

    return sum % 10;
}

int fibonacci_sum_squares_fast2(long long n) {
    if (n < 2)
        return n;
    n = n % 60;
     
    if (n <= 1)
        return n;
    
    long prev = 0;
    long curr = 1;

    for(int i = 0; i < n; i++)
        {
            long temp = 0;
            temp = curr;
            curr = (prev + curr) % 10;
            prev = temp;
        }

    int sum = curr * prev;

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
//    std::cout << fibonacci_sum_squares_naive(n)<<std::endl;
//    std::cout << fibonacci_sum_squares_fast(n)<<std::endl;
    std::cout << fibonacci_sum_squares_fast2(n)<<std::endl;
}
