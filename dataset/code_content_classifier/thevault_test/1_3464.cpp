void runtime::init_security()
    {
        // this is the AGAS bootstrap node (node zero)
        if (ini_.get_agas_service_mode() == agas::service_mode_bootstrap)
        {
            components::security::signed_certificate cert;

            util::security::root_certificate_authority& root_ca =
                security_data_->root_certificate_authority_;

            {
                // Initialize the root-CA
                std::lock_guard<lcos::local::spinlock> l(security_mtx_);

                root_ca.initialize();

                HPX_ASSERT(security_data_->cert_store_.get() == 0);
                security_data_->cert_store_.reset(
                    new components::security::certificate_store(
                        root_ca.get_certificate()));

                // initialize the sub-CA
                util::security::subordinate_certificate_authority& sub_ca =
                    security_data_->subordinate_certificate_authority_;
                sub_ca.initialize();

                // sign the sub-CA's certificate
                components::security::signed_certificate_signing_request csr =
                    sub_ca.get_certificate_signing_request();
                cert = root_ca.sign_certificate_signing_request(csr);

                // finalize initialization of sub-CA
                security_data_->locality_certificate_ = cert;
                sub_ca.set_certificate(cert);
            }

            // add the sub-CA's certificate to the local certificate store
            add_locality_certificate(cert);

            LSEC_(debug) << (boost::format(
                "runtime::init_security: initialized root certificate authority: %1%") %
                root_ca.get_certificate());
        }
    }