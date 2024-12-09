#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
int n,m,T;
#define Maxn 50010
int x[Maxn<<1],y[Maxn<<1];
bitset<Maxn> b[Maxn];
bool ap[Maxn];
int seq[Maxn<<1];
int to[Maxn],B[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(n);rd(m);rd(T);
	for(int i=1;i<=m;++i){
		rd(x[i]);rd(y[i]);
    }
    if(T==1){
		for(int i=1;i<=n;++i)b[i][i]=1;
		bitset<Maxn> res;
		for(int i=m;i>=1;--i){
			res=b[x[i]]|b[y[i]];
			b[x[i]]=b[y[i]]=res;
		}
		res=b[1];
		for(int i=2;i<=n;++i)res&=b[i];
		int flag=-1;
		for(int i=1;i<=n;++i)
		    if(res[i]){
				flag=i;
				break;
		    } 
		if(flag==-1){
			puts("-1");
			return 0;
		}
		ap[flag]=true;
		for(int i=m;i>=1;--i){
			if(ap[x[i]]==false&&ap[y[i]]==false)seq[i]=0;
			else if(ap[x[i]]==true&&ap[y[i]]==true)seq[i]=0;
		    else if(ap[x[i]])seq[i]=0;
		    else seq[i]=1;
		    bool tmp=ap[x[i]]|ap[y[i]];
		    ap[x[i]]=ap[y[i]]=tmp;
		}
		for(int i=1;i<=m;++i)
		    if(seq[i]==0)printf("^");
		    else printf("v");
    }else{
		if(n==2){
			puts("-1");
			return 0;
		}
		for(int i=1;i<=n;++i){
			B[i]=i;
			to[i]=1;
		}
		for(int i=m;i>=1;--i){
			if(B[x[i]]==B[y[i]]){
				seq[i]=0;
				continue;
			}
			if(to[B[x[i]]]>=2){
				seq[i]=1;
				to[B[x[i]]]--;
				B[x[i]]=B[y[i]];
				to[B[y[i]]]++; 
			}else{
				seq[i]=0;
				to[B[y[i]]]--;
				B[y[i]]=B[x[i]];
				to[B[x[i]]]++;
			}
		}
		for(int i=1;i<=m;++i)
		    if(seq[i]==0)printf("^");
		    else printf("v");
    }
    return 0;
}