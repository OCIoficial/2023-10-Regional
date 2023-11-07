#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(1, 1000000, "n");
  inf.readSpace();
  int k = inf.readInt(0, 100, "k");
  inf.readEoln();

  for (int i = 1; i <= n; i++) {
    int a = inf.readInt(0, 1000000000, "a_{" + to_string(i) + "}");
    if (i != n) {
      inf.readSpace();
    }
  }
  inf.readEoln();

  for (int i = 1; i <= n; i++) {
    int b = inf.readInt(0, 1000000000, "b_{" + to_string(i) + "}");
    if (i != n) {
      inf.readSpace();
    }
  }
  inf.readEoln();

  inf.readEof();
}
