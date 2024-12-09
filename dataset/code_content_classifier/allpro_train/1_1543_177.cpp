#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
typedef pair<int,int>P;
#define fi first
#define se second
#define mk make_pair
int a[26];
int main(){
	int h,w;
	cin>>h>>w;
	int s1=h,s2=w,p=(h/2)*(w/2);
	string s[h];
	r(i,h)cin>>s[i];
	r(i,h)r(j,w)a[s[i][j]-'a']++;
	while(p>0){
		int c=0;
		r(i,26){//cout<<a[i]<<endl;
			if(a[i]>=4){
				p--;
				a[i]-=4;
				c++;
				break;
			}
		}
	    if(!c){
	    	cout<<"No"<<endl;
	    	return 0;
	    }
	}
	if((h*w)%2)r(i,26){
		if(a[i]%2){
			a[i]--;
			break;
		}
	}
	r(i,26)if(a[i]%2){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
}