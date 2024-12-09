inline void CheckError(cudaError_t const err, char const *const fun, const int line) {
  if (err) {
    printf("CUDA Error Code[%d]: %s\n%s() Line:%d\n", err, cudaGetErrorString(err), fun, line);
    exit(1);
  }
}