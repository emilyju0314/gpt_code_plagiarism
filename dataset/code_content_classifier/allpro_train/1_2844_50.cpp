#include<bits/stdc++.h>
using namespace std;

double calc(double ra, double rb, double xb){
  double h = abs(ra-rb);
  double z = ra+rb;
  double dif = sqrt(z*z-h*h);

  return dif+xb;
}

int main(){
  int n;
  cin >> n;
  vector<double> r(n);
  for(int i=0;i<n;i++)cin >> r[i];

  vector<double> x(n);
  x[0] = r[0];
  for(int i=0;i<n;i++){
    double tx = 0;
    for(int j=0;j<i;j++){
      tx = max(tx, calc(r[i], r[j], x[j]));
    }
    x[i] = tx;
  }

  double left = 0, right = 0;
  for(int i=0;i<n;i++){
    left = min(left, x[i]-r[i]);
    right = max(right, x[i]+r[i]);
  }

  cout << fixed << setprecision(10) << right-left << endl;
}