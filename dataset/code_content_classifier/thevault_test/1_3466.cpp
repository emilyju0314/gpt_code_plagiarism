void runtime::add_locality_certificate(
        components::security::signed_certificate const& cert)
    {
        HPX_ASSERT(security_data_.get() != 0);

        LSEC_(debug) << (boost::format(
            "runtime::add_locality_certificate: locality(%1%): adding locality "
            "certificate: %2%") % here() % cert);

        std::lock_guard<lcos::local::spinlock> l(security_mtx_);
        HPX_ASSERT(0 != security_data_->cert_store_.get());
        // should have been created
        security_data_->cert_store_->insert(cert);
    }