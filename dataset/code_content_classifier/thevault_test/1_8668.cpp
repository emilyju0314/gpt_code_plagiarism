static void my_file_mpz_random(mpz_t r, mpz_t limit, void *data) {
//  char *filename = (char *) data;
//  FILE *fp;
  int n, bytecount, leftover;
  unsigned char *bytes;
  mpz_t z;
  mpz_init(z);
//  fp = fopen(filename, "rb");
//  if (!fp) return;
  n = mpz_sizeinbase(limit, 2);
  bytecount = (n + 7) / 8;
  leftover = n % 8;
  bytes = (unsigned char *) pbc_malloc(bytecount);
  for (;;) {
    if (!fread(bytes, 1, bytecount, fp)) {
      pbc_warn("error reading source of random bits");
      return;
    }
    if (leftover) {
      *bytes = *bytes % (1 << leftover);
    }
    mpz_import(z, bytecount, 1, 1, 0, 0, bytes);
    if (mpz_cmp(z, limit) < 0) break;
  }
//  fclose(fp);
  mpz_set(r, z);
  mpz_clear(z);
  pbc_free(bytes);
}