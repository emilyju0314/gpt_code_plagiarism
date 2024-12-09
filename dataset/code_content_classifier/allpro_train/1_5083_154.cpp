#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef vector<double> vec;

int N,K;
vec x(100),y(100),c(100);
bool b(double t){
    int rev=0;
    for(int i=0;i<N;i++){
        int include=0;
        for(int j=0;j<N;j++){
            if(j==i){
                include++;
                continue;
            }
            double d=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
            if(t/c[j]-t/c[i]>d) include++;
        }
        rev=max(rev,include);
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            double d=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
            double ri=t/c[i],rj=t/c[j];
            if(ri+rj<d) continue;
            vec v={(x[j]-x[i])/d,(y[j]-y[i])/d};
            vec w={(y[j]-y[i])/d,-(x[j]-x[i])/d};
            double X=(d+(ri*ri-rj*rj)/d)/2.0;
            double h=sqrt(ri*ri-X*X);
            int count=0;
            vec L={x[i]+X*v[0]+h*w[0],y[i]+X*v[1]+h*w[1]};
            for(int k=0;k<N;k++){
                if(k==i || k==j)count++;
                else if(sqrt((x[k]-L[0])*(x[k]-L[0])+(y[k]-L[1])*(y[k]-L[1]))<t/c[k])count++;
            }
            rev=max(rev,count);
            count=0;
            L={x[i]+X*v[0]-h*w[0],y[i]+X*v[1]-h*w[1]};
            for(int k=0;k<N;k++){
                if(k==i || k==j)count++;
                else if(sqrt((x[k]-L[0])*(x[k]-L[0])+(y[k]-L[1])*(y[k]-L[1]))<t/c[k])count++;
            }   
            rev=max(rev,count);         
        }
    }
    return rev>=K;
}
double BS(double l,double r){
    if(r-l<1.0e-10)return r;
    double m=(l+r)/2.0;
    if(b(m)) return BS(l,m);
    else     return BS(m,r);
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%lf %lf %lf",&x[i],&y[i],&c[i]);
    }
    printf("%.10lf\n",BS(0.0,1.0e10));
    return 0;
}