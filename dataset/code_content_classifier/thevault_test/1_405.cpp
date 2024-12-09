json::json Finance::Info(const json::json& params, bool fHelp)
        {
            json::json ret;

            /* Get the session to be used for this API call */
            uint256_t nSession = users->GetSession(params);

            /* Get the user account. */
            memory::encrypted_ptr<TAO::Ledger::SignatureChain>& user = users->GetAccount(nSession);
            if(!user)
                throw APIException(-10, "Invalid session ID");

            /* Retrieve the trust register address, which is based on the users genesis */
            TAO::Register::Address hashRegister = TAO::Register::Address(std::string("trust"), user->Genesis(), TAO::Register::Address::TRUST);

            /* Get trust account. Any trust account that has completed Genesis will be indexed. */
            TAO::Register::Object trust;

            /* Check for trust index. */
            if(!LLD::Register->ReadTrust(user->Genesis(), trust)
            && !LLD::Register->ReadState(hashRegister, trust, TAO::Ledger::FLAGS::MEMPOOL))
                throw APIException(-70, "Trust account not found");

            /* Parse the object. */
            if(!trust.Parse())
                throw APIException(-71, "Unable to parse trust account.");

            /* Check the object standard. */
            if(trust.Standard() != TAO::Register::OBJECTS::TRUST)
                throw APIException(-72, "Register is not a trust account");

            /* Check the account is a NXS account */
            if(trust.get<uint256_t>("token") != 0)
                throw APIException(-73, "Trust account is not a NXS account.");

            /* Set trust account values for return data */
            ret["address"] = hashRegister.ToString();

            ret["balance"] = (double)trust.get<uint64_t>("balance") / TAO::Ledger::NXS_COIN;

            ret["stake"] = (double)trust.get<uint64_t>("stake") / TAO::Ledger::NXS_COIN;

            /* Trust is returned as a percentage of maximum */
            uint64_t nTrustScore = trust.get<uint64_t>("trust");

            ret["trust"] = nTrustScore;

            TAO::Ledger::StakeMinter& stakeMinter = TAO::Ledger::TritiumMinter::GetInstance();

            /* Indexed trust account has genesis */
            bool fTrustIndexed = LLD::Register->HasTrust(user->Genesis());

            ret["new"] = (bool)(!fTrustIndexed);

            /* Return whether stake minter is started and actively running. */
            ret["staking"] = (bool)(stakeMinter.IsStarted() && trust.hashOwner == user->Genesis());

            /* Need the stake minter running for accessing current staking metrics.
             * Verifying current user ownership of trust account is a sanity check.
             */
            if(stakeMinter.IsStarted() && trust.hashOwner == user->Genesis())
            {
                /* The trust account is on hold when it does not have genesis, and is waiting to reach minimum age to stake */
                bool fOnHold = (!fTrustIndexed && stakeMinter.IsWaitPeriod());

                /* When trust account is on hold pending minimum age, also return the time remaining in hold period. */
                ret["onhold"] = (bool)(fOnHold);
                if(fOnHold)
                    ret["holdtime"] = (uint64_t)stakeMinter.GetWaitTime();

                /* If stake minter is running, get current stake rate it is using. */
                ret["stakerate"] = stakeMinter.GetStakeRatePercent();

                /* Other staking metrics also are available with running minter */
                ret["trustweight"] = stakeMinter.GetTrustWeightPercent();
                ret["blockweight"] = stakeMinter.GetBlockWeightPercent();

                /* Raw trust weight and block weight total to 100, so can use the total as a % directly */
                ret["stakeweight"] = stakeMinter.GetTrustWeight() + stakeMinter.GetBlockWeight();
            }
            else
            {
                /* When stake minter not running, return latest known value calculated from trust score (as an annual percent). */
                ret["stakerate"] = TAO::Ledger::StakeRate(nTrustScore, (nTrustScore == 0)) * 100.0;

                /* Other staking metrics not available if stake minter not running */
                ret["trustweight"] = 0.0;
                ret["blockweight"] = 0.0;
                ret["stakeweight"] = 0.0;
            }

            TAO::Ledger::StakeChange stakeChange;
            if(LLD::Local->ReadStakeChange(user->Genesis(), stakeChange) && !stakeChange.fProcessed
            && (stakeChange.nExpires == 0 || stakeChange.nExpires > runtime::unifiedtimestamp()))
            {
                ret["change"] = true;
                ret["amount"] = (double)stakeChange.nAmount / TAO::Ledger::NXS_COIN;
                ret["requested"] = stakeChange.nTime;
                ret["expires"] = stakeChange.nExpires;
            }
            else
                ret["change"] = false;

            /* If the caller has requested to filter on a fieldname then filter out the json response to only include that field */
            FilterResponse(params, ret);

            return ret;
        }