__EXPORT
zx_status_t zx_handle_close(zx_handle_t handle) {
  if (HandleTable::IsValidFakeHandle(handle)) {
    fbl::RefPtr<Object> obj;
    zx_status_t status = FakeHandleTable().Get(handle, &obj);
    ftracef("handle = %#x, obj = %p, status = %d\n", handle, obj.get(), status);
    ZX_ASSERT_MSG(status == ZX_OK, "fake_%s: Bad handle = %#x, status = %d\n", __func__, handle,
                  status);
    return FakeHandleTable().Remove(handle);
  }
  return _zx_handle_close(handle);
}