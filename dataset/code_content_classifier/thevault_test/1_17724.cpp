void DoTransposeSingleBlock(size_t num_elts_in_block, float* target, const float* source) {
  size_t blocksize = num_elts_in_block * sizeof(float);
  // copy
  memcpy(target, source, blocksize);
}