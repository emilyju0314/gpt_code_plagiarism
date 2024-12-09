#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define INF (1<<29)
using namespace std;
typedef long long ll;
int main(){
      string s;
      int f1[26],f2[10];
      for(int i=0;i<26;i++)f1[i]=0;
      for(int i=0;i<10;i++)f2[i]=0;
      cin>>s;
      for(int i=0;i<s.size();i++){
            if('a'<=s[i]&&s[i]<='z')f1[s[i]-'a']++;
            else f2[s[i]-'0']++;
      }
      bool update=true;
      int ans=0;
      while(update){
            update=false;
            for(int i=0;i<26;i++){
                  if(f1[i]>0){
                        int b=i;
                        while(f1[i]>0)i++;
                        if(i-b>3){
                              //cout<<i<<endl;
                              ans+=3;
                              for(int j=b;j<i;j++){
                                    f1[j]--;
                              }
                              update=true;
                        }
                  }
            }
            for(int i=0;i<10;i++){
                  if(f2[i]>0){
                        int b=i;
                        while(f2[i]>0)i++;
                        if(i-b>3){
                              ans+=3;
                              for(int j=b;j<i;j++){
                                    f2[j]--;
                              }
                              update=true;
                        }
                  }
            }
      }
      for(int i=0;i<26;i++)ans+=f1[i];
      for(int i=0;i<10;i++)ans+=f2[i];
      cout<<ans<<endl;
}