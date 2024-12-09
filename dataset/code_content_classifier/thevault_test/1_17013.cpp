TEST(TrackedRefTest, TrackedRefObjectDeletion) {
  Thread thread("TrackedRefTestThread");
  thread.Start();

  std::unique_ptr<ObjectWithTrackedRefs> obj =
      std::make_unique<ObjectWithTrackedRefs>();

  TimeTicks begin = TimeTicks::Now();

  thread.task_runner()->PostDelayedTask(
      FROM_HERE,
      BindOnce(
          [](TrackedRef<ObjectWithTrackedRefs> obj) {
            // By the time this kicks in, the object should already be under
            // destruction, but blocked on this TrackedRef being released. This
            // is technically racy (main thread has to run |obj.reset()| and
            // this thread has to observe the side-effects before this delayed
            // task fires). If this ever flakes this expectation could be turned
            // into a while(!obj->under_destruction()); but until that's proven
            // flaky in practice, this expectation is more readable and
            // diagnosable then a hang.
            EXPECT_TRUE(obj->under_destruction());
          },
          obj->GetTrackedRef()),
      TestTimeouts::tiny_timeout());

  // This should kick off destruction but block until the above task resolves
  // and releases the TrackedRef.
  obj.reset();
  EXPECT_GE(TimeTicks::Now() - begin, TestTimeouts::tiny_timeout());
}