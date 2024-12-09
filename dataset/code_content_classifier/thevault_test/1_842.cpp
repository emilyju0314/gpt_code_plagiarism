void hpx_MPI_Handler(MPI_Comm*, int* errorcode, ...)
        {
            mpi_debug.debug(debug::str<>("hpx_MPI_Handler"));
            HPX_THROW_EXCEPTION(invalid_status, "hpx_MPI_Handler",
                detail::error_message(*errorcode));
        }