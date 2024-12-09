#include<bits/stdc++.h>
using namespace std;
typedef double D;

vector<int> hand(int n){
  vector<int> h(n+1,0);

  int m; cin >> m;
  for(int i=0;i<m;i++){
    int a; cin >> a; h[a]++;
  }
  
  for(int i=0;i<=n;i++) h[i] %= 2;

  return h;
}

D memo2[3][3][110]; //memo2[turn][joker][card]

//0: kotori, 1: umi
D rec2(int t, int j, int c){
  D &res = memo2[t][j][c];
  if(res >= 0) return res;
  
  if(c == 0){
    if(j == 1) return res = 0; //umi loses
    else return res = 1;       //umi wins
  }

  if(t == 0){ //kotori turn
    return res = rec2(1-t,j,c-1);
  }else{     //umi turn
    int total = c + (j==0);
    res = c * rec2(1-t,j,c-1);
    if(j==0) res += rec2(1-t,1,c);
    res /= total;

    return res;
  }
}

D memo3[3][3][110][110][110]; //memo3[turn][joker][hono][umi][koto]

//honoka: 0, umi: 1, kotori: 2
D rec3(int t, int j, vector<int> p){
  D &res = memo3[t][j][p[0]][p[1]][p[2]];
  if(res >= 0) return res;

  //only joker
  if(p[0]==0 && p[1]==0 && p[2]==0){
    if(j == 1) return res = 0; //umi loses
    else return res = 1;       //umi wins
  }

  int nt = (t+1)%3;
  //turn player has no card
  if(j!=t && p[(t+1)%3]==0 && p[(t+2)%3]==0){
    return res = rec3(nt, j, p); //skip turn
  }

  //two players remain
  for(int i=0;i<3;i++){
    if(j!=i && p[(i+1)%3]==0 && p[(i+2)%3]==0){
      if(i==1) return res = 1;                //umi wins
      else return res = rec2(t==1,j==1,p[i]); //umi remains
    }
  }

  //three players remain
  if(t==2){
    if(p[0]){ //umi has cards that kotori also has
      res = rec3(nt, j, {p[0]-1,p[1],p[2]});
    }else if(p[0]==0 && p[2]==0 && j==1){ //umi only has joker
      res = 1;
    }else{
      res = rec3(nt, j, {p[0],p[1]+1,p[2]-1});
    }
  }else{
    int total = p[t] + p[(t+1)%3] + (j==(t+2)%3);

    vector<int> np = p;
    np[t]--;
    np[(t+2)%3]++;
    res = p[t] * rec3(nt,j,np);
    
    np = p;
    np[(t+1)%3]--;
    res += p[(t+1)%3] * rec3(nt,j,np);

    if(j==(t+2)%3) res += rec3(nt,t,p);

    res /= total;
  }
  
  return res;
}

int main(){
  int n;
  cin >> n;

  vector<int> hono = hand(n), umi = hand(n), koto = hand(n);

  int joker = 0;
  if(hono[0] == 1) joker = 0;
  if( umi[0] == 1) joker = 1;
  if(koto[0] == 1) joker = 2;

  int h=0, u=0, k=0;
  for(int i=1;i<=n;i++){
    if(umi[i]  && koto[i]) h++;
    if(koto[i] && hono[i]) u++;
    if(hono[i] &&  umi[i]) k++;
  }

  for(int a=0;a<3;a++){
    for(int b=0;b<3;b++){
      for(int c=0;c<=n;c++){
	memo2[a][b][c] = -1;

	for(int d=0;d<=n;d++){
	  for(int e=0;e<=n;e++) memo3[a][b][c][d][e] = -1;
	}
      }
    }
  }

  cout << fixed << setprecision(10) << rec3(0, joker, {h,u,k}) << endl;
}