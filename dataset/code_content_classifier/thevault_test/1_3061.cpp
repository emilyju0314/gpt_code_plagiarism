static bool isObjectSize(const Value *V, uint64_t Size, const DataLayout &DL,
                         const TargetLibraryInfo &TLI, bool NullIsValidLoc) {
  uint64_t ObjectSize = getObjectSize(V, DL, TLI, NullIsValidLoc);
  return ObjectSize != MemoryLocation::UnknownSize && ObjectSize == Size;
}