#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	int k;
	int now=0;
	int t=0;
	int a0=0,a1=0,a2=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		if(k%3==0)a0++;
		if(k%3==1)a1++;
		if(k%3==2)a2++;
	}
	if(a1==0&&a2==0){
		cout<<1<<endl;
		return 0;
	}
	t=a0+1;
	if(a1>a2){
		a1--;
		now=1;
	}
	else{
		a2--;
		now=2;
	}
	while(true){
		// cout<<a2<<":"<<a1<<":"<<now<<endl;
		if(now==2){
			if(a2>0){
				now=1;
				a2--;
				t++;
			}else{
				if(a1>0){
					t++;
					a1--;
				}
				break;
			}
		}else if(now==1){
			if(a1>0){
				now=2;
				a1--;
				t++;
			}else{
				if(a2>0){
					t++;
					a2--;
				}
				break;
			}
		}
	}
	if(a1!=0&&a2!=0)t++;
	cout<<t<<endl;
	return 0;

}