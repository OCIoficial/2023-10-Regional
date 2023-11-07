#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(1, 1000, "n");
  inf.readSpace();
  int q = inf.readInt(1, 1000, "q");
  inf.readSpace();
  int kmin = inf.readInt(0, 1000000000, "k_{min}");
  inf.readSpace();
  int kmax = inf.readInt(kmin, 1000000000, "k_{max}");
  inf.readEoln();

  for (int i = 1; i <= n; i++) {
    int r = inf.readInt(1, 10000, "r_{" + to_string(i) + "}");
    if (i != n) {
      inf.readSpace();
    }
  }
  inf.readEoln();

  for (int j = 1; j <= q; j++) {
    int x = inf.readInt(0, 100000, "x_{" + to_string(j) + "}");
    inf.readEoln();
  }

  inf.readEof();
}
