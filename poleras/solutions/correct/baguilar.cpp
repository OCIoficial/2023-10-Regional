#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    std::vector<int> poleras_inital(n);
    std::vector<int> poleras_target(n);
    for (int i = 0; i < n; i++) {
        cin >> poleras_inital[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> poleras_target[i];
    }

    int j = n - 1;    
    for (int i = n - 1; i >= 0; i--) {
        while (j > i + k) {
            j--;
        }
        while (poleras_target[i] > 0 && j >= i) {
            int delta = std::min(poleras_target.at(i), poleras_inital.at(j));
            poleras_target[i] -= delta;
            poleras_inital[j] -= delta;
            if (poleras_inital[j] == 0) {
                j--;
            }
        }
        if (poleras_target.at(i) > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "SI" << endl;
    return 0;
}