#include<bits/stdc++.h>
using namespace std;

void printTHS(int sec){
	int T = sec/3600;
	int H = sec/60%60;
	int S = sec%60;
	printf("%02d:%02d:%02d\n",T,H,S);
}

int main(){
	while(true){
		// 時、分、秒
		int T ,H ,S;
		cin >>T>>H>>S;
		
		// T, H, S がすべて -1 のとき入力の終わりとします。
		if(T==-1){
			break;
		}
		
		int sec = 120*60 - (T*3600+H*60+S);
		
		printTHS(sec);
		
		printTHS(sec*3);
	}
}
