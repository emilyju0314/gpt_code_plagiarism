explicit Array(const ArrayDescription& desc) :
        ArrayContainer(desc)
    {
        assert(typeMatchesTemplate<T>());
    }