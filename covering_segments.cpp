#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    int currPoint;
    size_t i = 0;
    
  while(0 < segments.size()) {
//    points.push_back(segments[i].start);
//    points.push_back(segments[i].end);
      
      currPoint = segments[0].end;
//      std::cout<<segments[0].end<<" - - - \n";
      for (size_t j = 0; j < segments.size(); ++j){
          if (segments[j].start <= currPoint){
//              std::cout<<segments[j].start<<"\n";
              segments.erase(segments.begin()+j);
              j--;
          }
      }
      points.push_back(currPoint);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  sort(segments.begin(), segments.end(), [](const Segment& s1, const Segment& s2) {
      return s1.end < s2.end;
  });
    
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
