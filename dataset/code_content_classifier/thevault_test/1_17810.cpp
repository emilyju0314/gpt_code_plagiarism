void TEST_GetStreamAddress(cudaStream_t* ptr) {
  CUDAContext context(0);
  *ptr = context.cuda_stream();
  // Sleep for a while so we have concurrent thread executions
  std::this_thread::sleep_for(std::chrono::seconds(1));
}