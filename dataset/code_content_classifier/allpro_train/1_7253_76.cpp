#include<iostream>
using namespace std;
#define abs(x) ((x>0)?x:(-(x)))

int px[900001],py[900001];
int d[900001];

int main(){
	int h,w,D; cin >> h >> w >> D;
	int a;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> a;
			px[a]=i;
			py[a]=j;
		}
	}
	for(int i=D+1;i<=h*w;i++)
		d[i]=d[i-D]+abs(px[i]-px[i-D])+abs(py[i]-py[i-D]);
	int q; cin >> q;
	int l,r;
	for(int i=0;i<q;i++){
		cin >> l >> r;
		cout << d[r]-d[l] << endl;
	}
}
