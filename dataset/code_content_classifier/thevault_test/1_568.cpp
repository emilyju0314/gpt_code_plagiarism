explicit random_access_handle_service(boost::asio::io_service& io_service)
    : boost::asio::detail::service_base<
        random_access_handle_service>(io_service),
      service_impl_(boost::asio::use_service<service_impl_type>(io_service))
  {
  }