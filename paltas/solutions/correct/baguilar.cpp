#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search(const std::vector<int> &rates, int time, int target) {
    int search_min = 0, search_max = rates.size() - 1;
    int current = -1;
    while (current != (search_max + search_min) / 2) {
        current = (search_max + search_min) / 2;
        if (rates.at(current) * time < target) {
            // Under, move search_min
            search_min = current + 1;
        } else {
            // Over, move search_max
            search_max = current;
        }
    }
    if (current == rates.size() - 1 && rates.back() * time <= target) {
        // Ugly but ¯\_(ツ)_/¯
        current++;
    }
    return current;
}

int main() {
    int n, q, k_min, k_max;
    cin >> n >> q >> k_min >> k_max;
    vector<int> rate(n );
    for (size_t i = 0; i < n; i++) {
        cin >> rate[i];
    }
    sort(rate.begin(), rate.end());
    for (size_t i = 0; i < q; i++) {
        int time;
        cin >> time;
        int min_idx = binary_search(rate, time, k_min);
        int max_idx = binary_search(rate, time, k_max + 1);
        cout << max_idx - min_idx << endl;
    }
    return 0;
}