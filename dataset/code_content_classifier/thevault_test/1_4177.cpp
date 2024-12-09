Application(std::string const& title)
  {
    // Title of the application
    std::cout << "Application title: " << title << std::endl;
    // Because ": m_presenter(*this)" is forbidden
    m_presenter = new Presenter(*this);
    // Simulate a user typing in the entry text widget.
    textEntry();
    // Do computation with the string return by the entry text widget.
    m_presenter->compute();
  }