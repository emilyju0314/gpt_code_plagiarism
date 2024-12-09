Object(const Object& x)
        // virtualized copy. Equivalent to :
        // m_self(std::make_unique<Model<T>>(*x.m_self))
        : m_self(x.m_self->copy())
    {
        std::cout << "Object copy" << std::endl;
    }