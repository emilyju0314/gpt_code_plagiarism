#include <iostream>
using namespace std;

//J=0,O=1,I=2
int N;
int ary[1000010];

int joichec(int numJ,int numI,int& fla){
	int cntJ=0,cntJO=0,cntJOI=0;
	int cntI=0,cntOI=0,cntJOI2=0;
	for(int i=0;i<N;i++){
		switch(ary[i]){
			case 0:
				cntJ++;
				break;
			case 1:
				if(cntJ>0){
					cntJ--;
					cntJO++;
				}
				break;
			case 2:
				if(numJ>0){
					numJ--;
					cntJ++;
				}
				else{
					if(cntJO>0){
						cntJO--;
						cntJOI++;
					}
				}
				break;
		}
	}
	for(int i=N-1;i>=0;i--){
		switch(ary[i]){
			case 0:
				if(cntOI>0){
					cntOI--;
					cntJOI2++;
				}
				break;
			case 1:
				if(cntI>0){
					cntI--;
					cntOI++;
				}
				break;
			case 2:
				if(numI>0){
					numI--;
					cntI++;
				}
				else{
					if(cntOI>0){
						cntOI--;
						cntJOI2++;
					}
				}
				break;
		}
	}
	if(cntJO>cntOI) fla=-1;
	else if(cntJO<cntOI) fla=1;
	else fla=0;
	//cout<<cntJ<<" "<<cntJO<<" "<<cntJOI<<" "<<cntI<<" "<<cntOI<<" "<<cntJOI2<<endl;//debug
	return cntJOI;
}

int main(){
	int numofI=0;
	char tmp;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		switch(tmp){
			case 'J':
				ary[i]=0;
				break;
			case 'O':
				ary[i]=1;
				break;
			case 'I':
				ary[i]=2;
				numofI++;
				break;
		}
	}

	int lb=0,rb=numofI,mid,hog,piy,res=0;
	hog=0;
	for(int i=0;i<25;i++){
		mid=(lb+rb)/2;
		hog=joichec(mid,numofI-mid,piy);
		//cout<<"hog="<<hog<<" mid="<<mid<<" lb="<<lb<<" rb="<<rb<<endl;//debug
		if(numofI-mid-hog>0)lb=mid;
		else{
			rb=mid;
			res=max(res,hog);
		}
	}
	res=max(res,hog);
	/*
	cout<<hog<<endl;
	int hog=0,flaa;
	for(int i=0;i<=numofI;i++){
		hog=max(hog,joichec(i,numofI-i,flaa));
	}
	cout<<hog<<endl;
	*/
	cout<<res<<endl;
	return 0;
}