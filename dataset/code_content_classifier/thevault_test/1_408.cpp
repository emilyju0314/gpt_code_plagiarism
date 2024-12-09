bool TritiumMinter::FindLastStake(const uint256_t& hashGenesis, uint512_t& hashLast)
        {
            if(LLD::Ledger->ReadStake(hashGenesis, hashLast))
                return true;

            /* If last stake is not directly available, search for it */
            Transaction tx;
            if(TAO::Ledger::FindLastStake(hashGenesis, tx))
            {
                /* Update the Ledger with found last stake */
                hashLast = tx.GetHash();

                return true;
            }

            return false;
        }