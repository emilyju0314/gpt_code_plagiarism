void WriteDescriptor32(MemoryFake* memory, uint64_t addr, uint32_t entry) {
  // Format of the 32 bit JITDescriptor structure:
  //   uint32_t version
  memory->SetData32(addr, 1);
  //   uint32_t action_flag
  memory->SetData32(addr + 4, 0);
  //   uint32_t relevant_entry
  memory->SetData32(addr + 8, 0);
  //   uint32_t first_entry
  memory->SetData32(addr + 12, entry);
}