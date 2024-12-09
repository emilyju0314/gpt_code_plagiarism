#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;

// OÏ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð·»è
int is_intersected_ls(P a1, P a2, P b1, P b2) {
    // üªª½sÈêÍdÈÁÄ¢È¢±ÆÉ·é
    if(abs(cross(a2-a1,b2-b1)) < EPS){
        return 0;
    }
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð_vZ
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

struct edgeInfo{
    P a;
    P b;
    int o;
    int l;
};

P p1,p2;

class Point{
public:
    P p;
    int l;
    int o;
    int t;

    bool operator<(const Point &pp)const{
        double dist1=abs(p1-pp.p);
        double dist2=abs(p1-this->p);
        return dist2<dist1;
    }
};

int main(){
    int data;
    cin>>data;
    while(data--){
        int x,y;
        cin>>x>>y;
        p1=P(x,y);
        cin>>x>>y;
        p2=P(x,y);
        int n;
        cin>>n;
        vector<edgeInfo> edges;
        for(int i = 0; i < n; i++){
            int xs,ys,xt,yt,o,l;
            cin>>xs>>ys>>xt>>yt>>o>>l;
            edgeInfo e;
            e.a=P(xs,ys);
            e.b=P(xt,yt);
            e.l=l;
            e.o=o;
            edges.push_back(e);
        }
        vector<Point> crossPoint;
        // ð_ðßé
        for(int i = 0;i < n; i++){
            if(is_intersected_ls(edges[i].a,edges[i].b,p1,p2)){
                P res=intersection_ls(edges[i].a,edges[i].b,p1,p2);
                Point pp;
                pp.l=edges[i].l;
                pp.o=edges[i].o;
                pp.p=res;
                pp.t=pp.l^pp.o;
                crossPoint.push_back(pp);
            }
        }
        // ð_ðp1Éß¢ÔÉ\[g
        sort(crossPoint.begin(),crossPoint.end());

        if(crossPoint.size()==0){
            cout<<0<<endl;
            continue;
        }

        // »ÝÌ©ªÌHüîñ(1:nã,0:nº)
        int sit=0;
        sit=crossPoint[0].t;
        // ð_ðp1Éß¢ÔÉ
        int cnt=0;
        for(int i = 1; i < crossPoint.size(); i++){
            if(crossPoint[i].t!=sit){
                sit=crossPoint[i].t;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}