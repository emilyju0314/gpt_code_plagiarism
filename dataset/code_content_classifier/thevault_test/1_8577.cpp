Compare(TLeft& left, const TRight& right, bool auto_delete = false, const char* compare_string = nullptr) :
            m_left(left), m_right(const_cast<TRight&>(right)), m_compare_string(compare_string)
    {
        m_auto_delete = auto_delete;
        Query::expression(this, auto_delete);
        Table* t = const_cast<Table*>(get_table()); // todo, const

        if (t)
            Query::m_table = t->get_table_ref();
    }