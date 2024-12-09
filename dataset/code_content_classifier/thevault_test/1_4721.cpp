kernel_provider(unsigned long flags, const GUID &id)
        : p_(flags)
        , id_(id)
        , gm_(0)
        , r_(0)
        , rundown_enabled_(false)
        {}