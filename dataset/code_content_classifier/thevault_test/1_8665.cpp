void BetterYao5::generate_input_keys(Prng & prng, std::vector<Bytes> & dest, uint32_t num_keys, uint32_t num_bits){
  Bytes key;
  int j;
  for(j=0;j<num_keys;j++){
    // generate the key (so that it is the right size)
    key = prng.rand_bits(num_bits);
    // set the permutation bit. evens are 0, odds are 1
    //    key.set_ith_bit(0, j%2);
    dest.push_back(key);
  }

}