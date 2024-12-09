#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

int sign(double x){
  return (x>0)-(x<0);
}

int deg(char *xy, int d){

  if(xy[0] == 'B') return 120 - d; //BC 
  if(xy[0] == 'C') return 60  - d; //CD
  if(xy[0] == 'D') return 180 - d; //DB 

  return 0;
}

int getID(int deg, int l){
  double eps = 1e-7;
  double s = sqrt(3)/2;
  
  double a = cos((deg-30) / 180.0 * M_PI) * l;
  double b = cos((deg-90) / 180.0 * M_PI) * l;
  double c = cos((deg-150)/ 180.0 * M_PI) * l;

  int A = floor(a / s + eps * sign(a));
  int B = floor(b / s + eps * sign(b));
  int C = floor(c / s + eps * sign(c));

  //debug(A);
  //debug(B);
  //debug(C);
  
  if((A + B) % 2 == 0){
    if((A + C) % 2 == 0){
      return 1;
    }else{
      return 3;
    }
  }else{
    if((A + C) %2 == 0){
      return 4;
    }else{
      return 2;
    }
  }
  
}

int main(){
  char xy[2][3];
  int d[2], l[2];

  for(int i=0;i<2;i++){
    scanf("%s%d%d",xy[i], d+i, l+i);
    d[i] = deg(xy[i], d[i]);
  }
  
  if(getID(d[0],l[0]) == getID(d[1],l[1])){
    puts("YES");
  }else{
    puts("NO");
  }
  
  return 0;
}

