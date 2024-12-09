bool doubleCheck_proof_(bigint*** proof, bigint root_node, int* challenge, int number_of_chall, int file_size, int pad_size, int rejected_proof_index, bigint modulus){

  int size_1 = log2(file_size) + 1;
  int tail_1, tail_2;
  bool is_in, is_in_;
  bigint* temp_hash;
  bigint one;
  mpz_init_set_str(one, "1", 10);
  temp_hash = (mpz_t*)malloc(1 * sizeof(mpz_t));
  int i = rejected_proof_index;
  for (int  j = 0; j < size_1; j++){
    if(j == 0){
      // extract the tail of the two leaf nodes
      tail_1 = extract_tail(proof[i][j][0], pad_size);
      tail_2 = extract_tail(proof[i][j+1][0], pad_size);
        // check if the tail equals the related challenge.
      if(challenge[i] == tail_1 || challenge[i] == tail_2){
        temp_hash = hash_combined_values(proof[i][j][0], proof[i][j+1][0], modulus);
      }
      else{
        cout<<"\n Proof is invalid"<<endl;
        return false;
      }
      j++;
    }
    else{ // if j!=0
      if(mpz_cmp(proof[i][j][1], one) == 0){
        temp_hash = hash_combined_values(proof[i][j][0], temp_hash[0],  modulus);
      }
      else{ // if mpz_cmp(proof[i][j][1], one) != 0) or when mpz_cmp(proof[i][j][1], zero) == 0
        temp_hash = hash_combined_values(temp_hash[0], proof[i][j][0],  modulus);
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