int multiply(int a, long long* A, int b, long long* B){
	    if (equals(a, A, b, B)) return square(a, A); /// Optimization

		build(a, A, b, B);
		for (int i = 0; i < len; i++) u[i] = complx(A[i], B[i]);
		transform_unrolled(u, f, dp);
		for (int i = 0; i < len; i++){
            int j = (len - 1) & (len - i);
            u[i] = (f[j] * f[j] - f[i].conjugate() * f[i].conjugate()) * complx(0, -0.25 / len);
		}
		transform_unrolled(u, f, dp);
		for (int i = 0; i < len; i++) A[i] = f[i].real + 0.5;
		return a + b - 1;
	}