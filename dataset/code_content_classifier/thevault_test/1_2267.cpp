static void EarlyBootSeed(uint level) {
  ASSERT(kGlobalPrng == nullptr);

  // Before doing anything else, test our entropy collector. This is
  // explicitly called here rather than in another init hook to ensure
  // ordering (at level LK_INIT_LEVEL_TARGET_EARLY, but before the rest of
  // EarlyBootSeed).
  entropy::EarlyBootTest();

  // Statically allocate an array of bytes to put the PRNG into.  We do this
  // to control when the PRNG constructor is called.
  // TODO(security): This causes the PRNG state to be in a fairly predictable
  // place.  Some aspects of KASLR will help with this, but we may
  // additionally want to remap where this is later.
  alignas(alignof(PRNG)) static uint8_t prng_space[sizeof(PRNG)];
  kGlobalPrng = new (&prng_space) PRNG(nullptr, 0, PRNG::NonThreadSafeTag());

  unsigned int successful = 0;  // number of successful entropy sources
  entropy::Collector* collector = nullptr;
  if (entropy::HwRngCollector::GetInstance(&collector) == ZX_OK && SeedFrom(collector)) {
    successful++;
  } else if (gCmdline.GetBool("kernel.cprng-seed-require.hw-rng", false)) {
    panic("Failed to seed PRNG from required entropy source: hw-rng\n");
  }
  if (entropy::JitterentropyCollector::GetInstance(&collector) == ZX_OK && SeedFrom(collector)) {
    successful++;
  } else if (gCmdline.GetBool("kernel.cprng-seed-require.jitterentropy", false)) {
    panic("Failed to seed PRNG from required entropy source: jitterentropy\n");
  }

  if (IntegrateCmdlineEntropy()) {
    successful++;
  } else if (gCmdline.GetBool("kernel.cprng-seed-require.cmdline", false)) {
    panic("Failed to seed PRNG from required entropy source: cmdline\n");
  }

  if (successful == 0) {
    printf(
        "WARNING: System has insufficient randomness.  It is completely "
        "unsafe to use this system for any cryptographic applications."
        "\n");
    // TODO(security): *CRITICAL* This is a fallback for systems without RNG
    // hardware that we should remove and attempt to do better.  If this
    // fallback is used, it breaks all cryptography used on the system.
    // *CRITICAL*
    uint8_t buf[PRNG::kMinEntropy] = {0};
    kGlobalPrng->AddEntropy(buf, sizeof(buf));
    return;
  } else {
    LTRACEF("Successfully collected entropy from %u sources.\n", successful);
  }
}