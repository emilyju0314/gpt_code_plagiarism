void TcpConnAsync::do_read_head() {

    if (get_conn_stat() != ConnStat::kWorking) {
        roo::log_err("Socket Status Error: %d", get_conn_stat());
        return;
    }

    if (was_ops_cancelled()) {
        return;
    }

    // roo::log_info("strand read read_until ... in thread %#lx", (long)pthread_self());

    set_session_cancel_timeout();
    async_read_until(*socket_, request_,
                     http_proto::header_crlfcrlf_str,
                     strand_->wrap(
                         std::bind(&TcpConnAsync::read_head_handler,
                                   shared_from_this(),
                                   std::placeholders::_1,
                                   std::placeholders::_2)));
    return;
}