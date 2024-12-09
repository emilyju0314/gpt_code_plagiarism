void BetterYao5::seed_prngs(std::vector<Prng> & prngs, std::vector<Bytes> & seeds){
  assert(prngs.size() == seeds.size());
  
  for(int i=0;i<prngs.size();i++){
    prngs[i].seed_rand(seeds[i]);
  }
}