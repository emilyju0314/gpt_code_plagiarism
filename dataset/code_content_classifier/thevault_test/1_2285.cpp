__EXPORT
zx_status_t zx_handle_replace(zx_handle_t handle, zx_rights_t rights, zx_handle_t* out) {
  if (HandleTable::IsValidFakeHandle(handle)) {
    fbl::RefPtr<Object> obj;
    zx_status_t status = FakeHandleTable().Get(handle, &obj);
    ftracef("handle = %#x, obj = %p, status = %d\n", handle, obj.get(), status);
    ZX_ASSERT_MSG(status == ZX_OK, "fake_%s: Bad handle = %#x, status = %d\n", __func__, handle,
                  status);
    ZX_ASSERT(FakeHandleTable().Add(std::move(obj), out) == ZX_OK);
    ZX_ASSERT(FakeHandleTable().Remove(handle) == ZX_OK);
    return ZX_OK;
  }

  return _zx_handle_replace(handle, rights, out);
}