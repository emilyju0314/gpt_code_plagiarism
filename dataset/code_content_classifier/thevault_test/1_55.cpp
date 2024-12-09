byte* Gen_key(int key_size){

  byte* seed_;
  seed_ = new byte[key_size];
  CryptoPP::AutoSeededRandomPool prng;
  prng.GenerateBlock(seed_, key_size);
  return seed_;
}