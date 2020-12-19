#include <iostream>
#include <vector>
using namespace std;

// Find the minimum number of coins
// with denominations 1, 3, 4 that changes money

int get_change(int m) {
    if (m == 0) return m;
    
    int numCoins = 0;
    vector<int> coins(m+1);
    vector<int> changes = {1, 3, 4};
    
    for(int i=0; i<=m; i++){
        coins[i] = i;
        for(int j : changes){
            if (i >= j){
                numCoins = coins[i - j] + 1;
//                cout<<"i: "<<i<<" j: "<<j<<" numCoins: "<<numCoins<<endl;
                if (numCoins < coins[i])
                    coins[i] = numCoins;
            }
        }
    }
    return coins[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
