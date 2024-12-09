#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

int h,w;
char field[21][21];

const int INF=100000000;

// INFÈç­ªBÅ«È¢
int minArrivalCost[21][21];
// HìÌÚ®[gði[
vector<pair<int,int> > ghostPath;
// HìªÊßµ½êði[
bool passedGhost[11][21][21];

const int dy[]={-1,0,0,1};
const int dx[]={0,-1,1,0};

// ­ªe}XÖ½Çè­½ßÌÅ¬RXgðßé
void bfs(int sx,int sy){
	queue<pair<int,int> > *prv=new queue<pair<int,int> > ();
	queue<pair<int,int> > *nxt=new queue<pair<int,int> > ();
	prv->push(make_pair(sy,sx));

	bool passed[21][21];
	for(int i = 0; i < 21; i++){
		for(int j = 0; j < 21; j++){
			passed[i][j]=false;
		}
	}
	int cnt=0;
	while(prv->size()){
		while(prv->size()){
			pair<int,int> cp=prv->front();prv->pop();
			if(passed[cp.first][cp.second])
				continue;
			passed[cp.first][cp.second]=true;
			minArrivalCost[cp.first][cp.second]=min(minArrivalCost[cp.first][cp.second],cnt);
			for(int i = 0; i < 4; i++){
				pair<int,int> np=cp;
				np.first+=dy[i];
				np.second+=dx[i];
				if(np.first>=0&&np.second>=0&&np.first<h&&np.second<w){
					if(!passed[np.first][np.second]&&field[np.first][np.second]!='#'){
						nxt->push(np);
					}
				}
			}
		}
		cnt++;
		swap(prv,nxt);
	}

	delete prv,nxt;
}

int searchGhost(pair<int,int> cp,int tern,string pattern,pair<int,int> sp){
	// 500ñ®¢Äàoï¦È¢ÈçÎA-1ðÔ·B»¤ÅÈ¯êÎAoï¦éÅ¬^[ðÔ·
	int cnt=-1;
	while(1){
		bool f=false;
		for(int i = 0; i < pattern.size(); i++){
			cnt++;
			if(cnt==500)
				return -1;
			// ­ÌÊuÉBµ½ê
			if(sp==cp){
				if(tern<=cnt){
					return cnt;
				}
			}
//			if(passedGhost[i][cp.first][cp.second]){
//				f=true;
//				break;
//			}
//			passedGhost[i][cp.first][cp.second]=true;
//			ghostPath.push_back(cp);
			char c = pattern[i];
			pair<int,int> np=cp;
			
			if(c=='8')
				np.first-=1;
			else if(c=='6')
				np.second+=1;
			else if(c=='4')
				np.second-=1;
			else if(c=='2')
				np.first++;
			
			if(np.first<0)
				np.first=0;
			else if(np.first>=h)
				np.first=h-1;
			else if(np.second>=w)
				np.second=w-1;
			else if(np.second<0)
				np.second=0;
			cp=np;
		}
	}
}

int main(){

	while(cin>>h>>w&&!(h==0&&w==0)){
		ghostPath.clear();
		for(int i = 0; i < 21; i++){
			for(int j = 0; j < 21; j++){
				for(int k = 0; k < 11; k++){
					passedGhost[k][i][j]=false;
				}
				minArrivalCost[i][j]=INF;
			}
		}
		int sx,sy;
		int gx,gy;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin>>field[i][j];
				if(field[i][j]=='A'){
					sx=j;
					sy=i;
				}
				else if(field[i][j]=='B'){
					gx=j;
					gy=i;
				}
			}
		}
		string pattern;
		cin>>pattern;
		bfs(sx,sy);

		pair<int,int> cp=make_pair(gy,gx);
		//while(1){
		//	bool f=false;
		//	for(int i = 0; i < pattern.size(); i++){
		//		if(passedGhost[i][cp.first][cp.second]){
		//			f=true;
		//			break;
		//		}
		//		passedGhost[i][cp.first][cp.second]=true;
		//		ghostPath.push_back(cp);
		//		char c = pattern[i];
		//		pair<int,int> np=cp;
		//		
		//		if(c=='8')
		//			np.first-=1;
		//		else if(c=='6')
		//			np.second+=1;
		//		else if(c=='4')
		//			np.second-=1;
		//		else if(c=='2')
		//			np.first++;

		//		if(np.first<0)
		//			np.first=0;
		//		else if(np.first>=h)
		//			np.first=h-1;
		//		else if(np.second>=w)
		//			np.second=w-1;
		//		else if(np.second<0)
		//			np.second=0;
		//		cp=np;
		//	}
		//	if(f)
		//		break;
		//}
		int minCost=INF;
		pair<int,int> rp;
		// eHìÌB|CgÉÂ¢ÄAÞªBÅ«Ä¢é©Ç¤©ðÝé
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				//cp=ghostPath[i];
				cp=make_pair(i,j);
				int cst=minArrivalCost[cp.first][cp.second];
				if(cst!=INF){
					int r=searchGhost(make_pair(gy,gx),cst,pattern,cp);
					if(r!=-1){
						if(minCost>r){
							minCost=min(minCost,r);
							rp=cp;
						}
					}
				}
			}
				//if(cst!=INF){
			//	// ­ÌBªHìÌBæè©Á½ê
			//	if(cst<=i){
			//		if(minCost>i){
			//			rp=cp;
			//			minCost=min(minCost,i);
			//		}
			//	}
			//	// ­ÌBªHìæèx©Á½ê
			//	else{
			//		// HìÌ®«ðV~[g·é

			//		//int j=0;
			//		//while(1){
			//		//	if(ghostPath[j%ghostPath.size()]==cp){
			//		//		minCost=min(minCost,j);
			//		//		break;
			//		//	}
			//		//	j++;
			//		//}

			//		//// Hìª­éÜÅÒÂ
			//		//int cnt=cst;
			//		//int j=(cst)%ghostPath.size();
			//		//while(1){
			//		//	if(ghostPath[j]==cp){
			//		//		if(minCost>cnt){
			//		//			minCost=min(minCost,cnt);
			//		//			rp=cp;
			//		//		}
			//		//		break;
			//		//	}
			//		//	j=(j+1)%ghostPath.size();
			//		//	cnt++;
			//		//}
			//	}
			//}
		}
		if(minCost==INF)
			cout<<"impossible"<<endl;
		else{
			cout<<minCost<<" "<<rp.first<<" "<<rp.second<<endl;
		}
	}

	return 0;
}