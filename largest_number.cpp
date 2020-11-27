#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using std::vector;
using std::string;
using std::min;

bool maxFirst(string a, string b){
    string t = a+b;
    string f = b+a;
    std::stringstream geek1(t);
    std::stringstream geek2(f);
    int xt = 0;
    geek1 >> xt;
    int xf = 0;
    geek2 >> xf;
    if (xt>xf) return true;
    return false;
}

string largest_number(vector<string> a) {
    std::stringstream ret;
    string maxDig;
    int x, s;
    s = 0;
    
    while (s<a.size()) {
        maxDig = "0";
        for (int i = s; i < a.size(); i++) {
//            std::cout<<a[i]<<" - - - \n";
            if (maxFirst(a[i], maxDig)) {
                maxDig = a[i];
                x = i;
            }
        }
        ret << maxDig;
        a.erase(a.begin()+x);
    }
    
    string result;
    ret >> result;
    return result;
}

string print_input(vector<string> a) {
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
