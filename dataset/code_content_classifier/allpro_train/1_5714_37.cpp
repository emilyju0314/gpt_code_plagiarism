 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
string parse[6];
int N;
int C[6];
int A[6];
//x?????¢???
int find(string s,char c){
   REP(i,s.size()){
       if(s[i]==c){
          return i;
       }
   }
   return -1;
}
//x??????????????°???????????????
int getC(string s){
    int num=find(s,'x');
    if(num==-1){
       return stoi(s);
    }else{
       if(num==0){
          return 1;
       }else if(num==1&&s[0]=='-'){
          return -1;
       }
       return stoi(s.substr(0,num));
    }
}
//x?????????????????????
int getA(string s){
    int a=find(s,'^');
    if(a==-1){
       int b=find(s,'x');
       if(b==-1){
          return 0;
       }else{
          return 1;
       }
    }else{
       return stoi(s.substr(a+1,s.size()));
    }
}

//+???????§£??????
int split(string s){
    int count=0;
    string a="";
    REP(i,s.size()){
       if(s[i]=='+'||s[i]=='-'){

          parse[count]=a;
          a="";
          if(s[i]=='-'){
             a="-"+a;
          }
          count++;
          continue;
       }
       a.push_back(s[i]);
    }
    parse[count]=a;
    count++;
    return count;
}
bool check(int x){
   int ans=0;
   REP(i,N){
       int sum=1;
       REP(j,A[i]){
           sum*=x;
       }
       sum*=C[i];
       ans+=sum;
   }
   //cout<<"x="<<x<<" ans"<<ans<<endl;
   return ans==0;
}

string solve(){
   string s="";
   for(int i=2000;i>=-2000;i--){
       if(check(i)){
          if(i<0){
             s=s+"(x+"+to_string(abs(i))+")";
          }else if(i==0){
             s=s+"x";
          }else{
             s=s+"(x-"+to_string(i)+")";
          }
       }
   }
   return s;
}

int main(){
    string s;
    cin>>s;
    N=split(s);
    REP(i,N){
        //cout<<parse[i]<<endl;
        C[i]=getC(parse[i]);
        A[i]=getA(parse[i]);
        //cout<<C[i]<<" "<<A[i]<<endl;
    }
    cout<<solve()<<endl;
    return 0;
}