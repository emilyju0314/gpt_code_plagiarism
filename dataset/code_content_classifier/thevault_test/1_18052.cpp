int256_t parse(const QString &text, bool *valid_out=0) const
    {
        int256_t val = 0;
        bool valid = BitcoinUnits::parseToken(decimalUnits, text, &val);
        if(valid)
        {
            if(val < 0 || val > totalSupply)
                valid = false;
        }
        if(valid_out)
            *valid_out = valid;
        return valid ? val : 0;
    }