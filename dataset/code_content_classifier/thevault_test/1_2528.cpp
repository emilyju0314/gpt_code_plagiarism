inline void CheckErrorMsg(cudaError_t const err, char const *const msg, char const *const fun,
                          int const line) {
  if (err) {
    printf("CUDA Error Code[%d]: %s\n%s() Line:%d\n%s\n", err, cudaGetErrorString(err), fun, line,
           msg);
    exit(1);
  }
}