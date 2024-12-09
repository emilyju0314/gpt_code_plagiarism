#include <cstdio>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

const double eps=1e-10;
const double PI=acos(-1);
struct Point
{
    double x,y;
    Point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    Point()
    {
        x=0;
        y=0;
    }
};
typedef Point Vector;
Vector operator+(Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
Vector operator*(double p,Vector A)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(double p,Vector A)
{
    return Vector(A.x/p,A.y/p);
}
bool operator<(const Point& a,const Point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int dcmp(double x)
{
    if(fabs(x)<eps)
    {
        return 0;
    }
    else
    return x<0?-1:1;
}
bool operator==(const Point& a,const Point& b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector a,Vector b)
{
    //?算点?
    return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
    //?算叉?
    return a.x*b.y-a.y*b.x;
}
double Length(Vector a)
{
    //?算?度
    return sqrt(Dot(a,a));
}
double Angle(Vector A,Vector B)
{
    //?算AB?角
    return acos(Dot(A,B)/Length(A)/Length(B));
}
double Area2(Point A,Point B,Point C)
{
    //?算三角形ABC的面?的二倍
    return Cross(B-A,C-A);
}
Vector Rotate(Vector a,double rad)
{
    //向量逆??旋?rad角
    //rad弧度
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector Normal(Vector a)
{
    //?算向量的?位法?，即左?90度，?度?一化。
    //用前?保A不是零向量
    double l=Length(a);
    return Vector(-a.y/l,a.x/l);
}
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    //求解直?P+t*v  Q+t*w 的交点
    //用前?保?条直?有唯一交点
    //当且?当cross(v,w)!=0
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}
double DistanceToLine(Point p,Point a,Point b)
{
    //?算点P到直?AB距?
    Point v1=b-a;
    Point v2=p-a;
    return fabs(Cross(v1,v2))/Length(v1);
    //如果不取???，得的是有向距?
}
double DistanceToSegment(Point p,Point a,Point b)
{
    //?算点P到?段AB距?
    if(a==b)
    {
        return Length(p-a);
    }
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0)
    {
        return Length(v2);
    }
    else
    if(dcmp(Dot(v1,v3))>0)
    {
        return Length(v3);
    }
    else
    {
        return fabs(Cross(v1,v2))/Length(v1);
    }
}
Point GetLineProjection(Point p,Point a,Point b)
{
    //求点在直?上投影
    //AB直?:A+tv , 投影Q的参数? t0
    //由 Dot(v,P-(A+t0*v))==0 得出
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    //?段相交判定
    double c1=Cross(a2-a1,b1-a1);
    double c2=Cross(a2-a1,b2-a1);
    double c3=Cross(b2-b1,a1-b1);
    double c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point p,Point a1,Point a2)
{
    //判断一个点在?段上
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}
double ConvexPolygonArea(Point* p,int n)
{
    //从第一个?点出?把凸多?形分成 n-2 个三角形
    double area=0;
    for(int i=1;i<n-1;i++)
    {
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}

Point p[11];

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        double w, h, r;
        double vx, vy;
        scanf("%lf %lf %lf %lf %lf", &w, &h, &r, &vx, &vy);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            p[i].x -= r;
            p[i].y -= r;
        }
        w -= r * 2;
        h -= r * 2;
        int dx = 1;
        int dy = 1;
        if (vx < 0)
        {
            dx = -1;
            vx = -vx;
        }
        if (vy < 0)
        {
            dy = -1;
            vy = - vy;
        }
        double len = 0;
        bool flag = false;
        while (len <= 10000 && !flag)
        {
            double& x = p[0].x;
            double& y = p[0].y;
            if (dx == 1 && dy == 1)
            {
                if ((w - x) * vy < (h - y) * vx)
                {
                    Point t(w, (w - x) / vx * vy + y);
                    dx = -dx;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = (len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = (len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
                else
                {
                    Point t((h - y) / vy * vx + x, h);
                    dy = -dy;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = (len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = (len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
            }
            else if (dx == -1 && dy == 1)
            {
                if (x * vy < (h - y) * vx)
                {
                    Point t(0, x / vx * vy + y);
                    dx = -dx;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = -(len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = (len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
                else
                {
                    Point t(-(h - y) / vy * vx + x, h);
                    dy = -dy;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = -(len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = (len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
            }
            else if (dx == 1 && dy == -1)
            {
                if ((w - x) * vy < y * vx)
                {
                    Point t(w, -(w - x) / vx * vy + y);
                    dx = -dx;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = (len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = -(len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
                else
                {
                    Point t(y / vy * vx + x, 0);
                    dy = -dy;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = (len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = -(len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
            }
            else
            {
                if (x * vy < y * vx)
                {
                    Point t(0, -x / vx * vy + y);
                    dx = -dx;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = -(len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = -(len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
                else
                {
                    Point t(-y / vy * vx + x, 0);
                    dy = -dy;
                    len += Length(t - p[0]);
                    if (len > 10000)
                    {
                        double tx = -(len - 10000) / Length(Vector(vx, vy)) * vx;
                        double ty = -(len - 10000) / Length(Vector(vx, vy)) * vy;
                        t = t - Point(tx, ty);
                    }
                    vector<pair<double, int> > dd;
                    for (int i = 1; i < n; ++i)
                    {
                        double l = DistanceToSegment(p[i], p[0], t);
                        if (l < 2 * r)
                        {
                            dd.push_back(make_pair(sqrt(Length(p[i] - p[0]) * Length(p[i] - p[0]) - l * l) -
                                         sqrt(4 * r * r - l * l), i));
                        }
                    }
                    if (dd.size() > 0)
                    {
                        sort(dd.begin(), dd.end());
                        printf("%d\n", dd[0].second + 1);
                        flag = true;
                    }
                    p[0] = t;
                }
            }
        }
        if (!flag)
        {
            printf("-1\n");
        }
    }
}