explicit ArrayDescription(const ArrayDescription& descr, Type type) :
        ArrayDescription(descr)
    {
        _componentType = type;
        _componentSize = typeSize(type);
        _elementSize = componentCount() * componentSize();
    }