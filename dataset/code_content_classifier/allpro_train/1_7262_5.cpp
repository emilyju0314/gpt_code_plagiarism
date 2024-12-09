#include <bits/stdc++.h>
using namespace std;

struct P{
  double x, y, z;
  P():x(0), y(0), z(0){}
  P(double x, double y, double z):x(x), y(y), z(z){}
  P operator+(const P& b)const{
    P res;
    res.x = x + b.x;
    res.y = y + b.y;
    res.z = z + b.z;
    return res;
  }
  P operator-(const P& b)const{
    P res;
    res.x = x - b.x;
    res.y = y - b.y;
    res.z = z - b.z;
    return res;
  }
  bool operator<(const P& b)const{
    if(x == b.x)
      if(y == b.y)
        return z < b.z;
      else
        return y < b.y;
    else
      return x < b.x;
  }
};

bool eq(double a, double b){
  return abs(a-b) < 0.01;
}

// Experimence
int main(void){
  int T; cin >> T;
  while(T--){
    double QR, RP, PQ; cin >> QR >> RP >> PQ;
    int N; cin >> N;
    vector<P> points(N);
    for(int i = 0; i < N; i++){
      cin >> points[i].x >> points[i].y >> points[i].z;
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        for(int k = 0; k < N; k++){
          if(i == j || j == k || i == k) continue;
          vector<P> triangle(3);
          triangle[0] = points[i];
          triangle[1] = points[j];
          triangle[2] = points[k];

          vector<double> edge(3);
          for(int edge_idx = 0; edge_idx < 3; edge_idx++){
            P subtract = triangle[edge_idx%3] - triangle[(edge_idx+1)%3];
            edge[edge_idx] = sqrt(subtract.x*subtract.x + subtract.y*subtract.y + subtract.z*subtract.z);
          }
          if( eq(edge[0]/QR, edge[1]/RP) && eq(edge[0]/QR, edge[2]/PQ) ){
            cout << k+1 << " " << i+1 << " " << j+1 << endl;
            i = N; j = N; k = N;
          }
        }
      }
    }
  }
}