bool Strategy::setup(const std::string& params, const std::string& stocks) 
	{
		std::string paramFile = (params.empty()) ? PARAM_CONFIG_FILE : params;
		std::string stockFile = (stocks.empty()) ? WATCHLIST_CONFIG_FILE : stocks;

		if (tools::fileExists(paramFile) && tools::fileExists(stockFile)) 
		{
			rapidjson::Document strategyJSON = tools::getDOMTree(tools::getWholeFile(paramFile));
			std::vector<std::string> stockLines = tools::getLines(stockFile);

			// parse out sell-when conditions
			parameters.insert(parameters.begin(), std::pair<std::string, double>(SELL_WHEN[0], strategyJSON["sell-when"]["num-tests-met"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(SELL_WHEN[1], strategyJSON["sell-when"]["profit-margin-over"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(SELL_WHEN[2], strategyJSON["sell-when"]["RSI-over"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(SELL_WHEN[3], strategyJSON["sell-when"]["loss-more-than"].GetDouble()));
			std::cout << "SELL-WHEN conditions saved." << std::endl;

			// parse out buy conditions
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[0], strategyJSON["buy-when"]["num-tests-met"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[1], strategyJSON["buy-when"]["RSI-below"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[2], strategyJSON["buy-when"]["min-market-cap-billions"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[3], strategyJSON["buy-when"]["PE-greater-than"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[4], strategyJSON["buy-when"]["PE-less-than"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[5], strategyJSON["buy-when"]["min-dividend-yield"].GetDouble()));
			parameters.insert(parameters.begin(), std::pair<std::string, double>(BUY_WHEN[6], strategyJSON["buy-when"]["min-ytd-change"].GetDouble()));
			std::cout << "BUY-WHEN conditions saved." << std::endl;
			std::cout << "Parameter map filled!" << std::endl;

			// parse out reserve cash and stocks to own
			reserveCash = strategyJSON["min-cash"].GetDouble();
			std::cout << "Reserve cash saved." << std::endl;

			stocksToOwn = strategyJSON["stocks-to-own"].GetUint();
			std::cout << "Stocks to own parsed. " << std::endl;

			// parse out 200 and 50-day SMA indicators
			priceAbove200SMA = strategyJSON["buy-when"]["price-above-200-SMA"].GetBool();
			priceAbove50SMA = strategyJSON["buy-when"]["price-above-50-SMA"].GetBool();

			// news sentiment minimum score 
			sentimentMinScore = strategyJSON["buy-when"]["news-sentiment-above"].GetDouble();
			headlines = strategyJSON["headlines"].GetUint();

			// parse out watchlist
			for (std::string& line : stockLines)
			{
				if (line.empty() || line[0] == '#') { continue; }

				std::vector<std::string> lineElements;
				boost::split(lineElements,line,boost::is_any_of(","));
				boost::algorithm::trim(lineElements[0]);
				
				if (lineElements.size() == 1)
				{
					// just symbol
					Stock s(lineElements[0]);
					watchlist.push_back(s);
				}
				else if (lineElements.size() == 2)
				{
					// symbol, name specified
					boost::algorithm::trim(lineElements[1]);
					Stock s(lineElements[0], lineElements[1]);
					watchlist.push_back(s);
				}
				else
				{
					// symbol, name, industry
					boost::algorithm::trim(lineElements[1]);
					boost::algorithm::trim(lineElements[2]);
					Stock s(lineElements[0], lineElements[1], lineElements[2]);
					watchlist.push_back(s); 
				}

				::verboseDebugMessage(lineElements[0]);
			}

			updateTodaysSentiment();

			return true;
		}
		else
		{
			return false;
		}
	}