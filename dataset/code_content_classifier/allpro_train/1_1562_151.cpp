#include<iostream>
#include<cstdio>
using namespace std;

class Cube {
public:
  int face[6];
  Cube() {}
  void roll_z(){ roll(1, 2, 4, 3);}
  void roll_y(){ roll(0, 2, 5, 3);}
  void roll_x(){ roll(0, 1, 5, 4);}    
  
  void roll(int i, int j, int k, int l) {
    int t = face[i];
    face[i] = face[j];
    face[j] = face[k];
    face[k] = face[l];
    face[l] = t;
  }
  
};

bool eq(Cube c1, Cube c2) {
  for (int i = 0; i < 6; i++) {
    if (c1.face[i] != c2.face[i]) return false;
  }
  return true;

}

bool equal(Cube c1, Cube c2) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      if(eq(c1,c2)) return true;
      c1.roll_z();
    }
    if(i % 2 == 0) c1.roll_y();
    else c1.roll_x();
  }
  return false;

}

int main() {
  int n = 0;
  cin >> n;
  
  Cube c[1000];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) cin >> c[i].face[j];
  }

  int flag = 1;

  for (int i = 0; i < n-1; i++) {
    for (int j = i+1 ; j < n; j++) {
      if (equal(c[i],c[j])) flag = 0;
    }
  }
  
  if (flag == 1) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
