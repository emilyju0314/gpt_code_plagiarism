void MultiThreadedMetricsTest::RegisterCounters(
    const scoped_refptr<MetricEntity>& metric_entity,
    const string& name_prefix,
    int num_counters) {
  uint64_t tid = Env::Default()->gettid();
  for (int i = 0; i < num_counters; i++) {
    // This loop purposefully leaks metrics prototypes, because the metrics system
    // expects the prototypes and their names to live forever. This is the only
    // place we dynamically generate them for the purposes of a test, so it's easier
    // to just leak them than to figure out a way to manage lifecycle of objects that
    // are typically static.
    ScopedLeakCheckDisabler disabler;

    string name = strings::Substitute("$0-$1-$2", name_prefix, tid, i);
    auto proto = new CounterPrototype(MetricPrototype::CtorArgs(
        "test_entity", strdup(name.c_str()), "Test Counter",
        MetricUnit::kOperations, "test counter"));
    proto->Instantiate(metric_entity)->Increment();
  }
}