void add_to_request_queue(future_data_ptr data)
        {
            // place this future data request in our queue for handling
            get_request_queue().enqueue(data);
            ++(get_mpi_info().request_queue_size_);

            mpi_debug.debug(debug::str<>("request queued"), get_mpi_info(),
                "request", debug::hex<8>(data->request_));
        }