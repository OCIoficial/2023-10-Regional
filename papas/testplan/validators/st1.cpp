#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int p = inf.readInt(2, 2, "p");
  inf.readSpace();
  int n = inf.readInt(2, p, "n");
  inf.readSpace();
  int k = inf.readInt(1, 2, "k");
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
