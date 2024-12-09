#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

string get(long long start){
	string res="";
	for(int i=0;;i++){
		stringstream ss;
		ss<<start+i;
		string add;
		ss>>add;
		res+=add;
		if(res.size()>140) break;
	}
	return res;
}

long long tens[18];

long long count(long long x){
	if(x<10) return x;
	int dig=lower_bound(tens,tens+18,x)-tens;
	dig--;
	long long res=0;
	for(int i=0;i<dig;i++){
		res+=tens[i]*9*(i+1);
	}
	long long rem=x-tens[dig];
	res+=rem*(dig+1);
//	cout<<x<<" "<<res<<"\n";
	return res+1;
}

long long solve2(int n){
	long long res=0;
	for(int i=0;i<n;i++) res+=tens[i]*9*(i+1);
	res+=2;
	return res;
}

bool all_zero(string str){
	for(int i=0;i<str.size();i++) if(str[i]!='0') return false;
	return true;
}

long long solve(string str){
	if(str=="1") return 1;
	int N=str.size();
	int n=min(N,33);
	long long res=-1;
	for(int i=0;i<n;i++) for(int j=i+1;j<=min(n,i+16);j++){
		long long cur=0;
		for(int k=i;k<j;k++){
			cur*=10;
			cur+=(str[k]-'0');
		}
	//	if(i==0&&j==n) cout<<"cur="<<cur<<"\n";
		if(cur-1<=0) continue;
		string cand=get(cur-1);
		int id=-1;
	//	cout<<cand<<"\n";
		for(int m=0;m+str.size()<cand.size();m++){
			bool ok=true;
			for(int p=0;p<str.size();p++){
				if(cand[m+p]!=str[p]){
					ok=false;
					break;
				}
			}
			if(ok){
				id=m;
				break;
			}
		}
		if(id==-1) continue;
		long long tmp=count(cur-1);
		tmp+=id;
		if(res==-1||res>tmp) res=tmp;
	}
	if(str.size()<=34){
	//	cout<<"str="<<str<<"\n";
		string firstHalf,secondHalf;
		for(int i=1;i+1<str.size();i++){
			firstHalf="";secondHalf="";
			for(int j=0;j<i;j++) firstHalf+=str[j];
			for(int j=i;j<str.size();j++) secondHalf+=str[j];
			string nxt=firstHalf;
		//	cout<<"i="<<i<<"fi="<<firstHalf<<"se="<<secondHalf<<"\n";
			bool flg=false;
			for(int j=firstHalf.size()-1;j>=0;j--){
				if(firstHalf[j]!='9'){
					flg=true;
					nxt[j]++;
					for(int k=j+1;k<firstHalf.size();k++) nxt[k]='0';
					break;
				}
			}
			if(flg==false){
				nxt="";
				for(int k=0;k<firstHalf.size();k++) nxt+='0';
			}
	//		cout<<"cand:"<<firstHalf<<" "<<nxt<<" "<<secondHalf<<"\n";
			int m=min(nxt.size(),secondHalf.size());
			for(int j=m;j>=0;j--){
				string str1=nxt.substr(0,j);
				string str2=secondHalf.substr(secondHalf.size()-j,j);
				if(str1!=str2) continue;
				string cur=secondHalf+nxt.substr(j,1000);
				if(cur.size()>=17) break;
				long long t;
				stringstream ss;
				ss<<cur;
				ss>>t;
				string a=get(t-1);
				int id=-1;
		//		cout<<t<<"\n";
				for(int k=0;k+str.size()<a.size();k++){
					bool ok=true;
					for(int m=0;m<str.size();m++){
						if(str[m]!=a[m+k]){
							ok=false;
							break;
						}
					}
					if(ok){
						id=k;
						break;
					}
				}
				if(id!=-1){
		//			cout<<t<<" "<<id<<"\n";
					long long a=count(t-1);
					if(res==-1||res>a+id) res=a+id;
				}
			}
		}
	}
	if(all_zero(str)){
		long long tmp=solve2(str.size());
		if(res==-1||res>tmp) res=tmp;
	}
	return res;
}

int main(){
	tens[0]=1;
	for(int i=1;i<18;i++) tens[i]=tens[i-1]*10;
	string str;
	while(true){
		cin>>str;
		if(str=="#") break;
		long long ans=solve(str);
		cout<<ans<<"\n";
	}
	return 0;
}