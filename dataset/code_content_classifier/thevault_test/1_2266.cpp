static bool IntegrateCmdlineEntropy() {
  const char* entropy = gCmdline.GetString("kernel.entropy-mixin");
  if (!entropy) {
    return false;
  }

  const size_t kMaxEntropyArgumentLen = 128;
  const size_t hex_len = fbl::min(strlen(entropy), kMaxEntropyArgumentLen);

  for (size_t i = 0; i < hex_len; ++i) {
    if (!isxdigit(entropy[i])) {
      panic("Invalid entropy string: idx %zu is not an ASCII hex digit\n", i);
    }
  }

  uint8_t digest[SHA256_DIGEST_LENGTH];
  SHA256(reinterpret_cast<const uint8_t*>(entropy), hex_len, digest);
  kGlobalPrng->AddEntropy(digest, sizeof(digest));

  // We have a pointer to const, but it's actually a pointer to the
  // mutable global state in __kernel_cmdline that is still live (it
  // will be copied into the userboot bootstrap message later).  So
  // it's fully well-defined to cast away the const and mutate this
  // here so the bits can't leak to userboot.  While we're at it,
  // prettify the result a bit so it's obvious what one is looking at.
  mandatory_memset(const_cast<char*>(entropy), 'x', hex_len);
  if (hex_len >= sizeof(".redacted=") - 1) {
    memcpy(const_cast<char*>(entropy) - 1, ".redacted=", sizeof(".redacted=") - 1);
  }

  const size_t entropy_added = fbl::max(hex_len / 2, sizeof(digest));
  LTRACEF("Collected %zu bytes of entropy from the kernel cmdline.\n", entropy_added);
  return (entropy_added >= PRNG::kMinEntropy);
}