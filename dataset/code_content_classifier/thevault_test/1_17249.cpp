TEST_F(ShaderCacheTest, InsertsShadersMultithreaded) {
  ShaderCache &cache = getCache();
  SmallVector<char> cacheEntry(64);
  constexpr size_t numShaders = 128;
  constexpr size_t numThreads = 8;
  constexpr unsigned maxWaitTimeMilliseconds = 4;

  SmallVector<MetroHash::Hash, 0> hashes(numShaders);
  for (auto &hashAndIndex : enumerate(hashes))
    hashAndIndex.value() = hashFromDWords(static_cast<unsigned>(hashAndIndex.index()), 2, 3, 4);

  // Initialize the generator with a deterministic seed.
  std::mt19937 generator(std::random_device{}());
  std::uniform_int_distribution<unsigned> waitTimeDistribution(0, maxWaitTimeMilliseconds * 1000);
  auto getWaitTime = [&generator, &waitTimeDistribution] {
    return std::chrono::microseconds(waitTimeDistribution(generator));
  };

  for (auto &hash : hashes) {
    std::atomic<size_t> numInsertions{0};
    std::atomic<size_t> numHits{0};

    Error err = parallelFor(numThreads, seq(size_t(0), numThreads),
                            [&cache, &cacheEntry, hash, &getWaitTime, &numInsertions, &numHits](size_t) -> Error {
                              CacheEntryHandle handle = nullptr;
                              ShaderEntryState state = cache.findShader(hash, true, &handle);
                              if (!handle)
                                return createResultError(Result::ErrorUnavailable);

                              if (state == ShaderEntryState::Compiling) {
                                // Insert the new entry. Sleep to simulate compilation time.
                                std::this_thread::sleep_for(getWaitTime());
                                cache.insertShader(handle, cacheEntry.data(), cacheEntry.size());
                                ++numInsertions;
                              } else {
                                EXPECT_EQ(state, ShaderEntryState::Ready);
                                ++numHits;
                              }
                              return Error::success();
                            });

    EXPECT_THAT_ERROR(std::move(err), Succeeded());
    EXPECT_EQ(numInsertions, 1);
    EXPECT_EQ(numHits, numThreads - 1);
  }

  // All entries should be in the cache now.
  for (auto &hash : hashes) {
    CacheEntryHandle newHandle = nullptr;
    ShaderEntryState state = cache.findShader(hash, false, &newHandle);
    EXPECT_EQ(state, ShaderEntryState::Ready);
    EXPECT_NE(newHandle, nullptr);
  }

  size_t cacheSize = 0;
  Result result = cache.Serialize(nullptr, &cacheSize);
  EXPECT_EQ(result, Result::Success);
  EXPECT_GE(cacheSize, sizeof(ShaderCacheSerializedHeader) + (numShaders * cacheEntry.size()));
}