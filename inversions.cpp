#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t ave, size_t right){
    long long number_of_inversions = 0;
    long long i=left, j=ave, k=left;
    
    while ((i <= ave - 1) && (j <= right)) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            }
            else {
                b[k++] = a[j++];
                number_of_inversions = number_of_inversions + (ave - i);
            }
    }
    while (i <= ave - 1)
            b[k++] = a[i++];
    while (j <= right)
            b[k++] = a[j++];

    for (i = left; i <= right; i++){
        a[i] = b[i];
    }
    return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    size_t ave = (left + right)/ 2;
    
    if (right <= left) return number_of_inversions;
    
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
    number_of_inversions += merge(a, b, left, ave+1, right);
    
    return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
