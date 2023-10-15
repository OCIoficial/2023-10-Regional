#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int p = inf.readInt(1, 250, "p");
  inf.readSpace();
  int n = inf.readInt(max(p, 2), 250, "n");
  inf.readSpace();
  int k = inf.readInt(1, p, "k");
  inf.readEoln();

  for (int i = 1; i <= p; i++) {
    int r = inf.readInt(1, 1000, "t_{" + to_string(i) + "}");
    if (i != p) {
      inf.readSpace();
    }
  }
  inf.readEoln();

  inf.readEof();
}
