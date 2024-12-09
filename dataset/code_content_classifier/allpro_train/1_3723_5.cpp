#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	double x,y,theta,omega;

	scanf("%lf %lf %lf %lf",&x,&y,&theta,&omega);

	double run_theta;
	double NUM = M_PI/180.0;

	if(x == 0){

		if(y > 0){

			run_theta = 90;

		}else{

			run_theta = 270;
		}
	}else if(y == 0){

		if(x > 0){

			run_theta = 0;

		}else{

			run_theta = 180;
		}

	}else{

		run_theta = (atan(fabs(y)/fabs(x)))/NUM;

		if(x < 0 && y > 0){

			run_theta = 180-run_theta;
		}else if(x < 0 && y < 0){

			run_theta = 180+run_theta;
		}else if(x > 0 && y < 0){

			run_theta = 360-run_theta;
		}
	}

	if(theta >= run_theta){

		theta = min(theta-run_theta,run_theta+(360-theta));

	}else{

		theta = min(run_theta-theta,theta+(360-run_theta));
	}

	double DIST = sqrt(x*x+y*y),pow_DIST = x*x+y*y;
	double left = 0,right = DIST*(omega/NUM),mid = (left+right)/2;
	double ans = 0;


	double run_time,snip_time;

	for(int loop = 0; loop < 100; loop++){

		run_time = sqrt(pow_DIST-mid*mid)/(mid*omega*NUM);
		snip_time = (theta+(acos(mid/DIST)/NUM))/omega;

		if(run_time > snip_time){

			ans = mid;
			left = mid;
		}else{

			right = mid;
		}
		mid = (left+right)/2;
	}

	printf("%.10lf\n",ans*(omega*NUM));

	return 0;
}

