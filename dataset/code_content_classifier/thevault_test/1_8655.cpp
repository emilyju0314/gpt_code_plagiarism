void GarbledMal::evl_next_gen_inp_com(const Bytes &row, size_t kx){
  // get Bytes array the length of a decommitment
  // it defaults to 0
  Bytes out(this->m_gen_inp_decom[0].size());
  
  
  /*   
  // std::cout << "m_gen_inp_decom.size(): " << this->m_gen_inp_decom.size() << std::endl;
  // std::cout << "key size(bytes): "<< Env::key_size_in_bytes() << "\t key size(bits): " << Env::key_size_in_bytes()*8 << std::endl;

  // std::cout << "Out (bytes): " << out.to_hex() << std::endl;
  

  // this takes the XOR of all of Gen's input decommitments for which
  // the ith value in the 2-UHF row is set
  // this is equivalent to evaluating a circuit of only
  // XOR gates that evaluates the 2-UHF
  // since every time a bit is set in the UHF,
  // we XOR the current key with all of the previous
  // and we end up with the output of the 2-UHF.
  // below, we will extract the semantics of the final bit
  // but how is this a secure way of getting input commitments?
  for (size_t jx = 0; jx < this->m_gen_inp_decom.size(); jx++)
    {
      if (row.get_ith_bit(jx)) {
        out ^= this->m_gen_inp_decom[jx];
        // std::cout << "Out (bytes): " << out.to_hex() << std::endl;
      }
    }
  
  // std::cout << "Out (bytes): " << out.to_hex() << std::endl;
  
  // now get the 0th bit
  // this should be the permutation bit
  // and since it is an output bit,
  // it carries the semantics of the wire
  byte bit = out.get_ith_bit(0);
  
  //  std::cout << "bit: " << (bit == 0 ? "0" : "1") << std::endl;
  //  assert(bit == 0 || bit == 1);

  //static Bytes tmp;
  Bytes tmp;
  Bytes tmp2;

  // this piece is a little troubling: where is m_in_bufr_ix?
  // std::cout << "m_in_bufr_ix: " << (this->m_in_bufr_ix) << std::endl;
  Bytes::iterator it = this->m_in_bufr_ix + bit*Env::key_size_in_bytes();
  
  __m128i aes_key, aes_plaintext, aes_ciphertext, out_key;
  
  tmp.assign(out.begin(), out.begin()+Env::key_size_in_bytes());
  tmp.resize(16, 0);
  aes_key = _mm_loadu_si128(reinterpret_cast<__m128i*>(&tmp[0]));

  //  std::cout << "aes key: " << tmp.to_hex() << std::endl;
  //aes_plaintext = _mm_set1_epi64x((uint64_t)kx+10); // why +10??
  aes_plaintext = _mm_set1_epi64x((uint64_t)kx); // why do we set both 64-bit integers to kx? 
  // changing this value not affecting anything! something's up here.

  tmp2.resize(16,0);
  _mm_storeu_si128(reinterpret_cast<__m128i*>(&tmp2[0]),aes_plaintext);
  // std::cout << "Aes plaintext: " << tmp2.to_hex() << std::endl;


  //KDF128((uint8_t*)&aes_plaintext, (uint8_t*)&aes_ciphertext, (uint8_t*)&aes_key);
  //THIS LINE USED TO BE INCLUDED, AND THE RESULTS WERE THE SAME!!!
  //MAJOR, SERIOUS BUG
   
  aes_ciphertext = _mm_and_si128(aes_ciphertext, this->m_clear_mask);

  // look at the aes_ciphertext
  tmp2.resize(16,0);
  _mm_storeu_si128(reinterpret_cast<__m128i*>(&tmp2[0]),aes_ciphertext);
  // std::cout << "Aes ciphertext: " << tmp2.to_hex() << std::endl;
  
  tmp.assign(it, it+Env::key_size_in_bytes());
  tmp.resize(16, 0);
  out_key = _mm_loadu_si128(reinterpret_cast<__m128i*>(&tmp[0]));
  out_key = _mm_xor_si128(out_key, aes_ciphertext);
  
  // std::cout << "out key: " << tmp.to_hex() << std::endl;

  bit = _mm_extract_epi8(out_key, 0) & 0x01;

  //  std::cout << "hash bit: " << (bit == 0? "0" : "1") << std::endl;
  this->m_gen_inp_hash.set_ith_bit(kx, bit);
  
  this->m_in_bufr_ix += 2*Env::key_size_in_bytes();
  
  */
}