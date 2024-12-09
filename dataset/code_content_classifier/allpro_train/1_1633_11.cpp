#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char field[101][101];

int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};
int n;

bool check(int x,int y,int angle){
	if(!(y>=0&&x>=0&&y<n&&x<n)){
		return false;
	}

	for(int i = 0; i < 4; i++){
		if(angle==i)
			continue;
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(!(ny>=0&&nx>=0&&ny<n&&nx<n)){
			continue;
		}
		if(field[ny][nx]=='#'){
			return false;
		}
	}
	return true;
}

int main(){

	int nn;
	cin>>nn;
	for(int i = 0; i < nn; i++){
		if(i!=0)
			cout<<endl;
		cin>>n;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				field[j][k]=' ';
			}
		}

		// 0:ツ右,1:ツ可コ,2:ツ債カ,3:ツ湘」
		int angle=3;
		int cx=0;
		int cy=n-1;
		int cnt=0;
		field[cy][cx]='#';
		while(1){
			if(angle==3){
				int ny=cy-1;
				int nx=cx;
				if(check(nx,ny,angle)){
					field[ny][nx]='#';
					cnt=0;
					cy=ny;
					cx=nx;
				}
				else{
					if(cnt>=1){
						break;
					}
					cnt++;
					angle=0;
				}
			}
			else if(angle==2){
				int ny=cy;
				int nx=cx-1;
				if(check(nx,ny,angle)){
					field[ny][nx]='#';
					cnt=0;
					cy=ny;
					cx=nx;
				}
				else{
					if(cnt>=1){
						break;
					}
					cnt++;
					angle=3;
				}
			}
			else if(angle==1){
				int ny=cy+1;
				int nx=cx;
				if(check(nx,ny,angle)){
					field[ny][nx]='#';
					cnt=0;
					cy=ny;
					cx=nx;
				}
				else{
					if(cnt>=1){
						break;
					}
					cnt++;
					angle=2;
				}
			}
			else if(angle==0){
				int ny=cy;
				int nx=cx+1;
				if(check(nx,ny,angle)){
					field[ny][nx]='#';
					cnt=0;
					cy=ny;
					cx=nx;
				}
				else{
					if(cnt>=1){
						break;
					}
					cnt++;
					angle=1;
				}
			}
		}
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				cout<<field[j][k];
			}
			cout<<endl;
		}
	}

	return 0;
}