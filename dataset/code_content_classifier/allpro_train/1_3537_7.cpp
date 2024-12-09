#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[131072];
char S[131072];
int inv[46000];
bool ok;
int p;
pair<int,int> eq(int a);
pair<int,int>ter(int a){
	if(S[a]=='('){
		pair<int,int> t=eq(a+1);
		t.second++;
	//	printf("t%d %d %d\n",a,t.first,t.second);
		return t;
	}else{
		int at=a;
		int now=0;
		while('0'<=S[at]&&S[at]<='9'){
			now=(now*10+S[at]-'0')%p;
			at++;
		}
	//	printf("t%d %d %d\n",a,now,at-1);
		return make_pair(now,at-1);
	}
}
pair<int,int>fac(int a){
	pair<int,int> t=ter(a);
	int ret=t.first;
	while(S[t.second+1]=='*'||S[t.second+1]=='/'){
		if(S[t.second+1]=='*'){
			t=ter(t.second+2);
			ret=ret*t.first%p;
		}else{
			t=ter(t.second+2);
			ret=ret*inv[t.first]%p;
			if(t.first==0)ok=false;
		}
	//	t.second++;
	}
//	printf("f%d %d %d\n",a,ret,t.second);
	return make_pair(ret,t.second);
}
pair<int,int> eq(int a){
	pair<int,int> t=fac(a);
	int ret=t.first;
	while(S[t.second+1]=='+'||S[t.second+1]=='-'){
		if(S[t.second+1]=='+'){
			t=fac(t.second+2);
			ret=(t.first+ret)%p;
		}else{
			t=fac(t.second+2);
			ret=(p+ret-t.first)%p;
		}
	//	t.second++;
	}
//	printf("e%d %d %d\n",a,ret,t.second);
	return make_pair(ret,t.second);
}
int main(){
	while(1){
		gets(str);
		if(str[0]=='0')return 0;
		ok=true;
		p=0;
		int at=0;
		while('0'<=str[at]&&str[at]<='9'){
			p*=10;
			p+=str[at++]-'0';
		}
		inv[1]=1;
		for(int i=2;i<p;i++)inv[i]=p-p/i*inv[p%i]%p;
		at++;
		int v=0;
		for(int i=at;str[i];i++){
			if(str[i]!=' ')S[v++]=str[i];
		}
		S[v]=0;
		int res=eq(0).first;
		if(!ok)printf("NG\n");
		else printf("%s = %d (mod %d)\n",S,res,p);
		//printf("%s\n%s\n",str,S);
	}
}