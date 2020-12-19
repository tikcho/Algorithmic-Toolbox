#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
/* You are given a primitive calculator that can perform the following three operations with the current number 𝑥: multiply 𝑥 by 2, multiply 𝑥 by 3, or add 1 to 𝑥. Your goal is given a positive integer 𝑛, find the minimum number of operations needed to obtain the number 𝑛 starting from the number 1. */

vector<int> optimal_sequence(int n) {
    std::vector<int> weights;
    std::vector<int> sequence;
    std::vector<int> final_sequence;
    
    int x, w;
    for (int i = 0; i <= n; i++) {
        if(i <= 1){
            x = i;
            w = 0;
        } else {
            x = i-1;
            w = weights[x]+1;
            if ((i % 3 == 0) && (weights[i/3] < w)){
                x = i/3;
                w = weights[x]+1;
            }
            if ((i % 2 == 0) && (weights[i/2] < w)){
                x = i/2;
                w = weights[x]+1;
            }
        }
        sequence.push_back(x);
        weights.push_back(w);
    }
    
    while(n > 1){
        final_sequence.push_back(n);
        n = sequence[n];
    }
    final_sequence.push_back(1);

    reverse(final_sequence.begin(), final_sequence.end());
    return final_sequence;
}

// Below is a GreedyCalculator(𝑛) -> not a correct solusion:
// ----------------------------------------------
//vector<int> optimal_sequence(int n) {
//  std::vector<int> sequence;
//  while (n >= 1) {
//    sequence.push_back(n);
//    if (n % 3 == 0) {
//      n /= 3;
//    } else if (n % 2 == 0) {
//      n /= 2;
//    } else {
//      n = n - 1;
//    }
//  }
//  reverse(sequence.begin(), sequence.end());
//  return sequence;
//}
// ----------------------------------------------

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
