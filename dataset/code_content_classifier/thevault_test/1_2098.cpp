bool cuda_dft(cuComplex *Y, cuComplex *X, float scale, int N) {
	size_t bytes = (size_t)N * sizeof(cuComplex);
	cuComplex *Y_gpu, *X_gpu;
	
	cudaMalloc((void **)&Y_gpu, bytes);
	cudaMalloc((void **)&X_gpu, bytes);

	cudaMemcpy(Y_gpu, Y, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(X_gpu, X, bytes, cudaMemcpyHostToDevice);

	cufftHandle plan;
	cufftPlan1d(&plan, N, CUFFT_C2C, 1);

	cufftExecC2C(plan, X_gpu, Y_gpu, CUFFT_FORWARD);

	cufftDestroy(plan);

	cudaMemcpy(Y, Y_gpu, bytes, cudaMemcpyDeviceToHost);

	cudaFree(Y_gpu);
	cudaFree(X_gpu);

	for (int n = 0; n < N; n++) {
		Y[n].x *= scale;
		Y[n].y *= scale;
	}

	return true;
}