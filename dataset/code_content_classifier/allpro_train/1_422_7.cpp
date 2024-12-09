#include <iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

double f(double a,double p,double q,double x) {
    return a*(x-p)*(x-p)+q;
}

double f(double a, double p, double x) {
    return sqrt(1.0 + 4.0*a*a*x*x - 8.0*a*a*p*x + 4.0*a*a*p*p);
}

double s(double a, double p, double x1, double x2){
    double N = 1000.0;
    double h = (x2 - x1)/ N, p1=0.0, p2=0.0;
    for(int n = 1; n <= N/2-1; n++){
        p1 += f(a, p, x1+2.0*n*h);
    }
    for(int n = 1; n <= N/2; n++){
        p2 += f(a, p, x1+2.0*n*h-h);
    }
    p = f(a, p, x1) + 2.0*p1 + 4.0*p2 + f(a, p, x2);
    return p*h/3.0;
}

int main(){
    int W,H,n; 
    double a[50],p[50],q[50];
    cin >> W >> H >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i] >> p[i] >> q[i];
    }
    vector<double> X; //動的配列クラス
    X.push_back(0);//末尾に0を挿入
    X.push_back(W);//末尾にWを挿入
   for(int i=0; i<n; i++){
       // 山 i と窓枠の下辺との交点
       if(0<=p[i]-sqrt(-(q[i]/a[i])) && p[i]-sqrt(-(q[i]/a[i]))<=W) {
           X.push_back(p[i]-sqrt(-(q[i]/a[i]))); //枠内ならx1を末尾に挿入
       }
       if(0<=p[i]+sqrt(-(q[i]/a[i])) && p[i]+sqrt(-(q[i]/a[i]))<=W) {
           X.push_back(p[i]+sqrt(-(q[i]/a[i]))); //枠内ならx2を末尾に挿入
       }
       for(int j=0; j<i; j++){ // 山 i と山 j の交点
           double A=a[i]-a[j];
           double B=-2*a[i]*p[i]+2*a[j]*p[j];
           double C=a[i]*p[i]*p[i]+q[i]-a[j]*p[j]*p[j]-q[j];

           if(A!=0){ // Ax^2+Bx+C=0
               if(B*B-4*A*C>=0){
                   double x;
                   x=(-B-sqrt(B*B-4*A*C))/(2*A);
                   if(0<=x && x<=W) X.push_back(x);//枠内なら交点を末尾に挿入
                   x=(-B+sqrt(B*B-4*A*C))/(2*A);
                   if(0<=x && x<=W) X.push_back(x);//枠内なら交点を末尾に挿入
               }
           }
           else if(B!=0){ // Bx+C=0
               double x=-1.0*C/B;
               if(0<=x && x<=W) X.push_back(x);//枠内なら交点を末尾に挿入
           }
       }
   }

   sort(X.begin(),X.end()); //昇順でソートする

   double ans=0;
   for(int i=0; i<(int)X.size()-1; i++){
       double x1=X[i],x2=X[i+1];

       int jmax=-1;
       for(int j=0; j<n; j++){
           if(f(a[j],p[j],q[j],(x1+x2)/2)>0//ｙ＝０より上
           && (jmax==-1 || f(a[jmax],p[jmax],q[jmax],(x1+x2)/2)<f(a[j],p[j],q[j],(x1+x2)/2))){//それまでで一番高い位置にある関数＜ｊ個目の関数のとき交換
               jmax=j;
           }
       }

       if(jmax != -1)ans+=s(a[jmax], p[jmax], x1, x2);
       
   }

   cout << fixed;
   cout << setprecision(9) << ans << endl;

   return 0;
}
