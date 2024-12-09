bool Users::sanitize_contract(TAO::Operation::Contract& contract, std::map<uint256_t, TAO::Register::State> &mapStates)
        {
            /* Return flag */
            bool fSanitized = false;

            /* Lock the mempool at this point so that we can build and execute inside a mempool transaction */
            RLOCK(TAO::Ledger::mempool.MUTEX);

            try
            {
                /* Start a ACID transaction (to be disposed). */
                LLD::TxnBegin(TAO::Ledger::FLAGS::MEMPOOL);

                fSanitized = TAO::Register::Build(contract, mapStates, TAO::Ledger::FLAGS::MEMPOOL)
                             && TAO::Operation::Execute(contract, TAO::Ledger::FLAGS::MEMPOOL);

                /* Abort the mempool ACID transaction once the contract is sanitized */
                LLD::TxnAbort(TAO::Ledger::FLAGS::MEMPOOL);

            }
            catch(const std::exception& e)
            {
                /* Abort the mempool ACID transaction */
                LLD::TxnAbort(TAO::Ledger::FLAGS::MEMPOOL);

                /* Log the error and attempt to continue processing */
                debug::error(FUNCTION, e.what());
            }

            return fSanitized;
        }