void SHA1Final(SHA1_CTX* context, uint8_t digest[SHA1_DIGEST_SIZE]) {
  uint8_t finalcount[8];
  for (int i = 0; i < 8; ++i) {
    // Endian independent
    finalcount[i] = static_cast<uint8_t>(
        (context->count[(i >= 4 ? 0 : 1)] >> ((3 - (i & 3)) * 8)) & 255);
  }
  SHA1Update(context, reinterpret_cast<const uint8_t*>("\200"), 1);
  while ((context->count[0] & 504) != 448) {
    SHA1Update(context, reinterpret_cast<const uint8_t*>("\0"), 1);
  }
  SHA1Update(context, finalcount, 8);  // Should cause a SHA1Transform().
  for (int i = 0; i < SHA1_DIGEST_SIZE; ++i) {
    digest[i] = static_cast<uint8_t>(
        (context->state[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
  }

  // Wipe variables.
  memset(context->buffer, 0, 64);
  memset(context->state, 0, 20);
  memset(context->count, 0, 8);
  memset(finalcount, 0, 8);   // SWR

#ifdef SHA1HANDSOFF  // Make SHA1Transform overwrite its own static vars.
  SHA1Transform(context->state, context->buffer);
#endif
}