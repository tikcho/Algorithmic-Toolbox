#include <iostream>
#include <algorithm>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int current_gcd = 1;
  int rm = std::min(a,b);
  int c = std::max(a,b);
    
  while (rm != 0){
      current_gcd = rm;
      rm = c % rm;
      c = current_gcd;
  }
    
  return current_gcd;
}

//void test_solution() {
//    assert(gcd_fast(18, 35) == 1);
//    assert(gcd_fast(28851538, 1183019) == 17657);
//}

int main() {
  int a, b;
  std::cin >> a >> b;
    
//  std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
    
//  test_solution();
  return 0;
}
