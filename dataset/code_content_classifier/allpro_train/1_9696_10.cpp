#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstring>

using namespace std;

const double EPS=(1e-10);
bool EQ(double a,double b){
    return abs(a-b)<EPS;
}

typedef complex<double> P;
typedef pair<double,double> pdd;

double calc(double a1,double b1,double a2,double b2,double x,double r){
    return (a2*a1*x*x*x)/3.0+(x*x*(a1*a2*r+b2*a1+a2*b1))/2.0+(a2*b1*r+b1*b2)*x;
}

int main(){
    int n;
    double r;
    while(cin>>n>>r&&!(n==0&&EQ(r,0))){
        vector<P> dots;
        vector<pdd> co;
        dots.push_back(P(-1000,0));
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            dots.push_back(P(x,y));
        }
        dots.push_back(P(1000,0));
        double sum=0;
        for(int i=1;i<=n+1;i++){
            double a=(dots[i-1].imag()-dots[i].imag())/(dots[i-1].real()-dots[i].real());
            double b=dots[i-1].imag()-a*dots[i-1].real();
            co.push_back(pdd(a,b));
        }
        double ax=dots[1].real();
        double bx=ax+r;
        int nxtApos=n+2;
        int nxtBpos=n+2;
        // rツづ個値ツつェツづづ個凝ヲツ甘板づ可甘慊づ慊づェツづつ「ツづゥツつゥツづーツ探ツ催オ
        for(int i=0;i<=n+1;i++){
            if(dots[i].real()>bx&&!EQ(dots[i].real(),bx)){
                nxtBpos=i;
                break;
            }
        }
        for(int i=0;i<=n+1;i++){
            if(dots[i].real()>ax&&!EQ(dots[i].real(),ax)){
                nxtApos=i;
                break;
            }
        }
        //bool rev=false;
        //if(ax>bx){
        //    swap(ax,bx);
        //    swap(nxtApos,nxtBpos);
        //    rev=true;
        //}
        // nxtBposツつェnツづ可づ按づゥツづ慊づ堕アツつッツづゥ
        while(nxtBpos!=n+2&&nxtApos!=n+2){
            // ツ篠淞づ個湘ェツ渉環づ鳴づ個仰猟猟」ツつェツ渉ャツつウツつ「ツづ個づ債づつソツづァツつゥ
            double adis=dots[nxtApos].real()-ax;
            double bdis=dots[nxtBpos].real()-bx;
            double dis=min(adis,bdis);
            double t=ax+dis;
            double s=ax;
            sum+=calc(co[nxtApos-1].first,co[nxtApos-1].second,co[nxtBpos-1].first,co[nxtBpos-1].second,t,r);
            sum-=calc(co[nxtApos-1].first,co[nxtApos-1].second,co[nxtBpos-1].first,co[nxtBpos-1].second,s,r);
            //if(rev){
            //    t=bx+dis;
            //    s=bx;
            //    sum+=calc(co[nxtBpos-1].first,co[nxtBpos-1].second,co[nxtApos-1].first,co[nxtApos-1].second,t,r);
            //    sum-=calc(co[nxtBpos-1].first,co[nxtBpos-1].second,co[nxtApos-1].first,co[nxtApos-1].second,s,r);
            //}
            //else{
            //    sum+=calc(co[nxtApos-1].first,co[nxtApos-1].second,co[nxtBpos-1].first,co[nxtBpos-1].second,t,r);
            //    sum-=calc(co[nxtApos-1].first,co[nxtApos-1].second,co[nxtBpos-1].first,co[nxtBpos-1].second,s,r);
            //}
            ax+=dis;bx+=dis;
            if(EQ(adis,bdis)){
                nxtApos++;
                nxtBpos++;
            }
            else if(adis<bdis)nxtApos++;
            else nxtBpos++;
        }
        printf("%.10f\n",sum);
    }
    return 0;
}