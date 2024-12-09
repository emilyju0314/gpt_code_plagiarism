#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
char in[3];
set<int> S[5];
set<int> U;
int cur;
char str[110000];
set<int>expr();
set<int>term(){
	if(str[cur]=='('){
		cur++;
		set<int>ret=expr();
		cur++;
		return ret;
	}
	if(str[cur]=='c'){
		cur++;
		set<int>tmp=term();
		set<int>ret;
		for(set<int>::iterator it=U.begin();it!=U.end();it++){
			if(!tmp.count(*it))ret.insert(*it);
		}
		return ret;
	}
	if(str[cur]=='U'){
		cur++;
		return U;
	}
	return S[str[cur++]-'A'];
}
set<int>expr(){
	set<int>ret=term();
	while(str[cur]=='u'||str[cur]=='i'||str[cur]=='d'||str[cur]=='s'){
		char c=str[cur];
		cur++;
		set<int>tmp=term();
		set<int>to;
		if(c=='i'){
			for(set<int>::iterator it=ret.begin();it!=ret.end();it++){
				if(tmp.count(*it))to.insert(*it);
			}
		}
		if(c=='u'){
			for(set<int>::iterator it=ret.begin();it!=ret.end();it++){
				to.insert(*it);
			}
			for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++){
				to.insert(*it);
			}
		}
		if(c=='d'){
			for(set<int>::iterator it=ret.begin();it!=ret.end();it++){
				if(!tmp.count(*it))to.insert(*it);
			}
		}
		if(c=='s'){
			for(set<int>::iterator it=ret.begin();it!=ret.end();it++){
				if(!tmp.count(*it))to.insert(*it);
			}
			for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++){
				if(!ret.count(*it))to.insert(*it);
			}
		}
		ret=to;
	}
	return ret;
}
int main(){
	int n;
	while(~scanf("%s%d",in,&n)){
		for(int i=0;i<5;i++)S[i].clear();
		U.clear();
		cur=0;
		for(int i=0;i<n;i++){
			int p;scanf("%d",&p);
			S[in[0]-'A'].insert(p);
			U.insert(p);
		}
		while(1){
			scanf("%s%d",in,&n);
			if(in[0]=='R')break;
			for(int i=0;i<n;i++){
				int p;scanf("%d",&p);
				S[in[0]-'A'].insert(p);
				U.insert(p);
			}
		}
		scanf("%s",str);
		set<int>res=expr();
		bool f=true;
		
		for(set<int>::iterator it=res.begin();it!=res.end();it++){
			if(!f)printf(" ");
			printf("%d",(*it));
			f=false;
		}
		if(f)printf("NULL");
		printf("\n");
	}
}