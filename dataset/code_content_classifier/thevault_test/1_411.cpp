bool TritiumMinter::CalculateWeights()
        {
            static uint32_t nCounter = 0; //Prevents log spam during wait period

            /* Use local variables for calculations, then set instance variables at the end */
            cv::softdouble nTrustWeightCurrent = cv::softdouble(0.0);
            cv::softdouble nBlockWeightCurrent = cv::softdouble(0.0);

            if(!fGenesis)
            {
                /* Weight for Trust transactions combines trust weight and block weight. */
                nTrustWeightCurrent = TrustWeight(nTrust);
                nBlockWeightCurrent = BlockWeight(nBlockAge);
            }
            else
            {
                /* Weights for Genesis transactions only use trust weight with its value based on coin age. */

                /* For Genesis, coin age is current block time less last time trust account register was updated.
                 * This means that, if someone adds more balance to trust account while staking Genesis, coin age is reset and they
                 * must wait the full time before staking Genesis again.
                 */
                uint64_t nAge = block.GetBlockTime() - account.nModified;

                /* Genesis has to wait for coin age to reach minimum. */
                if(nAge < MinCoinAge())
                {
                    /* Record that stake minter is in wait period */
                    fWait.store(true);
                    nWaitTime.store(MinCoinAge() - nAge);

                    /* Increase sleep time to wait for coin age (can't sleep too long or will hang until wakes up on shutdown) */
                    nSleepTime = 5000;

                    /* Update log every 60 iterations (5 minutes) */
                    if((nCounter % 60) == 0)
                        debug::log(0, FUNCTION, "Stake Minter: Stake balance is immature. ",
                            (nWaitTime.load() / 60), " minutes remaining until staking available.");

                    ++nCounter;

                    return false;
                }
                else if(nSleepTime == 5000)
                {
                    /* Reset wait period setting */
                    fWait.store(false);
                    nWaitTime.store(0);

                    /* Reset sleep time after coin age meets requirement. */
                    nSleepTime = 1000;
                    nCounter = 0;
                }

                nTrustWeightCurrent = GenesisWeight(nAge);

                /* Block Weight remains zero while staking for Genesis */
                nBlockWeightCurrent = cv::softdouble(0.0);
            }

            /* Update minter settings */
            nBlockWeight.store(double(nBlockWeightCurrent));
            nTrustWeight.store(double(nTrustWeightCurrent));

            return true;
        }