void SHA1Update(SHA1_CTX* context, const uint8_t* data, size_t input_len) {
  size_t i = 0;

#ifdef VERBOSE
  SHAPrintContext(context, "before");
#endif

  // Compute number of bytes mod 64.
  size_t index = (context->count[0] >> 3) & 63;

  // Update number of bits.
  // TODO: Use uint64_t instead of 2 uint32_t for count.
  // count[0] has low 29 bits for byte count + 3 pad 0's making 32 bits for
  // bit count.
  // Add bit count to low uint32_t
  context->count[0] += static_cast<uint32_t>(input_len << 3);
  if (context->count[0] < static_cast<uint32_t>(input_len << 3)) {
    ++context->count[1];  // if overlow (carry), add one to high word
  }
  context->count[1] += static_cast<uint32_t>(input_len >> 29);
  if ((index + input_len) > 63) {
    i = 64 - index;
    memcpy(&context->buffer[index], data, i);
    SHA1Transform(context->state, context->buffer);
    for (; i + 63 < input_len; i += 64) {
      SHA1Transform(context->state, data + i);
    }
    index = 0;
  }
  memcpy(&context->buffer[index], &data[i], input_len - i);

#ifdef VERBOSE
  SHAPrintContext(context, "after ");
#endif
}