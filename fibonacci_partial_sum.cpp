#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long sum = 0;

    long long previous1 = 0;
    long long current1  = 1;
    
    long long previous2 = 0;
    long long current2  = 1;
    
    long long p1 = (from-1) % 60;
    long long p2 = to % 60;

    for (int i = 2; i < p1 + 3; ++i) {
        long long tmp_previous1 = previous1;
        previous1 = current1;
        current1 = (tmp_previous1 + current1) % 60;
    }
    for (int j = 2; j < p2 + 3; ++j) {
        long long tmp_previous2 = previous2;
        previous2 = current2;
        current2 = (tmp_previous2 + current2) % 60;
    }

    return (((current2 - 1) - (current1-1)) % 10 + 10)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
