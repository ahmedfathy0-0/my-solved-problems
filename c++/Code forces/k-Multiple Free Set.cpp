#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    std::set<int> k_multiple_free_set;
    
    for (int i = 0; i < n; ++i) {
        if (k_multiple_free_set.find(a[i] / k) == k_multiple_free_set.end() || a[i] % k != 0) {
            k_multiple_free_set.insert(a[i]);
        }
    }
    
    std::cout << k_multiple_free_set.size() << std::endl;
    
    return 0;
}
