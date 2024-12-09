int find_index(bigint* set, int set_size, bigint val, bool &res_, int offset){

  int res;
  for(int i = offset-1; i < set_size; i++){
    if (mpz_cmp(set[i], val) == 0){
      res_ = true;
      return i;// 0 means val exists in the set
    }
  }
  res_ = false;
  return 0;
}