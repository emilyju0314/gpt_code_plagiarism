void Users::create_sig_chain(const SecureString& strUsername, const SecureString& strPassword,
                                   const SecureString& strPin, TAO::Ledger::Transaction& tx)
        {
            /* Generate the signature chain. */
            memory::encrypted_ptr<TAO::Ledger::SignatureChain> user = new TAO::Ledger::SignatureChain(strUsername, strPassword);

            /* Get the Genesis ID. */
            uint256_t hashGenesis = user->Genesis();

            /* Check for duplicates in ledger db. */
            if(LLD::Ledger->HasGenesis(hashGenesis) || TAO::Ledger::mempool.Has(hashGenesis))
            {
                user.free();
                throw APIException(-130, "Account already exists");
            }

            /* Create the transaction. */
            if(!Users::CreateTransaction(user, strPin, tx))
            {
                user.free();
                throw APIException(-17, "Failed to create transaction");
            }

            /* Generate register address for the trust account deterministically so that we can retrieve it easily later. */
            TAO::Register::Address hashRegister = TAO::Register::Address(std::string("trust"), hashGenesis, TAO::Register::Address::TRUST);

            /* Add a Name record for the trust account */
            tx[0] = Names::CreateName(user->Genesis(), "trust", "", hashRegister);

            /* Set up tx operation to create the trust account register at the same time as sig chain genesis. */
            tx[1] << uint8_t(TAO::Operation::OP::CREATE)      << hashRegister
                  << uint8_t(TAO::Register::REGISTER::OBJECT) << TAO::Register::CreateTrust().GetState();

            /* Generate a random hash for the default account register address */
            hashRegister = TAO::Register::Address(TAO::Register::Address::ACCOUNT);

            /* Add a Name record for the default account */
            tx[2] = Names::CreateName(user->Genesis(), "default", "", hashRegister);

            /* Add the default account register operation to the transaction */
            tx[3] << uint8_t(TAO::Operation::OP::CREATE)      << hashRegister
                  << uint8_t(TAO::Register::REGISTER::OBJECT) << TAO::Register::CreateAccount(0).GetState();

            /* Generate register address for crypto register deterministically */
            hashRegister = TAO::Register::Address(std::string("crypto"), hashGenesis, TAO::Register::Address::CRYPTO);

            /* The key type to use for the crypto keys */
            uint8_t nKeyType = config::GetBoolArg("-falcon") ? TAO::Ledger::SIGNATURE::FALCON : TAO::Ledger::SIGNATURE::BRAINPOOL;

            /* Create the crypto object. */
            TAO::Register::Object crypto = TAO::Register::CreateCrypto(
                                                user->KeyHash("auth", 0, strPin, nKeyType),
                                                0, //lisp key disabled for now
                                                user->KeyHash("network", 0, strPin, nKeyType),
                                                user->KeyHash("sign", 0, strPin, nKeyType),
                                                0, //verify key disabled for now
                                                0, //cert disabled for now
                                                0, //app1 disabled for now
                                                0, //app2 disabled for now
                                                0);//app3 disabled for now

            /* Add the crypto register operation to the transaction */
            tx[4] << uint8_t(TAO::Operation::OP::CREATE)      << hashRegister
                  << uint8_t(TAO::Register::REGISTER::OBJECT) << crypto.GetState();

            /* Add the fee */
            AddFee(tx);

            /* Calculate the prestates and poststates. */
            if(!tx.Build())
            {
                user.free();
                throw APIException(-30, "Operations failed to execute");
            }

            /* Sign the transaction. */
            if(!tx.Sign(user->Generate(tx.nSequence, strPin)))
            {
                user.free();
                throw APIException(-31, "Ledger failed to sign transaction");
            }

            /* Free the sigchain. */
            user.free();

            /* Execute the operations layer. */
            if(!TAO::Ledger::mempool.Accept(tx))
                throw APIException(-32, "Failed to accept");
        }