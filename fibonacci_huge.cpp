#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long period (long long m){
    long previous = 0;
    long current  = 1;

    for (int i = 0; i < m*m; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if (previous == 0 && current == 1)
                    return i + 1;
    }
    return 0;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;
    
    long p = period(m);
    n = n % p;
     
    if (n == 0) return 0;
    else if (n == 1) return 1;
    
    long prev = 0;
    long curr = 1;

    for(int i = 0; i < n - 1; i++)
        {
            long temp = 0;
            temp = curr;
            curr = (prev + curr) % m;
            prev = temp;
        }

    return curr % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    
//    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
