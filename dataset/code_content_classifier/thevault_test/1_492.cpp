const FareTransfer* PathFinder::getFareTransfer(const std::string from_fare_period, const std::string to_fare_period) const
    {
        FareTransferMap::const_iterator ftm_iter = fare_transfer_rules_.find( std::make_pair(from_fare_period, to_fare_period) );
        if (ftm_iter != fare_transfer_rules_.end()) {
            return &(ftm_iter->second);
        }
        return (const FareTransfer*)0;
    }