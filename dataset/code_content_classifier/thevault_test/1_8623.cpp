raw_handler_ptr(alloc_context_type& alloc_context)
    : alloc_context_(alloc_context)
    , pointer_(static_cast<pointer_type>(
          ma_handler_alloc_helpers::allocate(value_size, alloc_context)))
  {
  }