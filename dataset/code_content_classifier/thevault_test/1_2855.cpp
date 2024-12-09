static void Initial() {
  static bool init = false;
  if (!init) {
    static EngineImplRegister<KVEngine, PMemKVDK> pmem_kvdk("kvdk");
    static EngineImplRegister<KVEngine, MemoryEngine> memory_engine("memory");
#if defined(BUILD_ROCKSDB)
    static EngineImplRegister<KVEngine, RocksEngine> rocks_engine("rocksdb");
#endif
    init = true;
  }
}