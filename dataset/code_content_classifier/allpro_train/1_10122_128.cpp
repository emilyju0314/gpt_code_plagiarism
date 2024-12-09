#include <cstdio>

using namespace std;
int n,d[102][4];
bool ch[102];

int gcd(int a,int b){
  if(b == 0) return a;
  return gcd(b,a % b);
}


int dfs(int x){
  int p = d[x][0];
  int q = d[x][1];
  int w = gcd(p,q);
  
  p /= w;
  q /= w;
  
  if(d[x][2] == 0 && d[x][3] == 0){
    return (p+q);
  }
  
  int red=1,blue=1;
  
  if(d[x][2] != 0) red = dfs(d[x][2]);
  if(d[x][3] != 0) blue = dfs(d[x][3]);
  
  int k = p * red;
  int h = q * blue;
  int i = 0;
  int j = 0;
  while(1){
    i++;
    if(k * i % h == 0){
      j = k * i / h;
      break;
    }
  }
  
  return (i*red+j*blue);
}
  

int main(){
  
while(1){
  
  scanf("%d",&n);
  if(n == 0)break;
  
  for(int i = 1;i <= n;i++){
    ch[i] = false;
  }
  
  for(int i = 1;i <= n;i++){
    for(int j = 0;j < 4;j++){
      scanf("%d",&d[i][j]);
      if(j == 2 || j == 3){
	ch[d[i][j]] = true;
      }
    }
  }
  int ans;
  for(int i = 1;i <= n;i++){
    if(ch[i] == false){
      ans = i;
    }
  }
  
  printf("%d\n",dfs(ans));
  
}
  
  return 0;
  
}
  
  
 
