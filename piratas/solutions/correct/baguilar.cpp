#include<iostream>
using namespace std;
int main() {
    int n;
    int max_seeds = -1;
    int min_peers = 100000;
    int result;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int seeds;
        int peers;
        cin >> seeds >> peers;
        if (seeds > max_seeds) {
            result = i;
            max_seeds = seeds;
            min_peers = peers;
        } else if (seeds == max_seeds) {
            if (peers < min_peers) {
                result = i;
                max_seeds = seeds;
                min_peers = peers;
            }
        }
    }
    cout << result + 1 << endl;
    return 0;
}
