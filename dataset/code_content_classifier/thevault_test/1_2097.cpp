bool host_dft(cuComplex *Y, cuComplex *X, float scale, int N) {
	const float Pi = 3.14159265358979f;
	for (int n = 0; n < N; n++) {
		cuComplex X_n = {0, 0};	
		for (int k = 0; k < N; k++) {
			float w = -2.0f * Pi / (float)N * (float)n * (float)k;
			cuComplex e = {(float)cos(w), (float)sin(w)};
			cuComplex x_k = X[k];
			X_n.x += e.x * x_k.x - e.y * x_k.y;
			X_n.y += e.y * x_k.x + e.x * x_k.y;
		}
		X_n.x *= scale;
		X_n.y *= scale;
		Y[n] = X_n;
	}
	return true;
}