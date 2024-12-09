void SetCommercialCommissioningMode(bool aCCM)
    {
        if (aCCM)
        {
            mFlags |= kCCMMask;
        }
        else
        {
            mFlags &= ~kCCMMask;
        }
    }