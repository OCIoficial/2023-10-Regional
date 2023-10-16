#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(1, 10000, "n");
  inf.readEoln();
  // Map of <seeds: peers: count>
  map<int, map<int, int>> torrents;
  int max_seeds = -1;
  int min_peers = 100000;
  for (int i = 1; i <= n; i++) {
    int s = inf.readInt(0, 10000, "s_{" + to_string(i) + "}");
    inf.readSpace();
    int p = inf.readInt(1, 10000, "p_{" + to_string(i) + "}");
    inf.readEoln();
    if (torrents.count(s) == 0) {
      torrents[s] = {};
    }
    if (torrents[s].count(p) == 0) {
      torrents[s][p] = 0;
    }
    torrents[s][p]++;

    // Solve:
    if (s > max_seeds) {
        max_seeds = s;
        min_peers = p;
    } else if (s == max_seeds) {
        if (p < min_peers) {
            max_seeds = s;
            min_peers = p;
        }
    }
  }
  if (torrents[max_seeds][min_peers] != 1) {
    quitf(_wa, "Expected only one best answer, found %d", torrents[max_seeds][min_peers]);
  }

  inf.readEof();
}
