void convolution(int n, long long* A, long long* B){
        int len = build_convolution(n, A, B);
        multiply(len, P, len, Q);
        for (int i = 0; i < n; i++) A[i] = P[i + n];
	}