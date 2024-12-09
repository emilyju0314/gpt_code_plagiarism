void build(int node, int l, int r){
	if(l > r) return;
	if(l == r){
		tree[node] = l;
	}else{
		int mid = (l+r) >> 1;
		build(node*2, l, mid);
		build(node*2+1, mid+1, r);
		int A = tree[node*2];
		int B = tree[node*2+1];
		if(L[A] <= L[B]){
			tree[node] = A;
		}else{
			tree[node] = B;
		}
	}
}