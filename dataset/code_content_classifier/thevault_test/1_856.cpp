inline void wait()
    {
        hpx::util::yield_while([]() {
            std::unique_lock<detail::mutex_type> lk(
                detail::get_vector_mtx(), std::try_to_lock);
            if (!lk.owns_lock())
            {
                return true;
            }
            return (detail::get_mpi_info().active_futures_size_ > 0);
        });
    }