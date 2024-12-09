explicit raw_socket_service(boost::asio::io_service& io_service)
    : boost::asio::detail::service_base<
        raw_socket_service<Protocol> >(io_service),
      service_impl_(boost::asio::use_service<service_impl_type>(io_service))
  {
  }