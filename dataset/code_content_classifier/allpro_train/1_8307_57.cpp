#include<iostream>

using namespace std;

int ans[4];
int data[4];
int a[4];
int coin[4]={10,50,100,500};

int change(int n){
	int re=0;
	for(int i=3;i>=0;i--){
		re+=n/coin[i];n%=coin[i];
	}
	return re;
}

int main(){
	int n;
	int count=0;
	while(cin>>n && n){
		fill(ans,ans+4,0);
		fill(a,a+4,0);
		int s=0,mi=0;
		for(int i=0;i<4;i++){cin>>data[i];s+=data[i];}
		mi=s+10;
		for(a[0]=0;a[0]<=data[0];a[0]++){
			for(a[1]=0;a[1]<=data[1];a[1]++){
				for(a[2]=0;a[2]<=data[2];a[2]++){
					for(a[3]=0;a[3]<=data[3];a[3]++){
						int sum=0;
						for(int i=0;i<4;i++)sum+=a[i]*coin[i];
						if(sum<n)continue;
						int tmp=s+change(sum-n);
						for(int i=0;i<4;i++)tmp-=a[i];
						if(tmp<mi){
							mi=tmp;
							for(int i=0;i<4;i++)ans[i]=a[i];
						}
					}
				}
			}
		}
		if(count)cout<<endl;
		for(int i=0;i<4;i++){
			if(ans[i]>0)cout<<coin[i]<<" "<<ans[i]<<endl;
		}
		
		count++;
	}

}