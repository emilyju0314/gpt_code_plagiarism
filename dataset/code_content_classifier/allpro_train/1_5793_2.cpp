#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int xs[40400][7],ys[40400][7];

vector<P> vals[6];

int N;
int cnt[40400*6];

queue<int> que;
bool used[40400];

int Q;
int qx[40400],qy[40400];

int main(){
	scanf("%d",&N);
	bool suc=true;
	for(int i=0;i<N;i++){
		for(int j=0;j<6;j++){
			scanf("%d%d",&xs[i][j],&ys[i][j]);
		}
		xs[i][6]=xs[i][0],ys[i][6]=ys[i][0];
		for(int j=0;j<6;j++){
			if(xs[i][j]==0&&xs[i][j+1]==0&&(long long)ys[i][j]*ys[i][j+1]<=0) suc=true;
			if(ys[i][j]==0&&ys[i][j+1]==0&&(long long)xs[i][j]*xs[i][j+1]<=0) suc=true;
			if(xs[i][j]+ys[i][j]==0&&xs[i][j+1]+ys[i][j+1]==0&&
				(long long)xs[i][j]*xs[i][j+1]<=0) suc=true;
		}
	}
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		scanf("%d%d",qx+i,qy+i);
	}
	if(suc==false){
		for(int i=0;i<Q;i++){
			if(qx[i]==0&&qy[i]==0) printf("YES\n");
			else printf("NO\n");
		}
		return 0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<6;j++){
			int x0=xs[i][j],x1=xs[i][j+1];
			int y0=ys[i][j],y1=ys[i][j+1];
			int z0=xs[i][j]+ys[i][j],z1=xs[i][j+1]+ys[i][j+1];
			if(x0>x1) swap(x0,x1);
			if(y0>y1) swap(y0,y1);
			if(z0>z1) swap(z0,z1);
			int tmp[]={x0,-x1,y0,-y1,z0,-z1};
			for(int k=0;k<6;k++){
				vals[k].push_back(P(tmp[k],i*6+j));
			}
		}
	}
	for(int i=0;i<6;i++){
		sort(vals[i].begin(),vals[i].end());
	}
	int ids[6]={};
	int res[6]={};
	for(int i=0;i<6;i++){
		for(ids[i]=0;ids[i]<vals[i].size();ids[i]++){
			if(vals[i][ids[i]].first<=0){
				int id=vals[i][ids[i]].second;
				cnt[id]++;
				if(cnt[id]==6){
					int id2=id/6;
					if(used[id2]) continue;
					used[id2]=true;
					que.push(id2);
				}
			}else{
				break;
			}
		}
	}
//	for(int i=0;i<vals[0].size();i++) printf("%d ",vals[0][i]);
//	printf("\n");
	while(!que.empty()){
		int id=que.front();
		que.pop();
		int tmp[6]={};
		for(int j=0;j<6;j++){
			tmp[0]=max(tmp[0],xs[id][j]+1);
			tmp[1]=max(tmp[1],-xs[id][j]+1);
			tmp[2]=max(tmp[2],ys[id][j]+1);
			tmp[3]=max(tmp[3],-ys[id][j]+1);
			tmp[4]=max(tmp[4],xs[id][j]+ys[id][j]+1);
			tmp[5]=max(tmp[5],-(xs[id][j]+ys[id][j])+1);
		}
//		printf("id=%d\n",id);
//		printf("tmp={");
//		for(int j=0;j<6;j++){
//			printf("%d,",tmp[j]);
//		}
//		printf("}\n");
		for(int j=0;j<6;j++){
			res[j]=max(res[j],tmp[j]);
		}
		for(int j=0;j<6;j++){
//			printf("j=%d\n",j);
//			printf("ids[j]=%d,vals[j][ids[j]]=%d\n",ids[j],vals[j][ids[j]]);
			while(ids[j]<vals[j].size()&&vals[j][ids[j]].first<=tmp[j]){
				int id=vals[j][ids[j]].second;
//				printf("%d++\n",id);
				cnt[id]++;
				if(cnt[id]==6){
					int id2=id/6;
					if(used[id2]){
						goto nextloop;
					}
					used[id2]=true;
					que.push(id2);
				}
				nextloop: ids[j]++;
			}
		}
	}
/*	int res[6];
	for(int i=0;i<6;i++){
		res[i]=vals[i][ids[i]-1].first;
		if(i%2==1) res[i]*=-1;
	}*/
	for(int i=0;i<6;i++){
		if(i%2==1) res[i]*=-1;
	}
//	for(int i=0;i<6;i++) printf("%d ",res[i]);
//	printf("\n");
//	for(int i=6;i<12;i++) printf("%d ",cnt[i]);
//	printf("\n");
	for(int q=0;q<Q;q++){
		bool ok=true;
		if((qx[q]<res[1])) ok=false;
		if((res[0]<qx[q])) ok=false;
		if((qy[q]<res[3])) ok=false;
		if((res[2]<qy[q])) ok=false;
		if((qx[q]+qy[q]<res[5])) ok=false;
		if((res[4]<qx[q]+qy[q])) ok=false;
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}