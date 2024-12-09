#include <iostream>
#include <utility> 
using namespace std;
pair <int,int> p[5000005];
int a[200005];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int sum=a[i]+a[j];
			if (p[sum].first){
				if (p[sum].first!=i&&p[sum].second!=i&&p[sum].first!=j&&p[sum].second!=j){
					cout<<"YES"<<endl;
					cout<<i<<" "<<j<<" "<<p[sum].first<<" "<<p[sum].second<<endl;
					return 0;
				}
			}else{
				p[sum]=make_pair(i,j);
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

