void speck_encrypt( const uint64_t plaintext[2]
                  , const uint64_t key[2]
                  , uint64_t ciphertext[2]
                  )
{
  uint64_t b = key[0];
  uint64_t a = key[1];
  ciphertext[0] = plaintext[0];
  ciphertext[1] = plaintext[1];
  for (unsigned i = 0; i < ROUNDS; i++) {
    speck_round(ciphertext[1], ciphertext[0], b); 
    speck_round(a, b, i); // Get next row of key schedule
  }
}