#include <iostream>

using namespace std;

int data[1010][1010];

int main(){

	int n,m,a;

	while(cin>>n>>m>>a){
		if(n==0 && m== 0&&a==0)break;

		for(int i=0;i<1010;i++){
			for(int j=0;j<1010;j++){
				data[i][j]=0;
			}
		}

		int cnt,start,end;
		int max=0;

		for(int i=0;i<m;i++){
			cin>>cnt>>start>>end;
			data[cnt][start]=end;
			data[cnt][end]  =start;

			if(max<=cnt)max=cnt;
		}

		for(int i=max;i>=1;i--){
			if(data[i][a]>0){
				a = data[i][a];
			}
		}

		cout<<a<<endl;

	}

	return 0;
}