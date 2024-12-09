void SetNativeCommissioner(bool aNativeCommissioner)
    {
        if (aNativeCommissioner)
        {
            mFlags |= kNativeMask;
        }
        else
        {
            mFlags &= ~kNativeMask;
        }
    }