bool TritiumMinter::CreateCandidateBlock(const memory::encrypted_ptr<TAO::Ledger::SignatureChain>& user,
                                                 const SecureString& strPIN)
        {
            static uint32_t nCounter = 0; //Prevents log spam during wait period

            /* Reset any prior value of trust score, block age, and stake update amount */
            nTrust = 0;
            nBlockAge = 0;

            /* Create the block to work on */
            block = TritiumBlock();

            /* Create the base Tritium block. */
            if(!TAO::Ledger::CreateStakeBlock(user, strPIN, block, fGenesis))
                return debug::error(FUNCTION, "Unable to create candidate block");

            if(!fGenesis)
            {
                /* Staking Trust for existing trust account */
                uint64_t nTrustPrev  = account.get<uint64_t>("trust");
                uint64_t nStake      = account.get<uint64_t>("stake");
                int64_t nStakeChange = 0;

                /* Get the previous stake tx for the trust account. */
                uint512_t hashLast;
                if(!FindLastStake(user->Genesis(), hashLast))
                    return debug::error(FUNCTION, "Failed to get last stake for trust account");

                /* Find a stake change request. */
                if(!FindStakeChange(user->Genesis(), hashLast))
                {
                    debug::log(2, FUNCTION, "Failed to retrieve stake change request");
                    fStakeChange = false;
                    stakeChange.SetNull();
                }

                /* Adjust the stake change from database. */
                if(fStakeChange)
                    nStakeChange = stakeChange.nAmount;

                /* Check for available stake. */
                if(nStake == 0 && nStakeChange == 0)
                {
                    /* Trust account has no stake balance. Increase sleep time to wait for balance. */
                    nSleepTime = 5000;

                    /* Update log every 60 iterations (5 minutes) */
                    if((++nCounter % 60) == 0)
                        debug::log(0, FUNCTION, "Stake Minter: Trust account has no stake.");

                    return false;
                }

                /* Get the block containing the last stake tx for the trust account. */
                stateLast = BlockState();
                if(!LLD::Ledger->ReadBlock(hashLast, stateLast))
                    return debug::error(FUNCTION, "Failed to get last block for trust account");

                /* Get block previous to our candidate. */
                BlockState statePrev = BlockState();
                if(!LLD::Ledger->ReadBlock(block.hashPrevBlock, statePrev))
                    return debug::error(FUNCTION, "Failed to get previous block");

                /* Calculate time since last stake block (block age = age of previous stake block at time of current stateBest). */
                nBlockAge = statePrev.GetBlockTime() - stateLast.GetBlockTime();

                /* Check for previous version 7 and current version 8. */
                uint64_t nTrustRet = 0;
                if(block.nVersion == 8 && stateLast.nVersion == 7 && !CheckConsistency(hashLast, nTrustRet))
                    nTrust = GetTrustScore(nTrustRet, nBlockAge, nStake, nStakeChange, block.nVersion);
                else //when not consistency check, calculate like normal
                    nTrust = GetTrustScore(nTrustPrev, nBlockAge, nStake, nStakeChange, block.nVersion);

                /* Initialize block producer for Trust operation with hashLastTrust, new trust score.
                 * The coinstake reward will be added based on time when block is found.
                 */
                block.producer[0] << uint8_t(TAO::Operation::OP::TRUST) << hashLast << nTrust << nStakeChange;
            }
            else
            {
                /* Looking to stake Genesis for new trust account */

                /* Validate that have assigned balance for Genesis */
                if(account.get<uint64_t>("balance") == 0)
                {
                    /* Wallet has no balance, or balance unavailable for staking. Increase sleep time to wait for balance. */
                    nSleepTime = 5000;

                    /* Update log every 60 iterations (5 minutes) */
                    if((nCounter % 60) == 0)
                        debug::log(0, FUNCTION, "Stake Minter: Trust account has no balance for Genesis.");

                    ++nCounter;

                    return false;
                }

                /* Pending stake change request not allowed while staking Genesis */
                fStakeChange = false;
                if(LLD::Local->ReadStakeChange(user->Genesis(), stakeChange))
                {
                    debug::log(0, FUNCTION, "Stake Minter: Stake change request not allowed for trust account Genesis...removing");

                    if(!LLD::Local->EraseStakeChange(user->Genesis()))
                        debug::error(FUNCTION, "Stake Minter: Failed to remove stake change request");
                }

                /* Initialize block producer for Genesis operation. Only need the operation
                 * The coinstake reward will be added based on time when block is found.
                 */
                block.producer[0] << uint8_t(TAO::Operation::OP::GENESIS);

            }

            /* Do not sign producer transaction, yet. Coinstake reward must be added to operation first. */

            /* Reset sleep time on successful completion */
            if(nSleepTime == 5000)
            {
                nSleepTime = 1000;
                nCounter = 0;
            }

            /* Update display stake rate */
            nStakeRate.store(StakeRate(nTrust, fGenesis));

            return true;
        }