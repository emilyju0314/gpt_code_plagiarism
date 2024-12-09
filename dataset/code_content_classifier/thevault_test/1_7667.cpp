static Status CopyRowToArena(const Slice &row,
                             const Schema &schema,
                             Arena *dst_arena,
                             ContiguousRow *copied) {
  Slice row_data;

  // Copy the direct row data to arena
  if (!dst_arena->RelocateSlice(row, &row_data)) {
    return STATUS(IOError, "no space for row data in arena");
  }

  copied->Reset(row_data.mutable_data());
  RETURN_NOT_OK(RelocateIndirectDataToArena(copied, dst_arena));
  return Status::OK();
}