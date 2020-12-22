#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
    int m = a.size(), n = b.size();
    int L[m + 1][n + 1];
      
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                L[i][j] = 1 + L[i - 1][j - 1];
            else L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
