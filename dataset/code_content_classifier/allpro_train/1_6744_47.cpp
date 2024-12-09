#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(){
	int n;
	int in[1000], out[1000], sum[1000];
	while(cin >> n, n){
		string day, time; char e; int p;
		memset(in,  0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(sum, 0, sizeof(sum));
		string prevDay = "";
		for(int i=0;i<n;i++){
			cin >> day >> time >> e >> p;
			if(day != prevDay){
				memset(in,  0, sizeof(in));
				memset(out, 0, sizeof(out));
				prevDay = day;
			}
			int h, m;
			sscanf(time.c_str(), "%02d:%02d", &h, &m);
			int t = h*60+m;
			if(e == 'I'){
				in[p] = t;
				out[p] = 1000000;
			} else {
				if(p==0){
					out[0] = t;
					for(int i=1;i<1000;i++){
						if(out[i]==1000000){
							sum[i] += max(0, out[0] - max(in[i], in[0]));
							in[i] = t;
						}
					}
				} else {
					out[p] = t;
					sum[p] += max(0, min(out[p], out[0]) - max(in[p], in[0]));
				}
			}
		}
		int res = 0;
		for(int i=1;i<1000;i++) res = max(res, sum[i]);
		cout << res << endl;
	}
}