#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 1e-10;
int m[3] = {0};

int is(double a){
	if(abs(a) < EPS)return 1;
	if(a < 0)return 0;
	if(a > 0)return 2;
}

double mysqrt(double x){
	double l = 0 , r = x;
	for(int i = 0 ; i < 64 ; i++){
		double m = (l+r) / 2.0;
		if(m * m < x) l = m;
		else r = m;
	}
	return l;
}

double solve(double a,double b,double c,double d){
	//cout << a << " " << b << " " << c << " " << d << endl;
	if(a == 0){
		if(c * c - 4 * b * d < -EPS)return 0.0;
		double one = ( -c + mysqrt(c*c-4*b*d)  )/(2*b);
		double two = ( -c - mysqrt(c*c-4*b*d)  )/(2*b);
		//cout << one << "<>" << two << endl;
		m[is(one)]++;
		m[is(two)]++;
		return 0.0;
	}
	
	double l = -1000.0 , r = 1000.0;
	
	if(a < 0){ a *= -1; b *= -1; c *= -1; d *= -1;}
	
	for(int i=0;i<64;i++){
		double x = (l+r)/2.0;
		double res = a*x*x*x+b*x*x+c*x+d;
		if(res>0){
			r = x;
		}else{
			l = x;
		}
	}
	
	return l;
}
int main(){
	int N; cin >> N;
	while(N--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		m[0] = m[1] = m[2] = 0;
		
		double n = solve(a,b,c,d); // 三次方程式には必ず一つ以上実根が含まれているので、それを見つける。
		m[is(n)]++;
		
		solve(0,a,a*n+b,n*(a*n+b)+c);
		cout << m[2] << " " << m[0] << endl;
	}
}
