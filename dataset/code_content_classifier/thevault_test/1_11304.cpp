fiber_buffered_exchange(distributed_control& dc,
                      const size_t max_buffer_size = DEFAULT_BUFFERED_EXCHANGE_SIZE) :
      rpc(dc, this),
      max_buffer_size(max_buffer_size) {
       send_buffers.resize(fiber_control::get_instance().num_workers());
       recv_buffers.resize(fiber_control::get_instance().num_workers());
       for (size_t i = 0;i < send_buffers.size(); ++i) {
         send_buffers[i].resize(dc.numprocs());
         for (size_t j = 0;j < send_buffers[i].size(); ++j) {
           send_buffers[i][j].oarc = NULL;
           send_buffers[i][j].numinserts = 0;
         }
       }
       rpc.barrier();
      }