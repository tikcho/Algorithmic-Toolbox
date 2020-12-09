#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    int half = right/2;
//    if (left == right) return -1;
//    if (left + 1 == right) return a[left];
    std::unordered_map<int, int> b;
    for (int i=left; i<right; i++){
        b[a[i]]++;
        if (b[a[i]] >= half+1) return b[a[i]];
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
