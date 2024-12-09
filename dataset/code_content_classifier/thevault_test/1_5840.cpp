static void RunWithManyThreads(boost::function<void()>* f, int num_threads) {
  vector<scoped_refptr<kudu::Thread> > threads;
  for (int i = 0; i < num_threads; i++) {
    scoped_refptr<kudu::Thread> new_thread;
    CHECK_OK(kudu::Thread::Create("test", StringPrintf("thread%d", i),
          *f, &new_thread));
    threads.push_back(new_thread);
  }
  for (int i = 0; i < num_threads; i++) {
    ASSERT_OK(ThreadJoiner(threads[i].get()).Join());
  }
}