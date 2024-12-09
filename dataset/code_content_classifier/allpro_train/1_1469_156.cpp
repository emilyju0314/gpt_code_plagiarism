#include <iostream>

using namespace std;

int main()
{
	for(int n,m;cin>>n,n;){
		int cx=10,cy=10;
		int grid[21][21]={};
		grid[cy][cx]=1;
		
		int xs[20],ys[20];
		for(int i=0;i<n;i++)
			cin>>xs[i]>>ys[i];
		cin>>m;
		for(int i=0;i<m;i++){
			char d; int len;
			cin>>d>>len;
			int dx=0,dy=0;
			if(d=='N') dx=0,dy=1;
			if(d=='E') dx=1,dy=0;
			if(d=='S') dx=0,dy=-1;
			if(d=='W') dx=-1,dy=0;
			for(int j=0;j<len;j++){
				cx+=dx,cy+=dy;
				grid[cy][cx]=1;
			}
		}
		int res=0;
		for(int i=0;i<n;i++)
			res+=grid[ys[i]][xs[i]];
		cout<<(res==n?"Yes":"No")<<endl;
	}
	
	return 0;
}