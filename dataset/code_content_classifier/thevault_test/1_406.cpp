bool TritiumMinter::CheckUser()
        {
            /* Check whether unlocked account available. */
            if(TAO::API::users->Locked())
            {
                debug::log(0, FUNCTION, "No unlocked account available for staking");
                return false;
            }

            /* Check that the account is unlocked for staking */
            if(!TAO::API::users->CanStake())
            {
                debug::log(0, FUNCTION, "Account has not been unlocked for staking");
                return false;
            }

            return true;
        }