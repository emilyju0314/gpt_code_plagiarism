handler_ptr(raw_ptr_type& raw_ptr)
    : alloc_context_(detail::addressof(raw_ptr.alloc_context_))
    , pointer_(new (raw_ptr.pointer_) value_type)
  {
    raw_ptr.pointer_ = 0;
  }