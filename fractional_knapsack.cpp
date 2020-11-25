#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, int n, vector<std::pair<double,int> > sorted_vals) {
    double value = 0.0;
    double v = 0.0;
    int s = n;
    
    sort(sorted_vals.begin(),sorted_vals.end());
    while (capacity>0 & s>0){
        s = s - 1;
        v = std::min(sorted_vals[s].second, capacity);
        
        value = value + sorted_vals[s].first*v;
        capacity = capacity - v;
    }

    return (double)value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  vector<std::pair<double,int> > sorted_vals;
    
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    sorted_vals.push_back(std::make_pair(values[i]/(double)weights[i],weights[i]));
  }
      
  double optimal_value = get_optimal_value(capacity, n, sorted_vals);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
