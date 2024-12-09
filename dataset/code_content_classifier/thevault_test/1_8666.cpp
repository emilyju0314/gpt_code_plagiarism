void BetterYao5::generate_gen_input_keys(uint32_t circuit_num){
  // this function should be executed in parallel by all processors

  // first, generate all of the input keys for Gen
  // (K_{0},K_{1}) <-$ {0,1}^{2k}
  m_R[circuit_num] = m_circuit_prngs[circuit_num].rand_bits(Env::k());
  m_R[circuit_num].set_ith_bit(0,1);
 
  std::vector<Bytes> random_keys;

  // generate enough input keys for Gen's entire input
  // and then compute their XOR-offsets
  generate_input_keys(m_circuit_prngs[circuit_num],
                      random_keys,
                      get_gen_full_input_size(),
                      Env::k());
  
  // the proper XOR-offsets get pushed alongside the input keys
  for(int i = 0; i < get_gen_full_input_size();i++){
    random_keys[i].set_ith_bit(0,0);
    m_gen_inp_keys[circuit_num].push_back(random_keys[i]);
    m_gen_inp_keys[circuit_num].push_back(random_keys[i] ^ m_R[circuit_num]);
  }
  
  // next generate permutation bits for Gen's input keys
  // { pi_{i} } <-$ {0,1} for i in (0, gen_inputs ]  
  m_gen_inp_permutation_bits[circuit_num] = m_circuit_prngs[circuit_num].rand_bits(get_gen_full_input_size());
 
  // now we have a situation where we have a bunch of permutation bits
  // and a bunch of keys, ordered [0,1,0,1] etc.
  // the idea is that the permutation bit tells us if 
  // the 0 key encodes a 0 (0th bit 0) or a 1 (0th bit 1)
  // Gen also has his own input bits
  // so we have the following table to describe which key Gen sends
  // depending on his input key and the permutation bit
  //   Gen Input     Permutation    Selected
  //      0       |       0      |     0
  //      0       |       1      |     1
  //      1       |       0      |     1
  //      1       |       1      |     0
  // which is easily an XOR
 
  m_gen_select_bits[circuit_num] = m_gen_inp_permutation_bits[circuit_num] ^ get_gen_full_input();
  
}