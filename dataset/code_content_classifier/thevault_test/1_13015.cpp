void MemoryDumpManager::CreateLocalDumpPoint() {
  AutoLock lock(lock_);
  scoped_ptr<ProcessMemoryDump> pmd(new ProcessMemoryDump());

  for (MemoryDumpProvider* dump_provider : dump_providers_enabled_) {
    dump_provider->DumpInto(pmd.get());
  }

  scoped_refptr<TracedValue> value(new TracedValue());
  pmd->AsValueInto(value.get());
  // TODO(primiano): add the dump point to the trace at this point.
}