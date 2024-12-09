vector<int> verify_encrypted_proof(bigint*** proof, bigint root_node, int* challenge, int number_of_chall, int file_size, int pad_size, byte* key, byte* iv, int key_size, bigint* modulus, int byte_){

  int size_1 = log2(file_size) + 1;
  int tail_1, tail_2;
  bool is_in, is_in_;
  vector<int> res_;
  vector<int> vec;
  bigint* temp_hash, * temp_val;
  bigint one;
  mpz_init_set_str(one, "1", 10);
  temp_hash = (mpz_t*)malloc(1 * sizeof(mpz_t));
  temp_val = (mpz_t*)malloc(1 * sizeof(mpz_t));
  string cipher;
  CBC_Mode< AES >::Encryption e;
	e.SetKeyWithIV(key, key_size, iv); // set the key
  for(int i = 0; i < number_of_chall; i++){
    StringSource s(to_string(i), true, new StreamTransformationFilter(e, new StringSink(cipher)));// encrypt the str_index
    unsigned char der_key_0[key_size]; // convert the ciphertext into a der_key
    memset(der_key_0, 0x00, key_size + 1);
    strcpy((char*)der_key_0, cipher.c_str());
    cipher.clear();
    for (int  j = 0; j < size_1; j++){
      if(j == 0){
        // derive a key for index j
        temp_val = encrypt(j, der_key_0, key_size, iv, byte_); // derive a key for index j
        // unblind proof[i][j][0].
        mpz_sub(temp_val[0], modulus[0], temp_val[0]);
        mpz_add(proof[i][j][0], temp_val[0], proof[i][j][0]);
        mpz_mod(proof[i][j][0], proof[i][j][0], modulus[0]);
        temp_val = encrypt(j+1, der_key_0, key_size, iv, byte_); // derive a key for index j+1
        // unblind proof[i][j+1][0].
        mpz_sub(temp_val[0], modulus[0], temp_val[0]);
        mpz_add(proof[i][j+1][0], temp_val[0], proof[i][j+1][0]);
        mpz_mod(proof[i][j+1][0], proof[i][j+1][0], modulus[0]);
        // extract the tail of the two leaf nodes
        tail_1 = extract_tail(proof[i][j][0], pad_size);
        tail_2 = extract_tail(proof[i][j+1][0], pad_size);
        // check if the tail equals the related challenge.
        is_in = search(challenge, number_of_chall, tail_1);
        is_in_ = search(challenge, number_of_chall, tail_2);
        // check if (1) either proof[i][j][0] or  proof[i][j+1][0] is the challenged block,
        // and (2) there is no duplication of proof.
        if(((is_in || is_in_) == true) && (find(vec.begin(), vec.end(), challenge[i]) == vec.end())){
          temp_hash = hash_combined_values(proof[i][j][0], proof[i][j+1][0], modulus[0]);
          vec.push_back(challenge[i]);
        }
        else{
          res_.push_back(i); // store the index of rejected proof
          break; // exit the inner loop.
        }
        j++;
      }
      else{ // if j!=0
        temp_val = encrypt(j, der_key_0, key_size, iv, byte_);//derive a key for index j
        // unblind proof[i][j][0].
        mpz_sub(temp_val[0], modulus[0], temp_val[0]);
        mpz_add(proof[i][j][0], temp_val[0], proof[i][j][0]);
        mpz_mod(proof[i][j][0], proof[i][j][0], modulus[0]);
        if(mpz_cmp(proof[i][j][1], one) == 0){
          temp_hash = hash_combined_values(proof[i][j][0], temp_hash[0], modulus[0]);
        }
        else{ // if mpz_cmp(proof[i][j][1], one) != 0) or when mpz_cmp(proof[i][j][1], zero) == 0
          temp_hash = hash_combined_values(temp_hash[0], proof[i][j][0], modulus[0]);
        }
      }
      if(j+1 == size_1){
        if(mpz_cmp(temp_hash[0], root_node)!=0){
          res_.push_back(i); // store the index of rejected proof
        }
      }
    }
  }
  mpz_clear(temp_hash[0]);
  return res_;
}