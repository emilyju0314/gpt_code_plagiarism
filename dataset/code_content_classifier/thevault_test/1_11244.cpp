bool is_parallel_slicable(const pnode_ptr& n) {
  std::map<pnode_ptr, size_t> memoizer;
  size_t counter = 1;

  return _propagate_parallel_slicing(n, memoizer, counter) != size_t(-1); 
}