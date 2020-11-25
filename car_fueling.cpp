#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops, int n) {
    int refill = 0;
    int currStop = 0;
    int lastStop;
    
    if (stops[currStop]+tank >= dist) return refill;
//    for (int i=0; i<=n+1; i++){
//        cout<<stops[i]<<" "<<"\n";
//    }
    
    while(currStop <= n){
        lastStop = currStop;
        while((currStop<=n) && ((stops[currStop+1]-stops[lastStop])<=tank)){
            currStop++;
        }
        if (currStop == lastStop) return -1;
        if (currStop <= n) refill++;
//        if (stops[currStop]+tank >= dist) return refill++;
//        cout<< currStop<< " - - - "<< stops[currStop]<< " - - - "<< refill<<"\n";
    }
    return refill;
}


int main() {
    int d = 0; // distance till destination
    cin >> d;
    int m = 0; // distance car can travel after refill
    cin >> m;
    int n = 0; // number of refill stops
    cin >> n;

    vector<int> stops(n+2);
    stops.at(0)=0;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
    stops.at(n+1)=d;
    cout << compute_min_refills(d, m, stops, n) << "\n";

    return 0;
}
