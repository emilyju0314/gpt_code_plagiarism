uint64_t reporting::random(uint64_t seed, uint64_t a, uint64_t b) {
  uint64_t m = 1337;
  uint64_t y = seed % (m - 1);
  a = a % (m - 1);
  b = b % (m - 1);
  
  return (a * y + b) % m;
}