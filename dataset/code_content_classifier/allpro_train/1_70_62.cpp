                                        #include <bits/stdc++.h>
                                        #include<iostream>
                                        #include<cstdio>
                                        #include<vector>
                                        #include<queue>
                                        #include<map>
                                        #include<cstring>
                                        #include<string>
                                        #include <math.h>
                                        #include<algorithm>
                                    //    #include <boost/multiprecision/cpp_int.hpp>
                                        #include<functional>
                                #define int long long
                                        #define inf  1000000007
                                        #define pa pair<int,int>
                                        #define ll long long
                                        #define pal pair<double,pa>
                                        #define ppa pair<int,int>
                                        #define ppap pair<int,pa>
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-10)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
                                  #define VI vector<int>
                                        using namespace std;
                                        
                                  class pas{
                                    	public:
                                    	int x,y;
                                    	pas(int x=0,int y=0):x(x),y(y) {}
                                    	pas operator + (pas p) {return pas(x+p.x,y+p.y);}
                                    	pas operator - (pas p) {return pas(x-p.x,y-p.y);}
                                    	pas operator * (int a) {return pas(x*a,y*a);}
                                    	pas operator / (int a) {return pas(x/a,y/a);}
                                    //	double absv() {return sqrt(norm());}
                                    	int norm() {return x*x+y*y;}
                                    	bool operator < (const pas &p) const{
                                    		return x != p.x ? x<p.x: y<p.y;
                                    	}
                                    	bool operator == (const pas &p) const{
                                    		return x==p.x && y==p.y;
                                    	}
                                    };
int mod=10000;
int dp[600][600][2][11];
int dp2[600][600][2][11];
int m;
int ch(string e ){
	if(e=="0") return 1;
	if(e.length()==1){
		return (1+(e[0]-'0')/m);
	}
	while(e[0]=='0') e=e.substr(1);
	
	for(int i=0;i<600;i++)for(int j=0;j<600;j++)for(int k=0;k<2;k++)for(int f=0;f<11;f++)dp[i][j][k][f]=0,dp2[i][j][k][f]=0;
	
	dp[0][0][0][10]=1;
	dp2[0][0][0][10]=1;

	for(int i=0;i<e.length();i++){
		int gk=1;
		if(i%2) gk*=-1;
		for(int num=0;num<10;num++){
			
			for(int j=0;j<m;j++){
				for(int f=0;f<11;f++){
					if(f==10 && num==0) continue;
					if(num<e[i]-'0' && (gk*(num-f)>0 || f==10)){
						dp[i+1][(j*10+num)%m][1][num]+=dp[i][j][1][f];
						dp[i+1][(j*10+num)%m][1][num]+=dp[i][j][0][f];
				
					}
					else if(num==e[i]-'0'  && (gk*(num-f)>0 || f==10)){
						dp[i+1][(j*10+num)%m][1][num]+=dp[i][j][1][f];
						dp[i+1][(j*10+num)%m][0][num]+=dp[i][j][0][f];
					}
					else if(num>e[i]-'0'  && (gk*(num-f)>0 || f==10)){
						dp[i+1][(j*10+num)%m][1][num]+=dp[i][j][1][f];
					}
					dp[i+1][(j*10+num)%m][0][num]%=mod;
					dp[i+1][(j*10+num)%m][1][num]%=mod;
				}
			}
			
			
			
		}
		if(i>0){
				for(int num=1;num<10;num++) dp[i+1][num%m][1][num]++;
			}
//		for(int j=0;j<m;j++)for(int k=0;k<2;k++)for(int l=0;l<11;l++)if(dp[i+1][j][k][l])cout<<"1 "<<i+1<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i+1][j][k][l]<<endl;
	//	cout<<dp[i+1][0][1][5]<<endl;
		
	}
	
	for(int i=0;i<e.length();i++){
		int gk=-1;
		if(i%2) gk*=-1;
		for(int num=0;num<10;num++){
			
			for(int j=0;j<m;j++){
				for(int f=0;f<11;f++){
					if(f==10 && num==0) continue;
					if(num<e[i]-'0' && (gk*(num-f)>0 || f==10)){
						dp2[i+1][(j*10+num)%m][1][num]+=dp2[i][j][1][f];
						dp2[i+1][(j*10+num)%m][1][num]+=dp2[i][j][0][f];
				
					}
					else if(num==e[i]-'0'  && (gk*(num-f)>0 || f==10)){
						dp2[i+1][(j*10+num)%m][1][num]+=dp2[i][j][1][f];
						dp2[i+1][(j*10+num)%m][0][num]+=dp2[i][j][0][f];
					}
					else if(num>e[i]-'0'  && (gk*(num-f)>0 || f==10)){
						dp2[i+1][(j*10+num)%m][1][num]+=dp2[i][j][1][f];
					}
					dp2[i+1][(j*10+num)%m][0][num]%=mod;
					dp2[i+1][(j*10+num)%m][1][num]%=mod;
				}
			}
			
			
		}
		if(i>0 && i!=e.length()-1){
				for(int num=1;num<10;num++) dp2[i+1][num%m][1][num]++;
			}
		
	//	for(int j=0;j<m;j++)for(int k=0;k<2;k++)for(int l=0;l<11;l++)if(dp2[i+1][j][k][l])cout<<"2 "<<i+1<<" "<<j<<" "<<k<<" "<<l<<" "<<dp2[i+1][j][k][l]<<endl;

	}
	int ans=1;
	for(int f=0;f<=10;f++){
//		cout<<"1 "<<f<<" "<<dp[e.length()][0][1][f]<<endl;
//		cout<<"2 "<<f<<" "<<dp2[e.length()][0][1][f];
	//	cout<<endl;
		ans+=dp[e.length()][0][1][f]+dp2[e.length()][0][1][f]+dp[e.length()][0][0][f]+dp2[e.length()][0][0][f];
		ans%=mod;
	}
	return ans;
}


           signed main(){
   	//	int pr[3];
     
      
           	
           	string s1,s2;
           	cin>>s1>>s2;
           	
           	int l=s1.length();
           	for(int i=l-1;i>=0;i--){
           		if(s1[i]!='0'){
           			s1[i]--;
           			
           			break;
           		}
           		s1[i]='9';
           	}
           	
           	
           	cin>>m;
       //    	cout<<ch(s2)<<endl;
           	cout<<(ch(s2)-ch(s1)+mod)%mod<<endl;
           	
           	//cout<<ans<<endl;
           }
             
