IObserver(std::string const& name)
      : m_name(name)
    {
       std::cout << "Observer '" << m_name << "' created" << std::endl;
    }