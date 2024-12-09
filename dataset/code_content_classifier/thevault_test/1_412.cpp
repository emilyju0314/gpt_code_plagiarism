void TritiumMinter::MintBlock(const memory::encrypted_ptr<TAO::Ledger::SignatureChain>& user, const SecureString& strPIN)
        {
            static uint32_t nCounter = 0; //Prevents log spam during wait period

            /* Check the block interval for trust transactions.
             * This is checked here before minting and after setting up the block/calculating weights so that all staking metrics
             * continue to be updated during the interval wait. This way, anyone who retrieves and display metrics will see them
             * change appropriately. For example, they will see block weight reset after minting a block.
             */
            if(!fGenesis)
            {
                const uint32_t nInterval = block.nHeight - stateLast.nHeight;
                const uint32_t nMinInterval = MinStakeInterval(block);

                if(nInterval <= nMinInterval)
                {
                    /* Below minimum interval for generating stake blocks. Increase sleep time until can continue normally. */
                    nSleepTime = 5000; //5 second wait is reset below (can't sleep too long or will hang until wakes up on shutdown)

                    /* Update log every 60 iterations (5 minutes) */
                    if((nCounter % 60) == 0)
                        debug::log(0, FUNCTION, "Stake Minter: Too soon after mining last stake block. ",
                                   (nMinInterval - nInterval + 1), " blocks remaining until staking available.");

                    ++nCounter;

                    return;
                }
            }

            /* Genesis blocks do not include mempool transactions.  Therefore if there are already any transactions in the mempool
               for this sig chain the genesis block will fail to be accepted because the producer.hashPrevTx would not be on disk.
               Therefore if this is a genesis block, skip until there are no mempool transactions for this sig chain. */
            else if(fGenesis && mempool.Has(user->Genesis()))
            {
                /* 5 second wait is reset below (can't sleep too long or will hang until wakes up on shutdown) */
                nSleepTime = 5000;

                /* Update log every 10 iterations (50 seconds, which is average block time) */
                if((nCounter % 10) == 0)
                    debug::log(0, FUNCTION, "Stake Minter: Skipping genesis as mempool transactions would be orphaned.");

                ++nCounter;

                return;
            }
            else if(nSleepTime == 5000)
            {
                /* Reset sleep time after coin age meets requirement. */
                nSleepTime = 1000;
                nCounter = 0;
            }

            uint64_t nStake = 0;
            if (fGenesis)
            {
                /* For Genesis, stake amount is the trust account balance. */
                nStake = account.get<uint64_t>("balance");
            }
            else
            {
                nStake = account.get<uint64_t>("stake");

                /* Include added stake into the amount for threshold calculations. Need this because, if not included and someone
                 * unstaked their full stake amount, their trust account would be stuck unable to ever stake another block.
                 * By allowing minter to proceed when adding stake to a zero stake trust account, it must be added in here also
                 * or there would be no stake amount (require threshold calculation would fail).
                 *
                 * For other cases, where more is added to existing stake, we also include it as an immediate benefit
                 * to improve the chances to stake the block that implements the change. If not, low balance accounts could
                 * potentially have difficulty finding a block to add stake, even if they were adding a large amount.
                 */
                if(fStakeChange && stakeChange.nAmount > 0)
                    nStake += stakeChange.nAmount;
            }

            /* Calculate the minimum Required Energy Efficiency Threshold.
             * Minter can only mine Proof of Stake when current threshold exceeds this value.
             */
            cv::softdouble nRequired = GetRequiredThreshold(cv::softdouble(nTrustWeight.load()), cv::softdouble(nBlockWeight.load()), nStake);

            /* Calculate the target value based on difficulty. */
            LLC::CBigNum bnTarget;
            bnTarget.SetCompact(block.nBits);
            uint1024_t nHashTarget = bnTarget.getuint1024();

            debug::log(0, FUNCTION, "Staking new block from ", hashLastBlock.SubString(),
                                    " at weight ", (nTrustWeight.load() + nBlockWeight.load()),
                                    " and stake rate ", nStakeRate.load());

            /* Search for the proof of stake hash solution until it mines a block, minter is stopped,
             * or network generates a new block (minter must start over with new candidate)
             */
            while(!TritiumMinter::fStop.load() && !config::fShutdown.load()
                && hashLastBlock == TAO::Ledger::ChainState::hashBestChain.load())
            {
                /* Check that the producer isn't going to orphan any new transaction from the same hashGenesis. */
                Transaction tx;
                if(mempool.Get(block.producer.hashGenesis, tx) && block.producer.hashPrevTx != tx.GetHash())
                {
                    debug::log(2, FUNCTION, "Stake block producer is stale, rebuilding...");
                    break; //Start over with a new block
                }

                /* Update the block time for threshold accuracy. */
                block.UpdateTime();
                uint32_t nBlockTime = block.GetBlockTime() - block.producer.nTimestamp; // How long working on this block

                /* If just starting on block, wait */
                if(nBlockTime == 0)
                {
                    runtime::sleep(1);
                    continue;
                }

                /* Calculate the new Efficiency Threshold for the current nonce.
                 * To stake, this value must be larger than required threshhold.
                 * Block time increases the value while nonce decreases it.
                 * nNonce = 1 at start of new block.
                 */
                cv::softdouble nThreshold = GetCurrentThreshold(nBlockTime, block.nNonce);

                /* If threshhold not larger than required, wait and keep trying the same nonce value until threshold increases */
                if(nThreshold < nRequired)
                {
                    runtime::sleep(10);
                    continue;
                }

                /* Log every 1000 attempts */
                if(block.nNonce % 1000 == 0)
                    debug::log(3, FUNCTION, "Threshold ", nThreshold, " exceeds required ",
                        nRequired,", mining Proof of Stake with nonce ", block.nNonce);

                /* Handle if block is found. */
                uint1024_t hashProof = block.StakeHash();
                if(hashProof <= nHashTarget)
                {
                    debug::log(0, FUNCTION, "Found new stake hash ", hashProof.SubString());

                    ProcessBlock(user, strPIN);
                    break;
                }

                /* Increment nonce for next iteration. */
                ++block.nNonce;
            }

            return;
        }