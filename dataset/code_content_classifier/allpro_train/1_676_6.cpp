#include<iostream>

using namespace std;

int solve(const string& s1, const string& s2, int sp1, int sp2){

  int tmp = 0;
  int res = 0;
  int len = min(s2.length()-sp2,s1.length()-sp1);
  
  
  for(int i = 0; i < len; i++){
    if(s1[sp1+i] != s2[sp2+i]){
      res = max(res,tmp);
      tmp = 0;
    }else{
      tmp++;
    }
  }
  return max(tmp,res);
}

int main(){
  
  string s1,s2;
  while(getline(cin,s1) && getline(cin,s2)){
    int p1 = s1.length();
    int p2 = 0;
    int ans = 0;

    while(p1!=0||p2<=(int)s2.length()){
      if(p1 != 0) p1--;
      else p2++;
      ans = max(ans,solve(s1,s2,p1,p2));
     }
    cout << ans << endl;
  }
  return 0;
}