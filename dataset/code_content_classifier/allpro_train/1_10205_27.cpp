#include"bits/stdc++.h"
using namespace std;

int n;

#define MAX 1002
int room[MAX][MAX];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			room[i][j]=0;
			if((i+j)&1)continue;
			room[i][j]=true;
		}
	}
	for(int i=0;i<n;i++){
		room[i][0]=true;
	}
	for(int i=0;i<n;i++){
		if(i==n-1||i%3==0){
			
		}
		else{
			continue;
		}
		for(int j=0;j<n;j++){
			room[i][j]=true;
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<room[i][j];
		}
		cout<<endl;
	}*/
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%2==0)continue;
			if(room[i][j]){
				v.push_back(make_pair(i,j));
			}
		}
	}
	cout<<v.size()<<endl;
	for(auto el:v){
		cout<<el.first<<" "<<el.second<<endl;
	}
	return 0;
}
