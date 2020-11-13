#include <iostream>
#include <cassert>
#include <algorithm>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
    long n = std::max(a, b);
    long start = n;
    
    while (start <= (long long) a * b){
        if (start % a == 0 && start % b == 0)
          return start;
        start += n;
    }

    return (long long) a * b;
}

//void test_solution() {
//    assert(lcm_fast(6, 8) == 24);
//    assert(lcm_fast(761457, 614573) == 467970912861);
//    std::cout << "fin!" << std::endl;
//
//}

int main() {
  int a, b;
  std::cin >> a >> b;

//  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
    
//  test_solution();
  return 0;
}
