void runtime::store_root_certificate(
        components::security::signed_certificate const& root_cert)
    {
        // Only worker nodes need to store the root certificate at this
        // point, the root locality was already initialized (see above).
        if (ini_.get_agas_service_mode() != agas::service_mode_bootstrap)
        {
            LSEC_(debug) << (boost::format(
                "runtime::store_root_certificate: received certificate "
                "root-CA(%1%)") % root_cert);

            // initialize our certificate store
            std::lock_guard<lcos::local::spinlock> l(security_mtx_);

            HPX_ASSERT(security_data_->cert_store_.get() == 0);
            security_data_->cert_store_.reset(
                new components::security::certificate_store(root_cert));
        }
    }