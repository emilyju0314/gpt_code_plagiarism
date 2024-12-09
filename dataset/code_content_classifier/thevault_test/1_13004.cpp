bool MallocDumpProvider::OnMemoryDump(ProcessMemoryDump* pmd) {
  struct mallinfo info = mallinfo();
  DCHECK_GE(info.arena + info.hblkhd, info.uordblks);

  MemoryAllocatorDump* dump = pmd->CreateAllocatorDump("malloc");
  if (!dump)
    return false;

  // When the system allocator is implemented by tcmalloc, the total physical
  // size is given by |arena| and |hblkhd| is 0. In case of Android's jemalloc
  // |arena| is 0 and the outer pages size is reported by |hblkhd|. In case of
  // dlmalloc the total is given by |arena| + |hblkhd|.
  // For more details see link: http://goo.gl/fMR8lF.
  dump->AddScalar(MemoryAllocatorDump::kNameOuterSize,
                  MemoryAllocatorDump::kUnitsBytes, info.arena + info.hblkhd);

  // Total allocated space is given by |uordblks|.
  dump->AddScalar(MemoryAllocatorDump::kNameInnerSize,
                  MemoryAllocatorDump::kUnitsBytes, info.uordblks);

  return true;
}