QtFunction(const QMetaMethod& metaMethod)
        : ponder::Function(functionName(metaMethod), returnType(metaMethod), paramTypes(metaMethod))
        , m_metaMethod(metaMethod)
    {
    }