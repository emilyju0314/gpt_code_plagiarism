TEST(ThreadPoolEnvironmentConfig, CanUseBackgroundPriorityForWorker) {
#if defined(OS_WIN) || defined(OS_APPLE)
  EXPECT_TRUE(CanUseBackgroundPriorityForWorkerThread());
#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
    defined(OS_CHROMEOS) || defined(OS_NACL)
  EXPECT_FALSE(CanUseBackgroundPriorityForWorkerThread());
#else
#error Platform doesn't match any block
#endif
}