ArrayDescription(const std::vector<size_t>& dimensions, size_t componentCount, Type componentType) :
        _dimensions(dimensions),
        _componentCount(componentCount),
        _componentType(componentType),
        _componentSize(typeSize(componentType)),
        _elementSize(_componentCount * _componentSize),
        _elementCount(initElementCount()),
        _dimensionTagLists(dimensions.size()),
        _componentTagLists(_componentCount)
    {
    }