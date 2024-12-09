#include <iostream>
#include <climits>

typedef std::pair<int,int> TV; // Time and Value

void update(TV* A, int s, int t, int index, int l, int r, int time, int val)
{
	if (t<l || r<=s) return; // no intersection
	else if (s<=l && r<=t+1) { // [l,r) is contained in [s,t] 
		A[index].first = time;
		A[index].second = val;
		return;
	}
	else { // at least one end exceeds the range
		int mid = (l+r)/2;
		update(A, s, t, 2*index+1, l, mid, time, val);
		update(A, s, t, 2*index+2, mid, r, time, val);
	}
}

TV find(TV* A, int k, int index, int l, int r)
{
	if (l+1==r) return A[index];
	
	int mid = (l+r)/2;
	TV res;
	if (k<mid) res = find(A, k, 2*index+1, l, mid);
	else res = find(A, k, 2*index+2, mid, r);
	
	return (res.first > A[index].first) ? res : A[index];
}

int main ()
{
	int n, q;
	std::cin >> n >> q;
	
	int a_size = 1;
	for(; a_size<n; a_size<<=1);
	TV* A = new TV[2*a_size-1];
	for (int i=0; i<2*a_size-1; i++) {
		A[i].first = -1;
		A[i].second = INT_MAX;
	}
	
	
	for (int i=0; i<q; i++) {
		int op, s, t, x, k;
		std::cin >> op;
		if (op==0) {
			std::cin >> s >> t >> x;
			update(A, s, t, 0, 0, n, i, x);
		} else {
			std::cin >> k;
			std::cout << find(A, k, 0, 0, n).second << std::endl;
		}
	}
	
	delete[] A;
	
	return 0;
}

