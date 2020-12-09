#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// ---------------------- 2 P A R T ------------------------------
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
void randomized_quick_sort2(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort2(a, l, m - 1);
  randomized_quick_sort2(a, m + 1, r);
}

// ---------------------- 3 P A R T ------------------------------
// a[l..i] elements < x.
// a[i+1..j-1] elements == x.
// a[j..r] elements > x.

void partition3(vector<int> &a, int l, int r, int &start, int &end) {
    int q = l, p = a[r];
    
    while (q <= r) {
        if (a[q] < p)
            swap(a[l++], a[q++]);
        else if (a[q] == p)
            q++;
        else if (a[q] > p)
            swap(a[q], a[r--]);
    }
    start = l - 1;
    end = q;
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
    if (l >= r) {
      return;
    }
    
//    int k = l + rand() % (r - l + 1);
//    swap(a[l], a[k]);
    
    int start, end;
    partition3(a, l, r, start, end);
    
    randomized_quick_sort3(a, l, start);
    randomized_quick_sort3(a, end, r);

}

// ---------------------- T E S T --------------------------------
void test(){
    for (int sz=1; sz<50; sz++){
        vector<int> a2(sz);
        vector<int> a3(sz);
        vector<int> a1(sz);

        int n;
        for (int fi=0;fi<5;fi++){
            for(int i=0;i<sz;i++){
                n=rand()%100;
                a2[i]=n;
                a3[i]=n;
                a1[i]=n;
            }
            randomized_quick_sort2(a2, 0, sz - 1);
            randomized_quick_sort3(a3, 0, sz - 1);
            if (a2 != a3){
                std::cout << " FAIL : "<< sz <<'\n';
                for (size_t i = 0; i < sz; ++i) {
                  std::cout << a1[i] << ' ';
                }
                std::cout<<'\n';
//                for (size_t i = 0; i < sz; ++i) {
//                  std::cout << a2[i] << ' ';
//                }
//                std::cout<<'\n';
                for (size_t i = 0; i < sz; ++i) {
                  std::cout << a3[i] << ' ';
                }
                std::cout<<'\n';
            }
        }
    }
}

// ---------------------- M A I N --------------------------------
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
//    test();
}
