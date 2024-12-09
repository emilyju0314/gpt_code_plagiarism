__EXPORT
zx_status_t zx_handle_close_many(const zx_handle_t* handles, size_t num_handles) {
  for (size_t i = 0; i < num_handles; i++) {
    zx_handle_close(handles[i]);
  }

  return ZX_OK;
}