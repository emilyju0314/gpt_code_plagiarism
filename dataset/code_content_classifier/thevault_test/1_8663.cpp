void BetterYao5::generate_random_seeds(std::vector<Bytes> & seeds,uint32_t num_seeds){
 
  Bytes rand;
  G rand_elem;
  //Prng prng = Prng();
  
  seeds.clear();

  for(int i=0;i<num_seeds;i++){
    // these random elements will be used for OT,
    // so we generate them as random group elements

    
    // this version useful for ALSZ extension
    //rand = prng.rand_bits(Env::elm_size_in_bytes()*8);
    //std::cout << "prng rand element: " << rand.to_hex() << std::endl;
    //seeds.push_back(rand);
    
    rand_elem.random();
    seeds.push_back(rand_elem.to_bytes());
  }
}