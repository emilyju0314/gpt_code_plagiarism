double MarketData::getRSI(const std::string& symbol)
	{
		double numLosses = 0, totalLoss = 0, numGains = 0, totalGain = 0;

		std::string iexResponse = marketQueryIEX("stock/"+symbol+"/chart/1m");
		rapidjson::Document recentStats = getDOMTree(iexResponse);

		constexpr size_t NUM_PERIODS = 14;
		for (size_t i = 1; i <= NUM_PERIODS; i++)
		{
			double dayDelta = recentStats[recentStats.Size()-i]["changePercent"].GetDouble();

			::verboseDebugMessage("Day " + std::to_string(i) + " changePercent: " + std::to_string(dayDelta));

			if  (dayDelta < 0) 
			{ 
				numLosses++;
				totalLoss += dayDelta;
			}
			else 
			{ 
				numGains++;
				totalGain += dayDelta;
		 	}
		}
		double avgGain = totalGain/numGains;
		double avgLoss = (-1)*totalLoss/numLosses;

		double denominator = 1.0+(avgGain*NUM_PERIODS + getCurrentGain(symbol))/(avgLoss*NUM_PERIODS + getCurrentLoss(symbol));
		double rsi = (100.0 - (100.0)/denominator);

		::verboseDebugMessage("RSI calculated for " + symbol + ": " + std::to_string(rsi));

		return rsi;
	}