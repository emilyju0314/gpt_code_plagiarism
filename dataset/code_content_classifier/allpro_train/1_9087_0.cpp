#include<cstdio>
#include<map>
#include<vector>
#include<cassert>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

map<int,vector<int> > sameX,sameY;

vector<int> xs,ys;

long long mult(long long x,long long y){
	return ((x%mod)*(y%mod))%mod;
}

long long ad(long long x,long long y){
	return (x+y)%mod;
}

int getId(vector<int> &vec,int val){
	return distance(vec.begin(),lower_bound(vec.begin(),vec.end(),val));
}

void print(vector<int> &vec){
	printf("{");
	for(int i=0;i<vec.size();i++){
		printf("%d ",vec[i]);
	}
	printf("}\n");
}

struct Segtree{
	static const int SZ=524288;
//	long long dat[2][SZ];
//	long long weight[SZ];
//	long long sum[2][SZ];
//	bool same[2][SZ];
//	long long res[SZ];
	int dat[2][SZ];
	int weight[SZ];
	int sum[2][SZ];
	bool same[2][SZ];
	int res[SZ];
	int N;
	void update(int l,int r,int t,int x,int k,int a,int b){
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r){
			same[t][k]=true;
			dat[t][k]=x;
			sum[t][k]=mult(weight[k],x);
			res[k]=mult(sum[t^1][k],x);
			return;
		}
		for(int s=0;s<2;s++){
			if(same[s][k]){
				for(int j=k*2;j<=k*2+1;j++){
					same[s][j]=true;
					dat[s][j]=dat[s][k];
					sum[s][j]=mult(weight[j],dat[s][k]);
					res[j]=mult(sum[s^1][j],dat[s][j]);
				}
			}
		}
		same[t][k]=false;
		update(l,r,t,x,k*2,a,(a+b)/2);
		update(l,r,t,x,k*2+1,(a+b)/2,b);
		for(int s=0;s<2;s++){
			sum[s][k]=ad(sum[s][k*2],sum[s][k*2+1]);
		}
		res[k]=ad(res[k*2],res[k*2+1]);
	}
	void update(int l,int r,int t,int x){
//		printf("\n");
//		printf("update %d %d %d %d\n",l,r,t,x);
//		printf("before (%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld)\n",
//			sum[0][2],sum[1][2],res[2],sum[0][3],sum[1][3],res[3],sum[0][1],sum[1][1],res[1]);
		if(l>=r) return;
		update(l,r,t,x,1,0,N);
//		printf("cur_res=%lld\n",res[1]);
//		printf("updated (%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld)\n",
//			sum[0][2],sum[1][2],res[2],sum[0][3],sum[1][3],res[3],sum[0][1],sum[1][1],res[1]);
//		printf("\n");
	}
	void init(int *w,int N_){
		N=1;
		while(N<N_) N*=2;
		for(int i=N;i<=N*2-1;i++){
			weight[i]=w[i-N];
//			printf("%d",weight[i]);
		}
//		printf("\n");
		for(int i=N-1;i>=1;i--){
			weight[i]=weight[i*2]+weight[i*2+1];
		}
		same[0][1]=true;
		same[1][1]=true;
	}
	long long get(){
		return res[1];
	}
};

Segtree seg;

int rx[100100],ry[100100],K;
int X,Y;
long long num;

void compress(vector<int> &vec){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
}

void precalc(){
	for(int i=0;i<K;i++){
		xs.push_back(rx[i]);
		ys.push_back(ry[i]);
		xs.push_back(rx[i]+1);
		ys.push_back(ry[i]+1);
		sameX[rx[i]].push_back(ry[i]);
		sameY[ry[i]].push_back(rx[i]);
	}
	xs.push_back(X);
	ys.push_back(Y);
	xs.push_back(0);
	ys.push_back(0);
	compress(xs);
	compress(ys);
	map<int,vector<int> > :: iterator it;
	for(it=sameX.begin();it!=sameX.end();it++){
		vector<int> &vec=it->second;
		sort(vec.begin(),vec.end());
	}
	for(it=sameY.begin();it!=sameY.end();it++){
		vector<int> &vec=it->second;
		sort(vec.begin(),vec.end());
	}
	num=mult(X,Y)-K;
	if(num<=0) num+=mod;
}

vector<int> ids;
void process1(vector<int> &vec){//yoko
//	printf("process1\n");
	if(vec.size()==0){
		seg.update(0,ys.size()-1,0,Y-1);
		return;
	}
	ids.clear();
	for(int i=0;i<vec.size();i++){
		int id=getId(ys,vec[i]);
		ids.push_back(id);
	}
	for(int i=0;i<ids.size();i++){
		int cur=ids[i];
		seg.update(cur,cur+1,0,0);
		if(i!=0){
			int prv=ids[i-1];
			int val=ys[cur]-ys[prv]-2;
			seg.update(prv+1,cur,0,val);
		}
	}
	if(ids[0]!=0){
		int val=ys[ids[0]]-1;
		seg.update(0,ids[0],0,val);
	}
	if(ys[ids.back()]<=Y-2){
		int val=Y-ys[ids.back()]-2;
		int id=ids.back();
		seg.update(id+1,ys.size()-1,0,val);
	}
}

int getRange(vector<int> &vec,int val){
//	assert(vec.size()>0);
	if(vec.size()==0) return X;
	int id=distance(vec.begin(),lower_bound(vec.begin(),vec.end(),val));
	if(id==vec.size()){
		return X-vec.back()-1;
	}
	if(id==0) return vec[0];
	if(vec[id]==0) return 0;
	return vec[id]-vec[id-1]-1;
}

void process2(vector<int> &vec,int cur_x){//freed tate
//	printf("process2\n");
	for(int i=0;i<vec.size();i++){
		int y=vec[i];
		if(y==Y) continue;
//		printf("vec[%d]=%d\n",i,vec[i]);
		int val;
		/*if(sameY.count(vec[i])>0&&sameY[vec[i]].back()<cur_x){
			val=X-sameY[vec[i]].back()-1;
		}else{
			val=getRange(sameY[vec[i]],cur_x,X);
		}*/
		val=getRange(sameY[vec[i]],cur_x);
//		print(sameY[vec[i]]);
		if(val!=0) val--;
		int id=getId(ys,vec[i]);
		seg.update(id,id+1,1,val);
	}
}

void process3(vector<int> &vec){//appeared tate
//	printf("process3\n");
	for(int i=0;i<vec.size();i++){
		int id=getId(ys,vec[i]);
		seg.update(id,id+1,1,0);
	}
}

int w[300300];
void segtree_init(){
	for(int i=0;i+1<ys.size();i++){
		w[i]=ys[i+1]-ys[i];
	}
	seg.init(w,(int)ys.size()-1);
}

void input(){
	scanf("%d%d%d",&X,&Y,&K);
	for(int i=0;i<K;i++){
		scanf("%d%d",rx+i,ry+i);
	}
}

long long solve1(){
	segtree_init();
	long long res=0;
	for(int i=0;i+1<xs.size();i++){
//		printf("xs[%d]=%d\n",i,xs[i]);
		process1(sameX[xs[i]]);
		if(i==0){
			process2(ys,xs[i]);
		}else{
			process2(sameX[xs[i-1]],xs[i]);
		}
		process3(sameX[xs[i]]);
		long long tmp=seg.get();
		long long cur=mult(tmp,xs[i+1]-xs[i]);
		res+=cur;
//		printf("tmp=%lld,w=%d\n",tmp,xs[i+1]-xs[i]);
	}
	return res;
}

long long C(long long N,long long K){
	if(N<K) return 0;
	long long num=1,den=1;
	for(int i=1;i<=K;i++){
		den*=i;
		num=mult(num,(N-i+1));
	}
	while(true){
		if(num%den==0) return num/den;
		num+=mod;
	}
}

vector<int> parse(vector<int> &vec,int all){
	vector<int> res;
	if(vec.size()==0) return res;
	int prv=-1;
	for(int i=0;i<vec.size();i++){
		res.push_back(vec[i]-prv-1);
		prv=vec[i];
	}
	res.push_back(all-vec.back()-1);
	return res;
}

long long solve2(){//a-b,c
	long long res=0;
	map<int,vector<int> > :: iterator it;
	
	//yoko
	int cnt=0;
	for(it=sameX.begin();it!=sameX.end();it++){
		vector<int> &ys=it->second;
		if(ys.size()==0) continue;
		vector<int> vec=parse(ys,Y);
		for(int i=0;i<vec.size();i++){
			long long tmp=C(vec[i],2);
			tmp=mult(tmp,num-vec[i]);
			res=ad(res,tmp);
//			res=ad(res,C(vec[i],3));
		}
		cnt++;
	}
	long long tmp=C(Y,2);
	tmp=mult(tmp,num-Y);
	tmp=mult(tmp,X-cnt);
	res=ad(res,tmp);
//	res=ad(res,mult(tmp,X-cnt));
	
	//tate
	cnt=0;
	for(it=sameY.begin();it!=sameY.end();it++){
		vector<int> &xs=it->second;
		if(xs.size()==0) continue;
		vector<int> vec=parse(xs,X);
		for(int i=0;i<vec.size();i++){
			long long tmp=C(vec[i],2);
			tmp=mult(tmp,num-vec[i]);
			res=ad(res,tmp);
//			res=ad(res,C(vec[i],3));
		}
		cnt++;
	}
	tmp=C(X,2);
	tmp=mult(tmp,num-X);
	tmp=mult(tmp,Y-cnt);
	res=ad(res,tmp);
	return res;
//	res=ad(res,mult(tmp,Y-cnt));
}

long long solve3(){//a-b-c
	long long res=0;
	map<int,vector<int> > :: iterator it;
	
	//yoko
	int cnt=0;
	for(it=sameX.begin();it!=sameX.end();it++){
		vector<int> &ys=it->second;
		if(ys.size()==0) continue;
		vector<int> vec=parse(ys,Y);
		for(int i=0;i<vec.size();i++){
			res=ad(res,C(vec[i],3));
//			printf("vec[i]=%d\n",vec[i]);
		}
		cnt++;
	}
	long long tmp=C(Y,3);
	res=ad(res,mult(tmp,X-cnt));
//	printf("yoko res=%lld\n",res);
	
	//tate
	cnt=0;
	for(it=sameY.begin();it!=sameY.end();it++){
		vector<int> &xs=it->second;
		if(xs.size()==0) continue;
		vector<int> vec=parse(xs,X);
		for(int i=0;i<vec.size();i++){
			res=ad(res,C(vec[i],3));
//			printf("vec=%d\n",vec[i]);
		}
		cnt++;
	}
	tmp=C(X,3);
	res=ad(res,mult(tmp,Y-cnt));
	return res;
}

long long solve4(){//all
	return C(num,3);
}

long long solve(){/*
	long long res=solve4();
	res+=solve1();
	res-=solve2();
	res-=solve3();*/
	long long val1=solve1();
	long long val2=solve2();
	long long val3=solve3();
	long long val4=solve4();
	long long res=val1-val2-val3+val4;
	res%=mod;
	if(res<0) res+=mod;
//	printf("%lld %lld %lld %lld\n",val1,val2,val3,val4);
	return res;
}

int main(){
	input();
	precalc();/*
	long long tmp=solve1();
	printf("tmp=%lld\n",tmp);*/
	long long res=solve();
	printf("%lld\n",res);
	return 0;
}