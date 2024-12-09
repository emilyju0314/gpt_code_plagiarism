#include<iostream>
#include<vector>
#define MAX int(7.5*1e6)
using namespace std;

int main(){
  int n, m;
  while(1) {
    scanf("%d %d\n", &m, &n);
    if(n == 0)break;
    vector<bool> isBoring(MAX, false);
    for (;n != 0; n--) {
      while(isBoring[m]) m++;
      for (int j = m; j < MAX; j+=m) isBoring[j] = true;
    }
    while(isBoring[++m]);
    std::cout << m << std::endl;
  }
  return 0;
}