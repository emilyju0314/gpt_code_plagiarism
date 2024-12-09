#include <cstdio>
#include <vector>
using namespace std;

const int inf = (((1 << 30) - 1) << 1) + 1;

struct segtree1 {

	int *dat;
	
	void init(int *raw, int s)
	{
		dat = raw;
	
		for(int i = 0; i < s * 2; ++i)
			dat[i] = inf;
	}
	
	void set(int x, int v, int s)
	{
		int pos = s + x;
		
		dat[pos] = v;
		pos = pos / 2;
		
		while(pos > 0) {
		
			dat[pos] = min(dat[pos * 2 + 0], dat[pos * 2 + 1]);
			pos = pos / 2;
		}
	}
	
	void setmin(int x, int v, int s)
	{
		int pos = s + x;
		if(dat[pos] > v)
			set(x, v, s);
	}
	
	int getmin(int a, int b, int l, int r, int idx)
	{
		if(b <= l || r <= a) return inf;
		
		if(a <= l && r <= b) {
		
			return dat[idx];
		
		} else {
		
			int m = (l + r) / 2;
			int ret = inf;
			
			ret = min(ret, getmin(a, b, l, m, idx * 2 + 0));
			ret = min(ret, getmin(a, b, m, r, idx * 2 + 1));
		
			return ret;
		}
	}
	
	int getmin(int a, int b, int s)
	{
		return getmin(a, b, 0, s, 1);
	}
};

struct segtree2 {
	
	vector<segtree1> dat;
	vector<int> raw;
	int w, h;
	
	void init(int width, int height)
	{
		w = 1;
		while(w < width) w *= 2;
		
		h = 1;
		while(h < height) h *= 2;
		
		dat.resize(h * 2);
		raw.resize((h * 2) * (w * 2));
		for(int i = 0; i < h * 2; ++i)
			dat[i].init(&raw[i * (w * 2)], w);
	}
	
	void set(int x, int y, int v)
	{
		int pos = h + y;
		
		dat[pos].set(x, v, w);
		pos = pos / 2;
		
		while(pos > 0) {
		
			dat[pos].setmin(x, v, w);
			pos = pos / 2;
		}
	}
	
	int getmin(int ax, int ay, int bx, int by, int l, int r, int idx)
	{
		if(by <= l || r <= ay) return inf;
		
		if(ay <= l && r <= by) {
		
			//printf("[debug] getmin(%d, %d, %d, %d, %d, %d, %d) = %d\n", ax, ay, bx, by, l, r, idx, dat[idx].getmin(ax, bx));
			return dat[idx].getmin(ax, bx, w);
		
		} else {
		
			int m = (l + r) / 2;
			int ret = inf;
			
			ret = min(ret, getmin(ax, ay, bx, by, l, m, idx * 2 + 0));
			ret = min(ret, getmin(ax, ay, bx, by, m, r, idx * 2 + 1));
		
			//printf("[debug] getmin(%d, %d, %d, %d, %d, %d, %d) = %d\n", ax, ay, bx, by, l, r, idx, ret);
			return ret;
		}
	}
	
	int getmin(int ax, int ay, int bx, int by)
	{
		return getmin(ax, ay, bx, by, 0, h, 1);
	}
};


int main()
{
	while(true) {
	
		int r, c, q;
		segtree2 st;
		
		scanf("%d%d%d", &r, &c, &q);
		
		if(r == 0 && c == 0 && q == 0)
			break;
			
		st.init(r, c);
		
		for(int x = 0; x < r; ++x) {
			for(int y = 0; y < c; ++y) {
			
				int v;
				
				scanf("%d", &v);
				
				st.set(x, y, v);
			}
		}
		
		for(int i = 0; i < q; ++i) {
		
			int r1, c1, r2, c2;
			
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			
			int ans = st.getmin(r1, c1, r2 + 1, c2 + 1);
			
			printf("%d\n", ans);
		}
	}
	
	return 0;
}