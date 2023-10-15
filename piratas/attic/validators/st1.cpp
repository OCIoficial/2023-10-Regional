#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(1, 10000, "n");
  inf.readEoln();

  for (int i = 1; i <= n; i++) {
    int s = inf.readInt(1, 10000, "s_{" + to_string(i) + "}");
    inf.readSpace();
    int p = inf.readInt(1, 10000, "p_{" + to_string(i) + "}");
    inf.readEoln();
  }

  inf.readEof();
}
