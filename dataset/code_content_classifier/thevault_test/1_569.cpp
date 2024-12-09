boost::system::error_code assign(implementation_type& impl,
      const native_type& native_handle, boost::system::error_code& ec)
  {
    return service_impl_.assign(impl, native_handle, ec);
  }