#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int inv[2011];
char str[30][128];
int mod=2011;
int a;
int b;
int find(int top,int bottom,int left){
	for(int i=top;i<=bottom;i++)if(str[i][left]!='.')return i;
}
int find2(int top,int bottom,int left){
	for(int i=left;i<b;i++){
		for(int j=top;j<=bottom;j++){
			if(str[j][i]!='.')return i;
		}
	}
}
pair<int,int>expr(int top,int bottom,int left);
pair<int,int> fraction(int top,int bottom,int left){
	int base=find(top,bottom,left);
	pair<int,int>bunshi=expr(top,base-1,find2(top,base-1,left));
	pair<int,int>bunbo=expr(base+1,bottom,find2(base+1,bottom,left));
	return make_pair(bunshi.first*inv[bunbo.first]%mod,max(bunshi.second,bunbo.second)+1);
}
pair<int,int> primary(int top,int bottom,int left){
	int base=find(top,bottom,left);
	int at=left;
	if(str[base][at]>='0'&&str[base][at]<='9'){
		return make_pair(str[base][at]-'0',at);
	}else{
		pair<int,int>res=expr(top,bottom,left+2);
		res.second+=2;
		return res;
	}
}
pair<int,int> powexpr(int top,int bottom,int left){
	int base=find(top,bottom,left);
	int at=left;
	pair<int,int> val=primary(top,bottom,left);
	if(val.second<b-1&&base&&'0'<=str[base-1][val.second+1]&&str[base-1][val.second+1]<='9'){
		int res=1;
		for(int i=0;i<str[base-1][val.second+1]-'0';i++){
			res=res*val.first%mod;
		}
		return make_pair(res,val.second+1);
	}else{
		return val;
	}
}
pair<int,int> factor(int top,int bottom,int left){
	int base=find(top,bottom,left);
	int at=left;
	if(at<b-1&&str[base][at]=='-'&&str[base][at+1]=='-'){
		return fraction(top,bottom,at);
	}else if(str[base][at]=='-'){
		pair<int,int> val=factor(top,bottom,at+2);
		val.first=2011-val.first;
		return val;
	}else{
		return powexpr(top,bottom,at);
	}
}
pair<int,int> term(int top,int bottom,int left){
	int base=find(top,bottom,left);
	int val=1;
	int at=left;
	while(1){
		pair<int,int> res=factor(top,bottom,at);
		at=res.second+2;
		val=val*res.first%mod;
		if(at>=b||str[base][at]!='*'){
			if(at>=b)return make_pair(val,at);
			else return make_pair(val,at-2);
			break;
		}
		at+=2;
	}
}
pair<int,int> expr(int top,int bottom,int left){
	int base=find(top,bottom,left);
	int val=0;
	int at=left;
	int P=1;
	while(1){
		pair<int,int> res=term(top,bottom,at);
		at=res.second+2;
		val=(val+P*res.first+mod)%mod;
		if(at>=b||(str[base][at]!='+'&&str[base][at]!='-')){
			if(at>=b)return make_pair(val,at);
			else return make_pair(val,at-2);
		}
		if(str[base][at]=='+')P=1;
		else P=-1;
		at+=2;
	}
}
int main(){
	inv[1]=1;
	for(int i=2;i<2011;i++){
		inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	}
	while(scanf("%d",&a),a){
		for(int i=0;i<a;i++)scanf("%s",str[i]);
	//	printf("%s\n",str[0]);
		b=strlen(str[0]);
		int B=0;
		for(int i=0;i<a;i++)if(str[i][0]!='.')B=i;
		printf("%d\n",expr(0,a-1,0).first);
	}
}