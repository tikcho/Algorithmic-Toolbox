#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

vector<int> fast_count_segments(vector<std::pair<int,char>> v, vector<int> points) {
    int n = v.size(), m = points.size();
    std::map<int, int> c;
    vector<int> cnt(m);
    
    int count = 0;
    
    for(int i=0; i<n; i++){  // example: { (2,l),(3,p),(4,l),(5,p),(6,r),(8,p),(10,r) }
        if (v[i].second == '0'){ //starting
            count++;
        }
        else if (v[i].second == '2'){ //ending
            count--;
        }
        else if (v[i].second == '1'){ //point
            c[v[i].first] = count;
        }
    }
    
    for (int i=0; i<m; i++){
        cnt[i] = c[points[i]];
    }
    
    return cnt;
}

vector<int> better_count_segments(std::vector<std::pair<int,int>> v, vector<int> points) {
    vector<int> cnt(points.size());
    int n = v.size(), m = points.size();
    int count;

    for(int i=0; i<m; i++){  //points
        count = 0;
        for(int j=0; j<n; j++){  //v pairs(start, end)
            if (points[i]>=v[j].first && points[i]<=v[j].second)
                count += 1;
            else if(points[i]<v[j].first)
                break;
        }
        cnt[i] = count;
    }

    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  std::vector<std::pair<int,char>> v;
    
  for (size_t i = 0; i < n; i++) {
    std::cin >> starts[i] >> ends[i];
//    v.push_back(std::make_pair(starts[i],ends[i])); // for better_count_segments
    v.push_back(std::make_pair(starts[i],'0'));
    v.push_back(std::make_pair(ends[i], '2'));
  }
//  sort(v.begin(),v.end()); // for better_count_segments
    
  vector<int> points(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> points[i];
    v.push_back(std::make_pair(points[i], '1'));
  }
  
  sort(v.begin(),v.end());
//    for(int i=0; i<v.size(); i++){
//        std::cout<<v[i].first<<" "<<v[i].second<<" ; ";
//    }
  vector<int> cnt = fast_count_segments(v, points);
//   vector<int> cnt = better_count_segments(v, points);  // for better_count_segments
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
