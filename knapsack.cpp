#include <iostream>
#include <vector>

using std::vector;
/*
 You are given a set of bars of gold and your goal is
 to take as much gold as possible into your bag.
 There is just one copy of each bar and for each bar
 you can either take it or not
 (hence you cannot take a fraction of a bar).
 */

int optimal_weight(int W, const vector<int> &w) {
    int val, n = w.size();
    vector<vector<int>> value(n+1, vector<int> (W+1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            value[i][j] = value[i-1][j];
            if (w[i-1] <= j) {
                val = value[i-1][j-w[i-1]] + w[i-1];
                if (value[i][j] < val)
                    value[i][j] = val;
                }
        }
    }
    return value[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
