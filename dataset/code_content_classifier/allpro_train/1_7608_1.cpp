#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct P {
  int x, y, z;
  P() : x(0), y(0), z(0) {}
  P(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator < (const P &p) const {
    if(x != p.x) return x < p.x;
    if(y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator == (const P &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  P operator + (const P &p) const {
    return P(x+p.x, y+p.y, z+p.z);
  }
  P& operator += (const P &p) {
    return ( *this = *this + p );
  }
  P operator - (const P &p) const {
    return P(x-p.x, y-p.y, z-p.z);
  }
  P& operator -= (const P &p) {
    return ( *this = *this - p );
  }
};

typedef pair<P,P> Seg;
typedef vector<Seg> Key;

const int INF = 1<<28;

void rotate(int &x, int &y) {
  int t = x;
  x = -y;
  y = t;
}

Key rotate(Key k, int dir) {
  int n = k.size();
  for(int i = 0; i < n; ++i) {
    pair<int,int> p;
    if(dir == 0) {
      rotate(k[i].first.x, k[i].first.y);
      rotate(k[i].second.x, k[i].second.y);
    } else if(dir == 1) {
      rotate(k[i].first.y, k[i].first.z);
      rotate(k[i].second.y, k[i].second.z);
    } else if(dir == 2) {
      rotate(k[i].first.z, k[i].first.x);
      rotate(k[i].second.z, k[i].second.x);
    }
  }
  return k;
}

Key normalize(Key k) {
  int n = k.size();
  for(int i = 0; i < n; ++i) {
    if(k[i].second < k[i].first) swap(k[i].first, k[i].second);
  }
  P mini(INF,INF,INF);
  for(int i = 0; i < n; ++i) {
    mini.x = min(mini.x, min(k[i].first.x, k[i].second.x));
    mini.y = min(mini.y, min(k[i].first.y, k[i].second.y));
    mini.z = min(mini.z, min(k[i].first.z, k[i].second.z));
  }
  for(int i = 0; i < n; ++i) {
    k[i].first -= mini;
    k[i].second -= mini;
  }
  sort(k.begin(), k.end());
  return k;
}

Key getKey() {
  int q;
  cin >> q;
  if(!q) return Key();
  Key k;
  P p(0,0,0);
  P label[100];
  fill(label, label+100, P(INF,INF,INF));
  while(q--) {
    string s;
    cin >> s;
    P pre = p;
    if(0) {
    } else if(s == "+x") {
      ++p.x;
    } else if(s == "-x") {
      --p.x;
    } else if(s == "+y") {
      ++p.y;
    } else if(s == "-y") {
      --p.y;
    } else if(s == "+z") {
      ++p.z;
    } else if(s == "-z") {
      --p.z;
    } else {
      int id = atoi(s.c_str());
      if(label[id].x == INF) {
        label[id] = p;
      } else {
        p = label[id];
      }
      pre.x = INF;
    }
    if(pre.x != INF) {
      k.push_back(Seg(pre,p));
    }
  }
  return k;
}

bool equals(Key a, Key b) {
  a = normalize(a);
  for(int i = 0; i < 6; ++i) {
    for(int j = 0; j < 4; ++j) {
      b = normalize(b);
      if(a == b) return true;
      b = rotate(b, 0);
    }
    if(i < 3) {
      b = rotate(b, 1);
    } else if(i == 3) {
      b = rotate(b, 2);
    } else if(i == 4) {
      b = rotate(b, 2);
      b = rotate(b, 2);
    }
  }
  return false;
}

int main() {
  while(1) {
    Key a = getKey();
    if(!a.size()) break;
    Key b = getKey();
    /*
    cout << "A" << endl;
    for(int i = 0; i < a.size(); ++i) {
      cout << "(" << a[i].first.x << "," << a[i].first.y << "," << a[i].first.z << "),";
      cout << "(" << a[i].second.x << "," << a[i].second.y << "," << a[i].second.z << ")" << endl;
    }
    cout << "B" << endl;
    for(int i = 0; i < b.size(); ++i) {
      cout << "(" << b[i].first.x << "," << b[i].first.y << "," << b[i].first.z << "),";
      cout << "(" << b[i].second.x << "," << b[i].second.y << "," << b[i].second.z << ")" << endl;
    }
    */
    if(equals(a,b)) cout << "SAME" << endl;
    else cout << "DIFFERENT" << endl;
  }
  return 0;
}