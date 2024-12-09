#include<iostream>
#include<cmath>
#include<stdio.h>

#define PI 3.141592654
#define DEG_TO_RAD(theta) degToRad(theta)
#define RAD_TO_DEG(theta) radToDeg(theta)

struct point{
	double x;
	double y;
};

double degToRad( double theta )
{
	return PI/180.0 * theta;
}

double radToDeg( double theta )
{
	return 180.0/PI * theta;
}

int main(void)
{
	int n;
	double theta;
	point p;

	while(1){
		p.x = 1.0;
		p.y = 0.0;
		theta = 0.0;

		std::cin >> n;
		if( n == -1 ){
			break;
		}
		if( n < 2 || n > 1000 ){
			continue;
		}
		for( int i = 0 ; i < n-1 ; i++ ){
			theta += 90;
			p.x += cos( DEG_TO_RAD(theta) );
			p.y += sin( DEG_TO_RAD(theta) );
			theta = RAD_TO_DEG( atan( p.y/p.x ) );
			if( p.x <= 0 && p.y >= 0 ){
				theta += 180.0;
			}
			else if( p.x <= 0 && p.y <= 0 ){
				theta += 180.0;
			}
			else if( p.x >= 0 && p.y <= 0 ){
				theta += 360.0;
			}
		}
		printf( "%.2f\n%.2f\n", p.x, p.y );
	}

	return 0;
}