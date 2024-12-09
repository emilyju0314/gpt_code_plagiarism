void BetterYao5::generate_eval_input_keys(uint32_t circuit_num){
    

  //Bytes rand_key;
  G rnd;
  for(int i = 0; i < get_evl_inp_count()*2;i++){

    // this implementation will replace the current one when
    // we link OT extensions
    // rand_key = m_circuit_prngs[circuit_num].rand_bits(Env::elm_size_in_bytes()*8);
    // rnd.from_bytes(rand_key);

    // m_evl_inp_keys[circuit_num].push_back(rand_key);
  
    rnd.random(m_circuit_prngs[circuit_num]);
    m_evl_inp_keys[circuit_num].push_back(rnd.to_bytes());
      
  }
  
}