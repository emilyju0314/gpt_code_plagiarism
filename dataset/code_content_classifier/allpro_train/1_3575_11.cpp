#include<bits/stdc++.h>
using namespace std;
const int N=1234568,B=(1<<20)-1; bool fl[N]; int op,l,r,x;
int n,m,ql,qr,rt,ans,A,q[N],fa[N],s1[N],s2[N],ch[N][2],dep[N],f1[N],f2[N],f3[N],qt[N],qc[N];
inline bool get(int u){
	return (ch[fa[u]][1]==u);
}
inline void upd(int u){
	if(dep[u]==-1) return;
	if(!ch[u][1]) f1[u]=f1[ch[u][0]],f2[u]=f2[ch[u][0]],s1[u]=s1[ch[u][0]],s2[u]=s2[ch[u][0]];
	else if(!ch[u][0]) f1[u]=f1[ch[u][1]],f2[u]=f2[ch[u][1]],s1[u]=s1[ch[u][1]],s2[u]=s2[ch[u][1]];
	else{
		f1[u]=(f1[ch[u][0]]&f1[ch[u][1]]);
		f2[u]=(f2[ch[u][0]]&f2[ch[u][1]]);
		s1[u]=(s1[ch[u][0]]+s1[ch[u][1]]);
		s2[u]=(s2[ch[u][0]]+s2[ch[u][1]]);
	}
}
inline void psh(int u){
	if(f3[u]&(1<<dep[u])) swap(ch[u][0],ch[u][1]);
	f3[ch[u][0]]^=f3[u],f3[ch[u][1]]^=f3[u];
	int a=f1[u],b=f2[u];
	f1[u]=(b&f3[u])|(a&(B^f3[u]));
	f2[u]=(a&f3[u])|(b&(B^f3[u]));
	f3[u]=0;
}
inline void pushdown(int u){
	psh(u),psh(ch[u][0]),psh(ch[u][1]);
}
inline int newnode(){
	ql++; if(ql==1234567) ql=0; fl[q[ql]]=1; return q[ql];
}
inline void delnode(int u){
	if(u<=1) return;
	qr++; if(qr==1234567) qr=0;
	ch[fa[u]][get(u)]=0;
	if(fa[u]){
		upd(fa[u]);
	}
	f1[u]=f2[u]=f3[u]=ch[u][0]=ch[u][1]=fa[u]=s1[u]=s2[u]=dep[u]=0,q[qr]=u,fl[u]=0;
}
inline void ins(int u,int c){
	if(dep[u]==-1){
		s1[u]=1,s2[u]++,f1[u]=(c^B),f2[u]=c; return;
	}
	if(c&(1<<dep[u])){
		if(!ch[u][1]) ch[u][1]=newnode(),dep[ch[u][1]]=dep[u]-1,fa[ch[u][1]]=u;
		ins(ch[u][1],c);
	}
	else{
		if(!ch[u][0]) ch[u][0]=newnode(),dep[ch[u][0]]=dep[u]-1,fa[ch[u][0]]=u;
		ins(ch[u][0],c);
	}
	upd(u);
}
inline int chk(int A,int op,int x,int y,int d){
	if(op==1) x=(x&y);
	if(op==2) x=(x|y);
	if(op==3) x=(x^y);
	if(x) A=A|(1<<d); else A=(((A^B)|(1<<d))^B);
	return A;
}
inline void bfs(int t,int l,int r,int ql,int qr){
	pushdown(t);
	if(l==ql&&r==qr){
		if(op<=3){
			qt[++qt[0]]=t,qc[qt[0]]=A;
			ch[fa[t]][get(t)]=0,upd(fa[t]);
			fa[t]=0;
		}
		else ans+=s1[t];
		return;
	}
	int d=(l+r)>>1;
	if(ql<=d){
		if(ch[t][0]){
			A=chk(A,op,(x&(1<<dep[t]))>0,0,dep[t]);
			bfs(ch[t][0],l,d,ql,min(d,qr));
		}
	}
	if(d+1<=qr){
		if(ch[t][1]){
			A=chk(A,op,(x&(1<<dep[t]))>0,1,dep[t]);
			bfs(ch[t][1],d+1,r,max(d+1,ql),qr);
		}
	}
	upd(t);
}
inline int merge(int u,int t){
	pushdown(u);
	pushdown(t);
	if(!s1[u]){
		delnode(u); return t;
	}
	if(!s1[t]){
		delnode(t); return u;
	}
	if(!u||!t) return (u+t);
	if(dep[u]==-1){
		s1[u]=1,s2[u]=s1[u]+s2[t]; delnode(t); 
		return u;
	}
	ch[u][0]=merge(ch[u][0],ch[t][0]);
	ch[u][1]=merge(ch[u][1],ch[t][1]);
	delnode(t),upd(u);
	fa[ch[u][0]]=u,fa[ch[u][1]]=u;
	return u;
}
inline void AND(int u,int c){
	pushdown(u);
	if(((f1[u]|f2[u])&(B^c))==(B^c)){
		int C=0;
		for(int i=0;i<=19;i++) if(!((1<<i)&c)&&((1<<i)&f2[u])) f3[u]^=(1<<i);
		pushdown(u); return;
	}
	if(ch[u][0]) AND(ch[u][0],c);
	if(ch[u][1]) AND(ch[u][1],c);
	if(!(c&(1<<dep[u]))) ch[u][0]=merge(ch[u][0],ch[u][1]),ch[u][1]=0;
	upd(u);
}
inline void OR(int u,int c){
	pushdown(u);
	if(((f1[u]|f2[u])&c)==c){
		int C=0;
		for(int i=0;i<=19;i++) if(((1<<i)&c)&&((1<<i)&f1[u])) f3[u]^=(1<<i);
		pushdown(u); return;
	}
	if(ch[u][0]) OR(ch[u][0],c);
	if(ch[u][1]) OR(ch[u][1],c);
	if(c&(1<<dep[u])) ch[u][1]=merge(ch[u][0],ch[u][1]),ch[u][0]=0;
	upd(u);
}
inline int dfs(int u,int A,int B){
	pushdown(u);
	if(dep[u]==dep[A]) return merge(A,u);
	if(B&(1<<dep[u])){
		if(!ch[u][1]) ch[u][1]=newnode(),dep[ch[u][1]]=dep[u]-1,fa[ch[u][1]]=u;
		ch[u][1]=dfs(ch[u][1],A,B);
		fa[ch[u][1]]=u;
	}
	else{
		if(!ch[u][0]) ch[u][0]=newnode(),dep[ch[u][0]]=dep[u]-1,fa[ch[u][0]]=u;
		ch[u][0]=dfs(ch[u][0],A,B);
		fa[ch[u][0]]=u;
	}
	upd(u);
	return u;
}
int main(){
	for(int i=2;i<=1234567;i++) qr++,q[qr]=i;
	cin>>n>>m,rt=1,dep[rt]=19;
	for(int i=1;i<=n;i++) scanf("%d",&x),ins(rt,x);
	while(m--){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			scanf("%d",&x),qt[0]=0,A=0,bfs(rt,0,B,l,r);
			for(int i=1;i<=qt[0];i++){
				AND(qt[i],x);
				if(qt[i]==1) continue;
				rt=dfs(rt,qt[i],qc[i]);
			}
		}
		if(op==2){
			scanf("%d",&x),qt[0]=0,A=0,bfs(rt,0,B,l,r);
			for(int i=1;i<=qt[0];i++){
				OR(qt[i],x);	
				if(qt[i]==1) continue;
				rt=dfs(rt,qt[i],qc[i]);
			}
		}
		if(op==3){
			scanf("%d",&x),qt[0]=0,A=0,bfs(rt,0,B,l,r);
			for(int i=1;i<=qt[0];i++){
				f3[qt[i]]^=x,pushdown(qt[i]);
				if(qt[i]==1) continue;
				rt=dfs(rt,qt[i],qc[i]);
			}
		}
		if(op==4){
			ans=0,bfs(rt,0,B,l,r);
			printf("%d\n",ans);
		}
	}
}
