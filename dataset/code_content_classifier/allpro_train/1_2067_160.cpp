#include <cstdio>
#include <algorithm>
using namespace std;
int n;
pair<int,int>p[3005];
int P[3005];
int main(){
	while(1){
	scanf("%d",&n);
	if(!n) break;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		P[i]=a;
		p[i]=make_pair(a,b);
	}
	sort(p,p+n);
	sort(P,P+n);
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int a,b,c,d;
			a=p[i].first;
			b=p[i].second;
			c=p[j].first;
			d=p[j].second;
			if(ans>=(a-c)*(a-c)+(b-d)*(b-d)){
				continue;
			}
			int ro1=lower_bound(P,P+n,a+b-d)-P;
			int rp1=lower_bound(P,P+n,c+b-d)-P;
			int wo1=lower_bound(P,P+n,a-b+d)-P;
			int wp1=lower_bound(P,P+n,c-b+d)-P;
			int ro2=upper_bound(P,P+n,a+b-d)-P;
			int rp2=upper_bound(P,P+n,c+b-d)-P;
			int wo2=upper_bound(P,P+n,a-b+d)-P;
			int wp2=upper_bound(P,P+n,c-b+d)-P;
			bool aa=false,bb=false,cc=false,dd=false;
			for(int k=ro1;k<ro2;k++){
				if(p[k].second==b+c-a){
					aa=true;
					break;
				}
			}
			for(int k=rp1;k<rp2;k++){
				if(p[k].second==d+c-a){
					bb=true;
					break;
				}
			}
			for(int k=wo1;k<wo2;k++){
				if(p[k].second==b-c+a){
					cc=true;
					break;
				}
			}
			for(int k=wp1;k<wp2;k++){
				if(p[k].second==d-c+a){
					dd=true;
					break;
				}
			}
			if((aa&&bb)||(cc&&dd)){
				ans=max(ans,(a-c)*(a-c)+(b-d)*(b-d));
			}
		}
	}
	printf("%d\n",ans);
}
	return 0;
}