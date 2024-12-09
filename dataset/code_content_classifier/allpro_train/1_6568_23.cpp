/*
	2次元座標平面上に複数の点を配置した入力データを配置した入力データをいくつか生成した。
	このデータは、K個以上の点が同じ直線上にあってはならない。あなたは、作成した入力データがこの条件
	を満たしているかチェックすることにした。直線上に存在する場合があるか判定するプログラム。
	入力
	入力は以下の形式で与えられる。
	N K
	x1 y1
	x2 y2
	...
	xN yN
	１行目に座標平面上の点の数N(3≤N≤3000)と整数K(3≤K≤N)が与えられる。続くN行に、点の座標
	xi,yi(0≤xi,yi≤10000)が整数で与えられる。ただし、同じ座標をもつ点は与えられない(i≠jについて、
	xi≠xjまたはyi≠yj）。
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
#define N_MAX 3000						//N_MAX→3000
//classとは、メンバとして変数のほかに関数を持つことが出来る。
class Point{
//メンバ関数を定義する（Javaでいうメソッド）
public:
	//x,yの変数を使えるようにする
	int x,y;
};
int N,K;
Point P[N_MAX];
Point T[N_MAX];
bool compX(const Point &p1,const Point &p2){
	if(p1.x==p2.x)return p1.y<p2.y;
	return p1.x<p2.x;
}
bool compA(const Point &p1,const Point &p2){
	return p2.x*p1.y<p1.x*p2.y;
}
bool eq(const Point &p1,const Point &p2){
	return p2.x*p1.y==p1.x*p2.y;
}
int check(int p,int M){
	sort(T,T+M,compA);
	int maxl=1;
	int l=1;
	Point pre=T[0];
	for(int i=1;i<M;i++){
		if(eq(pre,T[i]))
		{
			l++;
			maxl=max(maxl,l);
		}else{
		l=1;
		}
		pre=T[i];
	}
	return maxl;
}
bool solve(){
	for(int i=0;i<N;i++){
		int k=0;
		int v=0;
		for(int j=i+1;j<N;j++){
			if(P[i].x==P[j].x)
			{
				v++;
			}else{
				T[k]=P[j];
				T[k].x-=P[i].x;
				T[k].y-=P[i].y;
				k++;
			}
		}
		if(1+v>=K)return true;
		if(1+check(i,k)>=K)return true;
	}
	return false;
}
int main(){
	//座標平面上の点の数Nと個数の制限Kこを定める
	cin>>N>>K;
	//それぞれの座標点を定める
	for(int i=0;i<N;i++)cin>>P[i].x>>P[i].y;
	sort(P,P+N,compX);
	/*----------------------*/
		for(int i=0;i<N;i++){
			//cout<<"P["<<i<<"].y="<<P[i].y<<"  .x="<<P[i].x<<endl;
		}
	/*----------------------*/
	cout<<solve()<<endl;
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ull;
#define BIG_NUM 200000000
#define NUM 3005; 
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
//struct 構造体、いくつかの変数をまとめることが出来る
struct Point{
	int x,y
};
struct Info{
	Info(double arg_slope,double arg_segment){
		slope=arg_slope;
		segment=arg_segment;
	}
	bool operator<(const struct Info &arg)const{
		if(fabs(slope-arg.slope)>EPS){
			return slope<arg.slope;
		}else{
			return segment<arg.segment;
		}
	}
	double slope.segment;
};
int N,K;
int table[10005];
Point point[NUM];
vector<Info> V;
int main(){
	for(int i=0;i<=10000;i++){
		table[i]=0;
	}
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>point[i].x>>point[i].y;
	}
	int maximum=0;
	int need_num=(K*(K-1))/2;
	double tmp_slope,tmp_segement;
	for(int i=0;i<N-1;i++){
		for(int k=i+1;k<N;k++){
			if(point[k].x==point[i].x){
				table[point[k].x]++;
				maximum=max(maximum,table[point[k].x]);
			}
			else
			{
				tmp_slope=(double)(point[k].y-point[i].y)/(double)(point[k].x-point[i].x);
				tmp_segment=(double)point[k].y-tmp_slope*(double)point[k].x;
				V.push_back(Info(tmp_slope,tmp_segement));
			}
		}
	}
	if(maximum>=need_num){
		printf("1\n");
		return 0;
	}
	sort(V.begin(),V.end());
	int limit=(int)V.size();
	for(int i=0;i+nedd_num<=limit;i++){
		if(fabs(V[i+need_num-1].slope-V[i].slope)<EPS&&fabs(V[i+need_num-1].segment)<EPS){
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}*/
