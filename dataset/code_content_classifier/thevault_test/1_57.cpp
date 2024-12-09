bigint* gen_public_key(int bit_size){

  bigint* res;
  res =  (bigint*)malloc(1 * sizeof(mpz_t));
  mpz_init(res[0]);
  Random rd;
  res = rd.gen_randSet(1, bit_size);
  mpz_nextprime(res[0], res[0]);
  return res;
}