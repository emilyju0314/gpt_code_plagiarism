bool ChainState::Synchronizing()
        {
            bool fSynchronizing = true;
            /* Persistent switch once synchronized. */
            //if(!fSynchronizing.load())
            //    return false;

            #ifndef UNIT_TESTS

            /* Check for null best state. */
            if(stateBest.load().IsNull())
                return true;

            /* Check if there's been a new block. */
            static memory::atomic<uint1024_t> hashLast;
            static std::atomic<uint64_t> nLastTime;
            if(hashBestChain.load() != hashLast.load())
            {
                hashLast = hashBestChain.load();
                nLastTime = runtime::unifiedtimestamp();
            }

            /* Special testnet rule. s*/
            if(config::fTestNet.load())
            {
                bool fLocalTestnet = config::fTestNet.load() && !config::GetBoolArg("-dns", true);
                bool fHasConnections = LLP::TRITIUM_SERVER && LLP::TRITIUM_SERVER->GetConnectionCount() > 0;
                /* Set the synchronizing flag. */
                fSynchronizing =
                (
                    /* If using main testnet then rely on the LLP synchronized flag */
                    (!fLocalTestnet && !LLP::TritiumNode::fSynchronized.load() 
                        && stateBest.load().GetBlockTime() < runtime::unifiedtimestamp() - 20 * 60) 
                    
                    /* If local testnet with connections then rely on LLP flag  */
                    || (fLocalTestnet && fHasConnections && !LLP::TritiumNode::fSynchronized.load() )

                    /* If local testnet with no connections then assume sync'd if the last block was more than 30s ago 
                       and block age is more than 20 mins, which gives us a 30s window to connect to a local peer */
                    || (fLocalTestnet && !fHasConnections 
                        && runtime::unifiedtimestamp() - nLastTime < 30
                        && stateBest.load().GetBlockTime() < runtime::unifiedtimestamp() - 20 * 60)
                );

                return fSynchronizing;
            }

            /* Check if block has been created within 60 minutes. */
            fSynchronizing =
            (
                (!LLP::TritiumNode::fSynchronized.load() &&
                (stateBest.load().GetBlockTime() < runtime::unifiedtimestamp() - 60 * 60))
            );

            return fSynchronizing;

            /* On unit tests, always keep Synchronizing off. */
            #else
            _unused(fSynchronizing); //suppress compiler warnings
            return false;
            #endif
        }