#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
bool maps[2004][2004];
int main() {
	while(true){
	for(int i=0;i<2004;i++)
		for(int j=0;j<2004;j++)
			maps[i][j]=false;
	int mask[1001][2][2];//番号/始点か/Xか
	int dx[]={0,1,0,-1};
	int dy[]={-1,0,1,0};
	int w,h,n;
	vector<int> points[2];
	map<int,int>zeep[2];
	queue<pair<int,int> > qoo;
	cin >> w >> h;
	if(w==0)
	break;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				cin >> mask[i][j][k];
				if(j==0)
				points[k].push_back(mask[i][j][k]);
				else
				points[k].push_back(mask[i][j][k]);
			}
		}
	}
	
	for(int k=0;k<2;k++){
		int now=1;
		sort(points[k].begin(),points[k].end());
		zeep[k].insert( map<int,int>::value_type(0,0) );
		
		for(int i=0;i<points[k].size();i++){
		if((i==0||points[k][i]!=points[k][i-1])&&points[k][i]!=0 &&points[k][i]!=((k==0)?w:h)){
		zeep[k].insert(map<int,int>::value_type(points[k][i],now) );
		//cout << points[k][i] << endl;
		now++;
		}
		}
		int r=(k==0)?w:h;
		if(zeep[k][r]==0){
		zeep[k][r]=now;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=zeep[0][mask[i][0][0]];j<zeep[0][mask[i][1][0]];j++)
			for(int k=zeep[1][mask[i][0][1]];k<zeep[1][mask[i][1][1]];k++){
				maps[j][k]=true;
			}
	}
	
	/*map<int,int>::iterator it =zeep[0].begin();
	while(it!=zeep[0].end()){
		cout <<(*it).first << " "<<(*it).second << endl;
		it++;
	}*/

//	cout << zeep[1][h-1] << endl;
/*	for(int i=0;i<zeep[1][h];i++){
		for(int j=0;j<zeep[0][w];j++)
		cout << maps[j][i] ;
		
		cout << endl;
		}*/
		
	int painted=0;
	
	for(int i=0;i<zeep[0][w];i++)
		for(int j=0;j<zeep[1][h];j++){
			if(maps[i][j]==false){
				maps[i][j]=true;
				painted++;
				qoo.push(pair<int,int>(i,j));
				
				//cout << i <<" head "<< j <<  endl;
				int x,y;
				while(!qoo.empty()){
					x=qoo.front().first;
					y=qoo.front().second;
					qoo.pop();
					for(int k=0;k<4;k++){
						
						if(x+dx[k]>=0 && x+dx[k]<zeep[0][w] &&y+dy[k]>=0 && y+dy[k]<zeep[1][h] &&maps[x+dx[k]][y+dy[k]]==false){
						maps[x+dx[k]][y+dy[k]]=true;
						qoo.push(pair<int,int>(x+dx[k],y+dy[k]));
						}
						
					}
					
				}
				
			}	
		}
		
	cout << painted << endl;
}
	return 0;
}