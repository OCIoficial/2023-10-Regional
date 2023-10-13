#include<bits/stdc++.h>

using namespace std;

struct Torrent {
  int s, p, index;
  Torrent(int s, int p, int index) : s(s), p(p), index(index) {}

  bool operator<(const Torrent& t) const {

    if(s == t.s)
    {
      if (p == t.p) // Cualquier indice debe ser valido
        return random() % 2 == 0;
      
      return p < t.p;
    }

    return s > t.s;
  }
};


int main() {

  int n;
  cin >> n;

  Torrent torrent(-1, 100000000, -1);

  for(int i = 0; i < n; i++)
  {
    int s, p;
    cin >> s >> p;

    Torrent t(s, p, i);

    if(t < torrent)
      torrent = t;
  }

  cout << torrent.index << endl;
}
