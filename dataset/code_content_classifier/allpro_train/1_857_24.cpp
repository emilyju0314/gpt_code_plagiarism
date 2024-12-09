#include <iostream>
#include <cstdio>
using namespace std;
int n,m,r,c,si,an;
bool a[30][30],b[30][30]; 

void check() {

  cout << endl;
  cout << " --------------------------"<< endl;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {

      cout <<a[i][j];
      if(j != n-1) cout <<" ";
    }
    cout << endl;
  }
  cout << "--------------------------"<< endl;
  cout<< endl;

}

void rotate() {
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      b[i][j] = a[i][j];
  
  
  for(int rt=0;rt<an/90;rt++) {
    
    for(int i=0;i<si;i++){
      for(int j=0;j<si;j++) {
	//printf("a[%d][%d](%d) = b[%d][%d](%d)\n",r+i,c+j,a[r+i][c+j],c+si-j-1,i+r,b[r+si-j-1][i+r]);
	a[r+i][c+j] = b[r+si-j-1][i+c];
      }
    }
    
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++) 
	b[i][j] = a[i][j];
    // check();   
  } 

} 


/*void rotate(){
  for(int k=0;k<an/90;k++){
    for(int i=0;i<si;i++)
      for(int j=0;j<si;j++)
	b[i][j] = a[r+i][c+j];
     
    for(int i=0;i<si;i++)
      for(int j=0;j<si;j++)
    a[i+r][j+c] = b[si-j-1][i];
  }
  }*/


void reversal() {

  for(int i=r;i<r+si;i++) {
    for(int j=c;j<c+si;j++) {
      a[i][j] = !a[i][j];
    }
  }

}

void IR(int x, int y) {
  int dx[4] = {0,0,1,-1};
  int dy[4] = {-1,1,0,0};
 
  a[y][x] = !a[y][x];
 
  for(int i=0;i<4;i++) {
    if(y+dy[i] >= 0 && y+dy[i] <n && x+dx[i] >=0 && x+dx[i] < n) 
      if(a[y+dy[i]][x+dx[i]] != a[y][x])
	IR(x+dx[i],y+dy[i]);  
  }
}


void RS() {

  a[r][0] = b[r][n-1];
  for(int i=1;i<n;i++) a[r][i] = b[r][i-1];
  for(int i=0;i<n;i++) b[r][i] = a[r][i];


}

void LS() {
  a[r][n-1] = b[r][0];
  for(int i=n-2;i>=0;i--) a[r][i] = b[r][i+1];
  for(int i=0;i<n;i++) b[r][i] = a[r][i];

}

int main(){

  cin >> n >> m;

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      b[i][j] = a[i][j];
    }
  }


  int o;

  for(int k=0;k<m;k++) {
    cin >> o;

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
	b[i][j] = a[i][j];

    if(o == 0){
      cin >> r >> c >> si >> an;
      r--;
      c--;
      rotate();
    }
    else if(o == 1) {
      cin >> r >> c >> si;
      r--;
      c--;
      reversal();
    } 
    else if(o == 2) {
      cin >> r;
      r--;
      LS();
    }
    else if(o==3) {
      cin >> r;
      r--;
      RS();
    }
    else if(o == 4) {
      cin >> r >> c ;
      r--;
      c--;
      IR(c,r);

    }

  }


  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {

      cout <<a[i][j];
      if(j != n-1) cout <<" ";
    }
    cout << endl;
  }

  return 0;

}