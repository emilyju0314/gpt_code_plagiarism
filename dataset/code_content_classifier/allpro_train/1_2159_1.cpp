#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int l;
long long base;
vector<long long> invaders;

void appearance() {
	invaders.push_back(l + base);
}

void move() {
	int d;
	scanf("%d", &d);

	base += d;

	vector<long long>::iterator en = upper_bound(invaders.begin(), invaders.end(), base);

	if(invaders.begin() != en) {
		printf("damage %d\n", (int)(en - invaders.begin()));
		invaders.erase(invaders.begin(), en);
	}
}

void rifle() {
	int k;
	scanf("%d", &k);

	if(invaders.size() >= k) {
		invaders.erase(invaders.begin() + (k - 1));
		puts("hit");
	}
	else
		puts("miss");
}

void grenade() {
	int r;
	long long x;
	scanf("%lld %d", &x, &r);

	x += base;
	vector<long long>::iterator it = lower_bound(invaders.begin(), invaders.end(), x - r);

	int cnt = 0;
	while(it != invaders.end() && *it <= x + r) {
		++cnt;
		it = invaders.erase(it);
	}

	printf("bomb %d\n", cnt);
}

void distance() {
	int k;
	scanf("%d", &k);

	if(invaders.size() >= k)
		printf("distance %lld\n", invaders[k - 1] - base);
	else
		printf("distance -1\n");
}

int main() {
	void (*operation[5])() = {&appearance, &move, &rifle, &grenade, &distance};

	for(int q; scanf("%d %d", &q, &l), q;) {
		base = 0;
		invaders.clear();

		for(int i = 0; i < q; ++i) {
			int in;
			scanf("%d", &in);
			(*operation[in])();
		}

		puts("end");
	}

	return EXIT_SUCCESS;
}