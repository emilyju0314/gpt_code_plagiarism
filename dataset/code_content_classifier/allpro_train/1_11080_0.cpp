#include<stdio.h>
#include<algorithm>
using namespace std;
int p[500];
int q[250][500];
int r[250][500];
int ret[500];
int s[500];
int t[250][500];
int u[500];
int v[250][500];
int w[250][500];
int ABS(int a){return max(a,-a);}
int LIM=240;
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)p[i]=i;
	for(int i=0;i<LIM;i++){
		random_shuffle(p,p+a);
		printf("?");
		for(int j=0;j<a;j++)printf(" %d",p[j]+1);
		for(int j=0;j<a;j++)q[i][j]=p[j];
		printf("\n");fflush(stdout);
		for(int j=0;j<a;j++)scanf("%d",&r[i][j]);
	}
	for(int i=0;i<a;i++)ret[i]=i;
	random_shuffle(ret,ret+a);
	int score=0;
	for(int i=0;i<a;i++)s[ret[i]]=i;
	for(int i=0;i<LIM;i++){
		for(int j=0;j<a;j++){
			t[i][q[i][j]]=j;
		}
		for(int j=0;j<a;j++)u[j]=ABS(s[j]-t[i][j]);
		for(int j=0;j<a;j++){
			v[i][r[i][j]]++;
			w[i][u[j]]++;
		}
		for(int j=0;j<a;j++)score+=min(v[i][j],w[i][j]);
	}
	while(score<LIM*a){
		int cl=rand()%a;
		int cr=rand()%a;
		if(cl==cr)continue;
		int nl=ret[cl];
		int nr=ret[cr];
	//	swap(s[ret[cl]],s[ret[cr]]);
	//	swap(ret[cl],ret[cr]);
		int tmp=score;
		for(int i=0;i<LIM;i++){
			int at[4];
			at[0]=ABS(s[nl]-t[i][nl]);
			at[1]=ABS(s[nl]-t[i][nr]);
			at[2]=ABS(s[nr]-t[i][nl]);
			at[3]=ABS(s[nr]-t[i][nr]);
			if(w[i][at[0]]<=v[i][at[0]])tmp--;
			w[i][at[0]]--;
			if(w[i][at[3]]<=v[i][at[3]])tmp--;
			w[i][at[3]]--;
			if(w[i][at[1]]<v[i][at[1]])tmp++;
			w[i][at[1]]++;
			if(w[i][at[2]]<v[i][at[2]])tmp++;
			w[i][at[2]]++;
			
			w[i][at[0]]++;w[i][at[1]]--;w[i][at[2]]--;w[i][at[3]]++;
			if(tmp<score-10)break;
		}
		if(tmp>=score){
			score=tmp;
			for(int i=0;i<LIM;i++){
				int at[4];
				at[0]=ABS(s[nl]-t[i][nl]);
				at[1]=ABS(s[nl]-t[i][nr]);
				at[2]=ABS(s[nr]-t[i][nl]);
				at[3]=ABS(s[nr]-t[i][nr]);
				w[i][at[0]]--;w[i][at[1]]++;w[i][at[2]]++;w[i][at[3]]--;
			}
			swap(ret[cl],ret[cr]);
			swap(s[nl],s[nr]);
		}
	}
	printf("!");
	for(int i=0;i<a;i++)printf(" %d",ret[i]+1);
	printf("\n");
	fflush(stdout);
}