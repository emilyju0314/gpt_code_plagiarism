inline future<void> make_ready_future()
    {
        typedef lcos::detail::future_data<void> shared_state;

        boost::intrusive_ptr<shared_state> p(new shared_state());
        p->set_value(hpx::util::unused);

        return hpx::traits::future_access<future<void> >::create(std::move(p));
    }