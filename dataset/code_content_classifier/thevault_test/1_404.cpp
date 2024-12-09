bool HasExpires(const TAO::Operation::Contract& contract)
        {
            /* Create a contract with a dummy expiration condition that we can use for comparison */
            TAO::Operation::Contract expiration;
            AddExpires( json::json(), 0, expiration, false);

            /* Check to see if the contract contains the expiration condition */
            return HasCondition(contract, expiration);

        }