#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std ;

long long a0 ;
long long t1[255] ;
long long t2[320000] ;

bool cmp(long long a,long long b){
	return a < b ;
}

long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

int main(){
	long long n ;
	long long i , j , k ;
	long long top1 ;
	long long top2 ;
	while(scanf("%lld",&n)!=EOF){
		if(n == 0)
			break ;
		top1 = 0 ;
		top2 = 0 ;
		for(i = 0 ; i <= (n*(n+1)/2-1) ; i++){
			long long c ;
			scanf("%lld",&c) ;
			if(c%2)
				t2[top2++] = c ;
			else
				t1[top1++] = c ;
		}
		sort(t1,t1+top1,cmp) ;
		sort(t2,t2+top2,cmp) ;
		long long t = gcd(t1[0],t1[1]) ;
		long long g1 = t1[0] / t ;
		long long g2 = t1[1] / t ;
		long long q = (long long)sqrt(t2[0]/(g1*g2)*1.0) ;
		a0 = t / q ;
		printf("%lld\n",a0) ;
		for(i = 0 ; i < n ; i++){
			if(i == 0){
				printf("%lld",t1[i] / a0) ;
			}
			else
				printf(" %lld",t1[i] / a0) ;
		}
		puts("") ;
	}
	return 0 ;
}