void DoTranspose(int64_t num_axes, const std::vector<int64_t>& target_dims,
                 size_t num_blocks, size_t num_elts_in_block,
                 const std::vector<size_t>& stride,
                 float* target, const float* source) {
  size_t blocksize = num_elts_in_block * sizeof(float);
  // index used to iterate over target iteration-space
  std::vector<int64_t> target_index(num_axes, 0);
  for (size_t i = 0; i < num_blocks; ++i) {
    // convert target_index into an offset in source data
    size_t source_offset = ComputeOffset(target_index, stride, num_axes);

    // copy
    memcpy(target, source + source_offset, blocksize);

    // increment target_index:
    IncrementIndex(target_index, target_dims, num_axes);
    target += num_elts_in_block;
  }
}