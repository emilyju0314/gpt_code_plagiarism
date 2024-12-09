#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

#define _I(i, j) (i*w+j)

int main(){
	int h, w, k;
	cin>>h>>w>>k;
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	x1--; y1--; x2--; y2--;
	char c[1000000];
	rep(i, h) rep(j, w) cin>>c[_I(i, j)];

	int dx[]={0, 0, 1, -1};
	int dy[]={1, -1, 0, 0};

	bool mita[1000000]={0};

	queue<int> q, nq;
	q.emplace(_I(x1, y1));
	mita[_I(x1, y1)]=true;
	unordered_map<int, bool> nmita;
	int cnt=0;
	while(!q.empty()){
		cnt++;
		while(!q.empty()){
			int tx=q.front()/w, ty=q.front()%w;
			q.pop();

			rep(r, 4){
				for(int s=1; s<=k; s++){
					int x=tx+dx[r]*s, y=ty+dy[r]*s;
					if(x==x2 && y==y2){
						cout<<cnt<<endl;
						return 0;
					}

					if(x>=0 && x<h && y>=0 && y<w && 
						c[_I(x, y)]!='@' && !mita[_I(x, y)]){
							if(!nmita[_I(x, y)]){
								nmita[_I(x, y)]=true;
								nq.emplace(_I(x, y));
							}
					}
					else break;
				}
			}

		}
		repit(it, nmita){
			mita[it->first]=true;
		}
		nmita.clear();
		auto tmp=q; q=nq; nq=tmp;
	}

	cout << (-1) << endl;
	return 0;
}
