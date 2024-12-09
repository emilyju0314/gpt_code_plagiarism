void Users::auto_login()
        {
            /* Flag indicating that the auto login has successfully run.  Once it has run successfully once it will not run again
               for the lifespan of the application, to avoid auto-logging you back in if you intentionally log out. */
            static bool fAutoLoggedIn = false;
            try
            {
                /* If we haven't already logged in at least once, are configured for auto login, and are not currently logged in */
                if(!fAutoLoggedIn && config::GetBoolArg("-autologin") && !config::fMultiuser.load() && !LoggedIn())
                {
                    /* Keep a the credentials in secure allocated strings. */
                    SecureString strUsername = config::GetArg("-username", "").c_str();
                    SecureString strPassword = config::GetArg("-password", "").c_str();
                    SecureString strPin = config::GetArg("-pin", "").c_str();

                    /* Check we have user/pass/pin */
                    if(strUsername.empty() || strPassword.empty() || strPin.empty())
                        throw APIException(-203, "Autologin missing username/password/pin");

                    /* Create the sigchain. */
                    memory::encrypted_ptr<TAO::Ledger::SignatureChain> user =
                        new TAO::Ledger::SignatureChain(strUsername.c_str(), strPassword.c_str());

                    /* Get the genesis ID. */
                    uint256_t hashGenesis = user->Genesis();

                    /* See if the sig chain exists */
                    if(!LLD::Ledger->HasGenesis(hashGenesis) && !TAO::Ledger::mempool.Has(hashGenesis))
                    {
                        /* If it doesn't exist then create it if configured to do so */
                        if(config::GetBoolArg("-autocreate"))
                        {
                            /* Testnet is considered local if no dns is being used or if using a private network */
                            bool fLocalTestnet = config::fTestNet.load()
                                && (!config::GetBoolArg("-dns", true) || config::GetBoolArg("-private"));

                            /* Can only create user if synced and (if not local) have connections.
                             * Return without create/login if cannot create, yet. It will have to try again.
                             */
                            if(TAO::Ledger::ChainState::Synchronizing()
                            || (LLP::TRITIUM_SERVER->GetConnectionCount() == 0 && !fLocalTestnet))
                            {
                                user.free();
                                return;
                            }

                            /* The genesis transaction  */
                            TAO::Ledger::Transaction tx;

                            /* Create the sig chain genesis transaction */
                            create_sig_chain(strUsername, strPassword, strPin, tx);

                            /* Display that login was successful. */
                            debug::log(0, "Auto-Create Successful");
                        }
                        else
                            throw APIException(-203, "Autologin user not found");
                    }

                    /* Check for duplicates in ledger db. */
                    TAO::Ledger::Transaction txPrev;

                    /* Get the last transaction. */
                    uint512_t hashLast;
                    if(!LLD::Ledger->ReadLast(hashGenesis, hashLast, TAO::Ledger::FLAGS::MEMPOOL))
                    {
                        user.free();
                        throw APIException(-138, "No previous transaction found");
                    }

                    /* Get previous transaction */
                    if(!LLD::Ledger->ReadTx(hashLast, txPrev, TAO::Ledger::FLAGS::MEMPOOL))
                    {
                        user.free();
                        throw APIException(-138, "No previous transaction found");
                    }

                    /* Genesis Transaction. */
                    TAO::Ledger::Transaction tx;
                    tx.NextHash(user->Generate(txPrev.nSequence + 1, config::GetArg("-pin", "").c_str(), false), txPrev.nNextType);

                    /* Check for consistency. */
                    if(txPrev.hashNext != tx.hashNext)
                    {
                        user.free();
                        throw APIException(-139, "Invalid credentials");
                    }

                    /* Setup the account. */
                    {
                        LOCK(MUTEX);
                        mapSessions.emplace(0, std::move(user));
                    }

                    /* Extract the PIN. */
                    if(!pActivePIN.IsNull())
                        pActivePIN.free();

                    /* The unlock actions to apply for autologin.  NOTE we do NOT unlock for transactions */
                    uint8_t nUnlockActions = TAO::Ledger::PinUnlock::UnlockActions::MINING
                                           | TAO::Ledger::PinUnlock::UnlockActions::NOTIFICATIONS
                                           | TAO::Ledger::PinUnlock::UnlockActions::STAKING;

                    /* Set account to unlocked. */
                    pActivePIN = new TAO::Ledger::PinUnlock(config::GetArg("-pin", "").c_str(), nUnlockActions);

                    /* Display that login was successful. */
                    debug::log(0, "Auto-Login Successful");

                    /* Set the flag so that we don't attempt to log in again */
                    fAutoLoggedIn = true;

                    /* Start the stake minter if successful login. */
                    TAO::Ledger::TritiumMinter::GetInstance().Start();
                }
            }
            catch(const APIException& e)
            {
                debug::error(FUNCTION, e.what());
            }

        }