static std::vector<fuchsia::sysmem::BufferCollectionTokenSyncPtr> DuplicateToken(
    const fuchsia::sysmem::BufferCollectionTokenSyncPtr& input, uint32_t count) {
  std::vector<fuchsia::sysmem::BufferCollectionTokenSyncPtr> output;
  for (uint32_t i = 0; i < count; ++i) {
    fuchsia::sysmem::BufferCollectionTokenSyncPtr new_token;
    zx_status_t status =
        input->Duplicate(std::numeric_limits<uint32_t>::max(), new_token.NewRequest());
    if (status != ZX_OK) {
      FXL_LOG(ERROR) << "Unable to duplicate sysmem token:" << status;
      return std::vector<fuchsia::sysmem::BufferCollectionTokenSyncPtr>();
    }
    output.push_back(std::move(new_token));
  }
  zx_status_t status = input->Sync();
  if (status != ZX_OK) {
    FXL_LOG(ERROR) << "Unable to sync sysmem token:" << status;
    return std::vector<fuchsia::sysmem::BufferCollectionTokenSyncPtr>();
  }
  return output;
}