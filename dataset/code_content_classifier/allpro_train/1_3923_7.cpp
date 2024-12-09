#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N	2048
#define INF	0x3f3f3f3f3f3f3f3fLL
#define X	10000000

long long min(long long a, long long b) { return a < b ? a : b; }

unsigned int Z;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}

int rand_() {
	return (Z *= 3) >> 1;
}

int xx[N * 2], yy[N * 2];

void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;

		while (j < k) {
			int c = yy[ii[j]] != yy[i_] ? yy[ii[j]] - yy[i_] : (i_ & 1) - (ii[j] & 1);

			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		}
		sort(ii, l, i);
		l = k;
	}
}

int y_, head, tail, next[N * 2], prev[N * 2], xy[N * 2][N * 2], kk[N * 2]; long long dd[N * 2][N * 2];

int cmp(int i, int j) {
	return xx[i] != xx[j] ? xx[i] - xx[j] : ((i & 1) != (j & 1) ? (j & 1) - (i & 1) : (i >> 1) - (j >> 1));
}

void refresh(int i) {
	int z, k;

	if (kk[i] == 0 || xy[i][kk[i] - 1] <= (z = xx[next[i]] - y_))
		return;
	k = kk[i];
	while (k && xy[i][k - 1] > z)
		k--;
	if (k == 0 || dd[i][k] + xy[i][k] - z < dd[i][k - 1] + z - xy[i][k - 1])
		dd[i][k] += xy[i][k] - z, xy[i][k] = z, k++;
	kk[i] = k;
}

void insert(int i) {
	int l, z, h;
	long long d1, d2;

	l = head;
	while (cmp(next[l], i) < 0)
		l = next[l];
	if (kk[l]) {
		refresh(l);
		z = xx[i] - y_;
		h = 0;
		while (h < kk[l] && xy[l][h] <= z)
			h++;
		d1 = h == 0 ? INF : dd[l][h - 1] + z - xy[l][h - 1], d2 = h == kk[l] ? INF : dd[l][h] + xy[l][h] - z;
		if (d1 < d2) {
			kk[i] = kk[l] - h + 1, kk[l] = h;
			xy[i][0] = z, dd[i][0] = d1;
			if (kk[i] - 1 > 0) {
				memcpy(xy[i] + 1, xy[l] + h, (kk[i] - 1) * sizeof *xy[l]);
				memcpy(dd[i] + 1, dd[l] + h, (kk[i] - 1) * sizeof *dd[l]);
			}
		} else if (d1 > d2) {
			kk[i] = kk[l] - h, kk[l] = h + 1;
			memcpy(xy[i], xy[l] + h, kk[i] * sizeof *xy[l]);
			memcpy(dd[i], dd[l] + h, kk[i] * sizeof *dd[l]);
			xy[l][kk[l] - 1] = z, dd[l][kk[l] - 1] = d2;
		} else {
			kk[i] = kk[l] - h, kk[l] = h;
			memcpy(xy[i], xy[l] + h, kk[i] * sizeof *xy[l]);
			memcpy(dd[i], dd[l] + h, kk[i] * sizeof *dd[l]);
		}
	}
	next[i] = next[l], prev[next[l]] = i, next[l] = i, prev[i] = l;
}

void extract(int i) {
	int l = prev[i], h1, h2;

	refresh(l), refresh(i);
	h1 = kk[l] - 1, h2 = 0;
	while (h1 >= 0 && h2 < kk[i]) {
		int z = xy[i][h2] - xy[l][h1];

		if (dd[l][h1] >= dd[i][h2] + z)
			h1--;
		else if (dd[l][h1] + z <= dd[i][h2])
			h2++;
		else
			break;
	}
	kk[l] = h1 + 1;
	if (h2 < kk[i]) {
		memcpy(xy[l] + kk[l], xy[i] + h2, (kk[i] - h2) * sizeof *xy[i]);
		memcpy(dd[l] + kk[l], dd[i] + h2, (kk[i] - h2) * sizeof *dd[i]);
		kk[l] += kk[i] - h2;
	}
	next[l] = next[i], prev[next[i]] = l;
}

int main() {
	static int ii[N * 2];
	int n, x, h, i;
	long long ans;

	srand_();
	scanf("%d%d", &n, &x);
	for (i = 0; i < n; i++)
		scanf("%d%d%d%d", &yy[i << 1 | 0], &yy[i << 1 | 1], &xx[i << 1 | 0], &xx[i << 1 | 1]), xx[i << 1 | 0]--, xx[i << 1 | 1]++, yy[i << 1 | 0]--, yy[i << 1 | 1]++;
	xx[n << 1 | 0] = -X, xx[n << 1 | 1] = X;
	for (i = 0; i < n * 2; i++)
		ii[i] = i;
	sort(ii, 0, n * 2);
	head = n << 1 | 0, tail = n << 1 | 1;
	next[head] = tail, prev[tail] = head;
	xy[head][kk[head]] = x, dd[head][kk[head]] = 0, kk[head]++;
	for (h = 0; h < n * 2; h++) {
		int i0, i1;

		i = ii[h] >> 1, i0 = i << 1 | 0, i1 = i << 1 | 1, y_ = yy[ii[h]];
		if ((ii[h] & 1) == 0) {
			insert(i0), insert(i1);
			for (i = i0; i != i1; i = next[i])
				kk[i] = 0;
		} else
			extract(i0), extract(i1);
	}
	ans = INF;
	for (h = 0; h < kk[head]; h++)
		ans = min(ans, dd[head][h]);
	printf("%lld\n", ans);
	return 0;
}
