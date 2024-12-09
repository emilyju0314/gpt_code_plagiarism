#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;
typedef long long ll;

/**
 * Link-Cut Tree
 *
 * ????????¨????????????link???cut???evert???parent, root???????£???????
 * ?????????????????????????????´??????????????????
 */
struct LCNode {
	using NP = LCNode*;

	ll tsz, tszsm;
	ll tsm;
	ll d;
	ll dsm;
	ll lsm, rsm;
	LCNode() {}
	LCNode(int d) : p(nullptr), l(nullptr), r(nullptr), sz(1), rev(false) {
		tsz = 0;
		tszsm = 0;
		tsm = 0;
		this->d = d;
		dsm = d;
		lsm = rsm = 0;
	}

	void update() {
		int lsz = (l) ? l->sz : 0, rsz = (r) ? r->sz : 0;
		sz = 1;
		tszsm = tsz;
		dsm = d;
		if (lsz) {
			dsm += l->dsm;
			sz += lsz;
			tszsm += l->tszsm;
		}
		if (rsz) {
			dsm += r->dsm;
			sz += rsz;
			tszsm += r->tszsm;
		}
		ll ldsm = (l) ? l->dsm : 0;
		ll llsm = (l) ? l->lsm : 0;
		ll lrsm = (l) ? l->rsm : 0;
		ll ltszsm = (l) ? l->tszsm : 0;
		ll rdsm = (r) ? r->dsm : 0;
		ll rlsm = (r) ? r->lsm : 0;
		ll rrsm = (r) ? r->rsm : 0;
		ll rtszsm = (r) ? r->tszsm : 0;
		lsm = llsm + ldsm * tsz + tsm + (ldsm + d) * rtszsm + rlsm;
		rsm = rrsm + rdsm * tsz + tsm + (rdsm + d) * ltszsm + lrsm;
	}
	void cngchsz(int x) {
		tsz += x;
		tszsm += x;
	}
	void addch(NP b) {
		assert(!b || b->p == this);
		if (b) {
			cngchsz(b->tszsm);
			tsm += b->lsm + (d) * b->tszsm;
//			assert(!d);
		}
	}
	void delch(NP b) {
		assert(!b || b->p == this);
		if (b) {
			cngchsz(-b->tszsm);
			tsm -= b->lsm + (d) * b->tszsm;
//			assert(!d);
		}
	}
	void push() {
		int lsz = (l) ? l->sz : 0, rsz = (r) ? r->sz : 0;
		if (rev) {
			if (lsz) {
				l->revdata();
			}
			if (rsz) {
				r->revdata();
			}
			rev = false;
		}
	}
	void revdata() {
		swap(l, r);
		swap(lsm, rsm);
		rev ^= true;
	}

	//????????????
	NP p, l, r;
	int sz;
	bool rev;
	inline int pos() {
		if (p) {
			if (p->l == this) return -1;
			if (p->r == this) return 1;
		}
		return 0;
	}
	void rot() {
		NP q = p->p;
		int pps = p->pos();
		if (pps == -1) {
			q->l = this;
		}
		if (pps == 1) {
			q->r = this;
		}
		if (p->l == this) {
			p->l = r;
			if (r) r->p = p;
			r = p;
		} else {
			p->r = l;
			if (l) l->p = p;
			l = p;
		}
		p->p = this;
		p->update();
		update();
		p = q;
		if (q) q->update();
	}
	void splay() {
		supush();
		int ps;
		while ((ps = pos())) {
			int pps = p->pos();
			if (!pps) {
				rot();
			} else if (ps == pps) {
				p->rot(); rot();
			} else {
				rot(); rot();
			}
		}
	}
	void expose() {
		for (NP u = this; u; u = u->p) {
			u->splay();
		}
		for (NP u = this, ur = nullptr; u; u = u->p) {
			NP tmp = u->r;
			u->r = nullptr;
			u->update();
			u->addch(tmp);
			u->delch(ur);
			u->r = ur;
			u->update();
			ur = u;
		}
		splay();
	}
	void supush() {
		if (pos()) {
			p->supush();
		}
		push();
	}
	//???????????§?????¶?????????

	void link(NP r) {
		expose();
		r->expose();
		p = r;
		r->addch(this);
	}

	NP parent() {
		expose();
		NP u = this->l;
		if (!u) return nullptr;
		u->push();
		while (u->r) {
			u = u->r;
			u->push();
		}
		u->expose();
		return u;
	}

	void cut() {
		NP u = parent();
		assert(u);
		assert(!u->r);
		u->delch(this);
		this->p = nullptr;
	}

	NP root() {
		expose();
		NP u = this;
		while (u->l) {
			u = u->l;
			u->push();
		}
		u->expose();
		return u;
	}

	void evert() {
		expose();
		revdata();
	}

	NP lca(NP n) {
		n->expose();
		expose();
		NP t = n;
		while (n->p != nullptr) {
			if (!n->pos()) t = n->p;
			n = n->p;
		}
		return (this == n) ? t : nullptr;
	}

	NP get(int x) {
		push();
		int rszsm = (r) ? r->tszsm : 0;
		if (r && x <= rszsm) return r->get(x);
		if (x <= tsz + rszsm) {
			splay();
			return this;
		}
		if (l) return l->get(x - (tsz + rszsm));
		return nullptr;
	}
};

const int MN = 200200;

LCNode tr[MN], et[MN];
int p[MN];
int main2() {
	int n;
	scanf("%d", &n);
	tr[0] = LCNode(0);
	for (int i = 1; i < n; i++) {
		int d;
		scanf("%d %d", p+i, &d); p[i]--;
		tr[i] = LCNode(0);
		et[i] = LCNode(d);
	}
	for (int i = 1; i < n; i++) {
		tr[i].link(et + i);
		et[i].link(tr + p[i]);
	}

	int sp = 0;
	printf("%d\n", 0);
	tr[0].expose();
	tr[0].cngchsz(1);
	for (int i = 1; i < n; i++) {
		tr[i].evert();
		tr[i].expose();
		tr[i].cngchsz(1);
		tr[sp].expose();
		sp = tr[sp].get(i/2+1) - tr;
		tr[sp].evert();
		tr[sp].expose();
		printf("%lld\n", tr[sp].lsm);
	}
	return 0;
}


/*AOJ??¨ stack size???????????????*/
int main() {
    static ll eord, enew;
    const int sz = 256*1024*1024;
    static void *p = malloc(sz);
    enew = (long long)p + sz - 32;
    __asm__ volatile("mov %%rsp, %0" : "=r"(eord));
    __asm__ volatile("mov %0, %%rsp" : : "r"(enew));
    main2();
    __asm__ volatile("mov %0, %%rsp" : : "r"(eord));
    return 0;
}