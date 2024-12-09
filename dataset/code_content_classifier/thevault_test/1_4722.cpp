kernel_provider(const GUID& id, PERFINFO_MASK group_mask)
        : p_(0)
        , id_(id)
        , gm_(group_mask)
        , r_(0)
        , rundown_enabled_(false)
        {}