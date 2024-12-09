void Unwinder::FillInDexFrame() {
  size_t frame_num = frames_.size();
  frames_.resize(frame_num + 1);
  FrameData* frame = &frames_.at(frame_num);
  frame->num = frame_num;

  uint64_t dex_pc = regs_->dex_pc();
  frame->pc = dex_pc;
  frame->sp = regs_->sp();

  MapInfo* info = maps_->Find(dex_pc);
  if (info != nullptr) {
    frame->map_start = info->start();
    frame->map_end = info->end();
    // Since this is a dex file frame, the elf_start_offset is not set
    // by any of the normal code paths. Use the offset of the map since
    // that matches the actual offset.
    frame->map_object_start_offset = info->offset();
    frame->map_exact_offset = info->offset();
    frame->map_load_bias = info->load_bias();
    frame->map_flags = info->flags();
    if (resolve_names_) {
      frame->map_name = info->name();
    }
    frame->rel_pc = dex_pc - info->start();
  } else {
    frame->rel_pc = dex_pc;
    warnings_ |= WARNING_DEX_PC_NOT_IN_MAP;
    return;
  }

  if (!resolve_names_) {
    return;
  }

#if defined(DEXFILE_SUPPORT)
  if (dex_files_ == nullptr) {
    return;
  }

  dex_files_->GetFunctionName(maps_, dex_pc, &frame->function_name, &frame->function_offset);
#endif
}