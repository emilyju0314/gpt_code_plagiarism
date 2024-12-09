handle_t(rmm::cuda_stream_view stream_view                  = rmm::cuda_stream_per_thread,
           std::shared_ptr<rmm::cuda_stream_pool> stream_pool = {nullptr})
    : dev_id_([]() -> int {
        int cur_dev = -1;
        RAFT_CUDA_TRY(cudaGetDevice(&cur_dev));
        return cur_dev;
      }()),
      stream_view_{stream_view},
      stream_pool_{stream_pool}
  {
    create_resources();
  }