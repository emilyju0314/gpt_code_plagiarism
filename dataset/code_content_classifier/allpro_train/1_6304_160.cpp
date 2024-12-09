#include <iostream>

using namespace std;

int main(void){
	int a,b;
	while(cin>>a>>b){
		int tl[101][101]={};
		tl[a][b]++;
		tl[b][a]++;
		while(cin>>a>>b,a||b){
			tl[a][b]++;
			tl[b][a]++;
		}
		bool f=true;
		for(int i=1;i<101;++i){
			int cnt=0;
			for(int j=1;j<101;++j){
				cnt+=tl[i][j];
			}
			//cerr<<cnt<<endl;
			if(i<3 && cnt%2==0) f=false;
			if(3<=i && cnt%2==1) f=false;
		}
		cout<<(f?"OK":"NG")<<endl;
	}
	return 0;
}