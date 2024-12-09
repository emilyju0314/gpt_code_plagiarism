void SetJoiner(bool aJoiner)
    {
        if (aJoiner)
        {
            mFlags |= kJoinerMask;
        }
        else
        {
            mFlags &= ~kJoinerMask;
        }
    }