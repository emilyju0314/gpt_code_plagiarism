static void sha512_process_block(uint64_t hash[8], uint64_t block[16]) {
  uint64_t A, B, C, D, E, F, G, H;
  uint64_t W[16];
  const uint64_t *k;
  int i;

  A = hash[0], B = hash[1], C = hash[2], D = hash[3];
  E = hash[4], F = hash[5], G = hash[6], H = hash[7];

  /* Compute SHA using alternate Method: FIPS 180-3 6.1.3 */
  ROUND_1_16(A, B, C, D, E, F, G, H, 0);
  ROUND_1_16(H, A, B, C, D, E, F, G, 1);
  ROUND_1_16(G, H, A, B, C, D, E, F, 2);
  ROUND_1_16(F, G, H, A, B, C, D, E, 3);
  ROUND_1_16(E, F, G, H, A, B, C, D, 4);
  ROUND_1_16(D, E, F, G, H, A, B, C, 5);
  ROUND_1_16(C, D, E, F, G, H, A, B, 6);
  ROUND_1_16(B, C, D, E, F, G, H, A, 7);
  ROUND_1_16(A, B, C, D, E, F, G, H, 8);
  ROUND_1_16(H, A, B, C, D, E, F, G, 9);
  ROUND_1_16(G, H, A, B, C, D, E, F, 10);
  ROUND_1_16(F, G, H, A, B, C, D, E, 11);
  ROUND_1_16(E, F, G, H, A, B, C, D, 12);
  ROUND_1_16(D, E, F, G, H, A, B, C, 13);
  ROUND_1_16(C, D, E, F, G, H, A, B, 14);
  ROUND_1_16(B, C, D, E, F, G, H, A, 15);

  for (i = 16, k = &k512[16]; i < 80; i += 16, k += 16) {
    ROUND_17_80(A, B, C, D, E, F, G, H, 0);
    ROUND_17_80(H, A, B, C, D, E, F, G, 1);
    ROUND_17_80(G, H, A, B, C, D, E, F, 2);
    ROUND_17_80(F, G, H, A, B, C, D, E, 3);
    ROUND_17_80(E, F, G, H, A, B, C, D, 4);
    ROUND_17_80(D, E, F, G, H, A, B, C, 5);
    ROUND_17_80(C, D, E, F, G, H, A, B, 6);
    ROUND_17_80(B, C, D, E, F, G, H, A, 7);
    ROUND_17_80(A, B, C, D, E, F, G, H, 8);
    ROUND_17_80(H, A, B, C, D, E, F, G, 9);
    ROUND_17_80(G, H, A, B, C, D, E, F, 10);
    ROUND_17_80(F, G, H, A, B, C, D, E, 11);
    ROUND_17_80(E, F, G, H, A, B, C, D, 12);
    ROUND_17_80(D, E, F, G, H, A, B, C, 13);
    ROUND_17_80(C, D, E, F, G, H, A, B, 14);
    ROUND_17_80(B, C, D, E, F, G, H, A, 15);
  }

  hash[0] += A, hash[1] += B, hash[2] += C, hash[3] += D;
  hash[4] += E, hash[5] += F, hash[6] += G, hash[7] += H;
}