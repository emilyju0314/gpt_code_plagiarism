size_t Trader::getSharesToBuy(const std::string& symbol)
    {
        size_t stocksWeCanOwn = Strategy::getStocksToOwn();
        double cashAvailable = tools::AccountData::getCashBalance();
        size_t numStocksOwned = currentHoldings.size();
        double reserveCash = Strategy::getMinCash();

        double cashToSpend = (cashAvailable - reserveCash)/(stocksWeCanOwn - numStocksOwned);

        double shares = cashToSpend/(tools::MarketData::getPrices({symbol})[0]);

        ::verboseDebugMessage("Stocks we can own: " + std::to_string(stocksWeCanOwn));
        ::verboseDebugMessage("Cash available: " + std::to_string(cashAvailable));
        ::verboseDebugMessage("Num stocks owned: " + std::to_string(numStocksOwned));
        ::verboseDebugMessage("Reserve cash level: " + std::to_string(reserveCash));
        ::verboseDebugMessage("Cash to spend on trade: " + std::to_string(cashToSpend));
        ::verboseDebugMessage("SHARES TO BUY OF " + symbol + ": " + std::to_string(shares));

        size_t result = static_cast<size_t>(floor(shares));
        std::cout << "SHARES TO BUY: " << result << std::endl;

        return result;
    }