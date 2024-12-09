__EXPORT
zx_status_t zx_object_get_child(zx_handle_t handle, uint64_t koid, zx_rights_t rights,
                                zx_handle_t* out) {
  if (!HandleTable::IsValidFakeHandle(handle)) {
    return _zx_object_get_child(handle, koid, rights, out);
  }

  fbl::RefPtr<Object> obj;
  zx_status_t status = FakeHandleTable().Get(handle, &obj);
  ZX_ASSERT_MSG(status == ZX_OK, "fake_%s: Bad handle = %#x, status = %d\n", __func__, handle,
                status);
  return obj->get_child(handle, koid, rights, out);
}