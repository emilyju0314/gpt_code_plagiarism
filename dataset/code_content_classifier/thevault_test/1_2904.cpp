size_t Trader::getSharesToSell(const std::string& symbol)
    {
        for (const Holding& hold : currentHoldings)
        {
            if (hold.getSymbol() == symbol)
            {
                return hold.getNumShares();
            }
        }

        return 0;
    }