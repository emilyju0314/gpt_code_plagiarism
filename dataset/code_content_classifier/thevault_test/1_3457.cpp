void id_type_impl::preprocess_gid(serialization::output_archive& ar) const
        {
            // unmanaged gids do not require any special handling
            if (unmanaged == type_)
            {
                return;
            }

            if (ar.has_gid(*this))
            {
                return;
            }

            HPX_ASSERT(has_credits(*this));

            // Request new credits from AGAS if needed (i.e. the remainder
            // of the credit splitting is equal to one).
            if (managed == type_)
            {
                ar.await_future(
                    split_gid_if_needed(const_cast<id_type_impl&>(*this)).then(
                        [&ar, this](hpx::future<gid_type> && gid_future)
                        {
                            ar.add_gid(*this, gid_future.get());
                        }
                    )
                );
                return;
            }
        }