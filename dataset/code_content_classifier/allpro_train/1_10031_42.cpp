#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
int N;
int ans[101][101];
int main(){
	cin>>N;
	if(N==2){
	   cout<<-1<<endl;
	   return 0;
	}
	if(N%2==1){
	   REP(i,N-1){
	       REP(j,N){
	           ans[i][j]=(1+i+j)%N+1;
	           //cout<<(1+i+j)%N+1;
	           /*if(j==N-1){
	              cout<<endl;
	           }else{
	              cout<<" ";
	           }*/
	       }
	   }
	}else{
	  int now=0;
	  REP(i,N-3){
	      if(N/2-1==i)now++;
	      REP(j,N){
	          ans[i][j]=(1+now+j)%N+1;
	          /*cout<<(1+now+j)%N+1;
	          if(j==N-1){
	              cout<<endl;
	           }else{
	              cout<<" ";
	           }*/
	      }
	      now++;
          }
          REP(i,N){
             if(i<N/2){
                ans[N-3][i]=(i+N-1)%N+1;
                //cout<<(i+N-1)%N+1;
             }else{
                ans[N-3][i]=i-N/2+1;
                //cout<<i-N/2+1;
             }
             /*
             if(i==N-1){
	              cout<<endl;
	           }else{
	              cout<<" ";
	     }*/
          }
          
          REP(i,N){
             if(i>=N/2){
                ans[N-2][i]=(i+N-1)%N+1;
                //cout<<(i+N-1)%N+1;
             }else{
                ans[N-2][i]=i+N/2+1;
                //cout<<i+N/2+1;
             }
             /*
             if(i==N-1){
	              cout<<endl;
	           }else{
	              cout<<" ";
	     }*/
          }
	}
	REP(i,N){
	    REP(j,N-1){
	        cout<<ans[j][i];
	        if(j==N-2){
	              cout<<endl;
	           }else{
	              cout<<" ";
	        }
	    }
	}
        cout<<endl;
	return(0);
}