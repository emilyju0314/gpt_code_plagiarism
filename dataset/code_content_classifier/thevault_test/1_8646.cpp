void RenderFrame(InternalScopedString *buffer, const char *format, int frame_no,
                 const AddressInfo &info, bool vs_style,
                 const char *strip_path_prefix, const char *strip_func_prefix) {
  buffer->append(kFormatFrame, frame_no, info.address);
}