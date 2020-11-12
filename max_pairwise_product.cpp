#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();
    int max1 = -1; 
    int max2 = -1;

    for (int i = 0; i < n; ++i) {
        if((numbers[i]>numbers[max1]) || (max1 == -1)){ 
            if (numbers[max1]>numbers[max2]) {max2=max1;}
            max1 = i;
        }
        else if (((numbers[i]>numbers[max2]) || (max2 == -1))&& (i!=max1)) {max2 = i;}
    }
    return (((long long)(numbers[max1])) * numbers[max2]);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
