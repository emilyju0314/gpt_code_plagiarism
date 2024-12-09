#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
 
#define rep(i,x) for(int i=0;i<x;i++)
 
int main(){
	int bit[11][7]={
		{0,1,1,1,1,1,1},
		{0,0,0,0,1,1,0},
		{1,0,1,1,0,1,1},
		{1,0,0,1,1,1,1},
		{1,1,0,0,1,1,0},
		{1,1,0,1,1,0,1},
		{1,1,1,1,1,0,1},
		{0,1,0,0,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,0,1,1,1,1},
		{0,0,0,0,0,0,0}
	};
	while(1){
		int n;
		scanf("%d",&n); if(n==-1)break;
 
		int a=10;
		rep(i,n){
			int b;
			scanf("%d",&b);
 
			rep(j,7){
				printf("%d",(bit[a][j]+bit[b][j])&1);
			}
			printf("\n");
			a=b;
		}
	}
}