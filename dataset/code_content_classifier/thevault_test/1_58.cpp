bool doubleCheck_encrypted_proof_(bigint*** proof, bigint root_node, int* challenge, int number_of_chall, int file_size, int pad_size, int rejected_proof_index, byte* key, byte* iv, int key_size, bigint* modulus, int byte_){

  int size_1 = log2(file_size) + 1;
  int tail_1, tail_2;
  bool is_in, is_in_;
  bigint* temp_hash, * temp_val;
  bigint one;
  mpz_init_set_str(one, "1", 10);
  temp_hash = (mpz_t*)malloc(1 * sizeof(mpz_t));
  temp_val = (mpz_t*)malloc(1 * sizeof(mpz_t));
  mpz_init(temp_val[0]);
  int i = rejected_proof_index;
  //----1- encrypt i
  string cipher;
  CBC_Mode< AES >::Encryption e;
	e.SetKeyWithIV(key, key_size, iv); // set the key
  StringSource s(to_string(i), true, new StreamTransformationFilter(e, new StringSink(cipher)));// encrypt the str_index
  unsigned char der_key_0[key_size]; // convert the ciphertext into a der_key
  memset(der_key_0, 0x00, key_size + 1);
  strcpy((char*)der_key_0, cipher.c_str());
  cipher.clear();
  cout<<proof[i][0][0]<<endl;
  for (int  j = 0; j < size_1; j++){
    if(j == 0){
      temp_val = encrypt(j, der_key_0, key_size, iv, byte_); //derive a key for index j
      // unblind proof[i][j][0].
      mpz_sub(temp_val[0], modulus[0], temp_val[0]);
      mpz_add(proof[i][j][0], temp_val[0], proof[i][j][0]);
      mpz_mod(proof[i][j][0], proof[i][j][0], modulus[0]);
      temp_val = encrypt(j+1, der_key_0, key_size, iv, byte_); //derive a key for index j+1
      // unblind proof[i][j+1][0].
      mpz_sub(temp_val[0], modulus[0], temp_val[0]);
      mpz_add(proof[i][j+1][0], temp_val[0], proof[i][j+1][0]);
      mpz_mod(proof[i][j+1][0], proof[i][j+1][0], modulus[0]);
      // extract the tail of the two leaf nodes
      tail_1 = extract_tail(proof[i][j][0], pad_size);
      tail_2 = extract_tail(proof[i][j+1][0], pad_size);
      // check if the tail equals the related challenge.
      if(challenge[i] == tail_1 || challenge[i] == tail_2){
        temp_hash = hash_combined_values(proof[i][j][0], proof[i][j+1][0], modulus[0]);
      }
      else{
        cout<<"\n Proof is invalid"<<endl;
        return false;
      }
      j++;
    }
    else{ // if j!=0
      temp_val = encrypt(j, der_key_0, key_size, iv, byte_); //derive a key for index j
      // unblind proof[i][j][0].
      mpz_sub(temp_val[0], modulus[0], temp_val[0]);
      mpz_add(proof[i][j][0], temp_val[0], proof[i][j][0]);
      mpz_mod(proof[i][j][0], proof[i][j][0], modulus[0]);
      if(mpz_cmp(proof[i][j][1], one) == 0){
        temp_hash = hash_combined_values(proof[i][j][0], temp_hash[0],  modulus[0]);
      }
      else{ // if mpz_cmp(proof[i][j][1], one) != 0) or when mpz_cmp(proof[i][j][1], zero) == 0
        temp_hash = hash_combined_values(temp_hash[0], proof[i][j][0],  modulus[0]);
      }
    }
    if(j+1 == size_1){
      if(mpz_cmp(temp_hash[0], root_node)!=0){
        cout<<"\n Proof is invalid"<<endl;
        return false;
      }
    }
  }
  mpz_clear(temp_hash[0]);
  return true;
}