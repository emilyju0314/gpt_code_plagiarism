void GarbledMal::initialize_gen_circuit(const std::vector<Bytes> &ot_keys, const Bytes &gen_inp_mask, const Bytes &seed){
  
  // set the circuit's ot keys
  m_ot_keys = &ot_keys;

  // set the circuit's input mask (is this necessary for new version (BY5)?)
  m_gen_inp_mask = gen_inp_mask;

  // must seed the circuit's random number generator
  m_prng.seed_rand(seed);

  // at this point (now that we have a prng),
  //we can determine the free-XOR value R for the circuit
  Bytes tmp;
  tmp = m_prng.rand_bits(Env::k());
  tmp.set_ith_bit(0,1);
  tmp.resize(16,0);
  m_R = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&tmp[0]));

  // must also pick zero-keys for the constant wires
  tmp = m_prng.rand_bits(Env::k());
  tmp.resize(16, 0);
  m_const_wire[0] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&tmp[0]));

  tmp = m_prng.rand_bits(Env::k());
  tmp.resize(16, 0);
  m_const_wire[1] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&tmp[0]));

}