int long_multiply(int a, long long* A, int b, long long* B){
		int mod1 = 1.5e9;
		int mod2 = mod1 + 1;
		for (int i = 0; i < a; i++) C[i] = A[i];
		for (int i = 0; i < b; i++) D[i] = B[i];

		mod_multiply(a, A, b, B, mod1);
		mod_multiply(a, C, b, D, mod2);
		for (int i = 0; i < len; i++){
            A[i] = A[i] + (C[i] - A[i] + (long long)mod2) * (long long)mod1 % mod2 * mod1;
		}
		return a + b - 1;
	}