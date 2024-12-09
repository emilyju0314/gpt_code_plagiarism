#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#define all(c) c.begin(),c.end()
#define H 21
using namespace std;
typedef pair<int,int> P;
int y[2][6]={{0,7,7,7,7,14},{0,7,7,7,7,14}},x[2][6]={{7,0,7,14,21,7},{36,29,36,43,50,36}};
vector<string> s;
vector<string> rot(vector<string> t){
	vector<string> u(7,"");
	//285992
	//626685
	
	
	
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			u[i]+=t[j][6-i];
			if(u[i][j]=='|'){
				u[i][j]='-';
			}else if(u[i][j]=='-'){
				u[i][j]='|';
			}
		}
	}
	
	return u;
}
int dig(vector<string> f){
	int a=0,b=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			if(f[i][j]=='|'){
				a++;
			}else if(f[i][j]=='-'){
				b++;
			}
		}
	}
	if(a==2&&b==1){//1 7
		if(f[1][3]=='-'){
			return 7;
		}else{
			return 1;
		}
	}else if(a==2&&b==3){//2 3 5
		if(f[4][2]=='|'){
			return 2;
		}else if(f[2][2]=='|'){
			return 5;
		}else{
			return 3;
		}
	}else if(a==3&&b==1){
		return 4;
	}else if(a==3&&b==3){//6 9
		if(f[2][4]=='|'){
			return 9;
		}else{
			return 6;
		}
	}else{
		return 8;
	}
	
}
int cal(P a,int num){
	vector<string> f(7);
	for(int i=0;i<7;i++){
		f[i]=s[a.second+i].substr(a.first,7);
		reverse(all(f[i]));
		
		
	}
	if(num==1){
		f=rot(f);
	}else if(num==3){
		f=rot(f);f=rot(f);f=rot(f);
	}else if(num==5){
		vector<string> t=f;
		for(int j=0;j<7;j++){
			f[j]=t[6-j];
		}
	}
	/*for(int i=0;i<7;i++){
		cout<<f[i]<<endl;
	}*/
	//cout<<dig(f)<<endl;
	
	return dig(f);
}
int main(){
	s.resize(H);
	while(cin>>s[0],s[0][0]!='0'){
		for(int i=1;i<H;i++){
			cin>>s[i];
		}
		vector<int> m(6),o(6);
		for(int i=0;i<6;i++){
			m[i]=cal(P(x[0][i],y[0][i]),i);
		}
		for(int i=0;i<6;i++){
			o[i]=cal(P(x[1][i],y[1][i]),i);
		}
		int win=0,lose=0;
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				if(m[i]>o[j]){
					win++;
				}else if(m[i]<o[j]){
					lose++;
				}
				//cout<<m[i]<<" "<<o[j]<<" "<<win<<" "<<lose<<endl;
			}
		}
		//cout<<win<<" "<<lose<<endl;
		if(win>=lose)
			cout<<"HIGH"<<endl;
		else
			cout<<"LOW"<<endl;
	}
	return 0;
}