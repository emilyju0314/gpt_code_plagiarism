#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

class P3 {
public:
	double x, y, z;
	P3(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}
	P3(const P3& p) : x(p.x), y(p.y), z(p.z) {}
	void set(const P3& p){ x = p.x, y = p.y, z = p.z; }
	void set(double px, double py, double pz){ x = px, y = py, z = pz; }
	P3 operator + (const P3 &p) const { return P3(x+p.x, y+p.y, z+p.z); }
	P3 operator - (const P3 &p) const { return P3(x-p.x, y-p.y, z-p.z); }
	P3 operator * (double p) const { return P3(x*p, y*p, z*p); }
	void add(const P3& p){ x += p.x, y += p.y, z += p.z; }
	void sub(const P3& p){ x -= p.x, y -= p.y, z -= p.z; }
	void scale(double s){ x *= s, y *= s, z *= s; }
	double dot(const P3& p) const { return x*p.x + y*p.y + z*p.z; }
	double squaredLength() const { return x*x + y*y + z*z; }
	double length() const { return sqrt(squaredLength()); }
	double normalize(){ double L = length(); if(L>0) scale(1.0/L); return L; }
};

int main(){
	int N;
	while(cin >> N && N){
		P3 pos(0, 0, 0), dir;
		cin >> dir.x >> dir.y >> dir.z;
		dir.normalize();
		vector< pair<P3, double> > vp(N);
		for(int i=0;i<N;i++){
			cin >> vp[i].first.x >> vp[i].first.y >> vp[i].first.z >> vp[i].second;
		}
		while(true){
			bool end = true;
			double nearest = 1e12;
			P3 npos, ndir;
			for(int i=0;i<N;i++){
				P3 p(vp[i].first);
				p.sub(pos);
				double l = dir.dot(p);
				p.sub(dir*l);
				double dist = p.length();
				if(dist > vp[i].second - 1e-8) continue;
				double sub = sqrt(vp[i].second*vp[i].second - dist*dist);
				if(l-sub > 0 && nearest > l-sub){
					nearest = l-sub;
					npos.set(pos);
					npos.add(dir*(l-sub));
					ndir.set(dir);
					ndir.scale(-1);
					P3 ref(npos-vp[i].first);
					ref.normalize();
					P3 add(ndir);
					ref.scale(ndir.dot(ref));
					add.sub(ref);
					add.scale(-2.0);
					ndir.add(add);
					end = false;
				}
			}
			if(end) break;
			pos.set(npos);
			dir.set(ndir);
		}
		printf("%.8lf %.8lf %.8lf\n", pos.x, pos.y, pos.z);
	}
}