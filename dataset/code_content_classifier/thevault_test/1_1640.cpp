PdsTableFormatStrategy::PdsTableFormatStrategy(const PvlObject &definition, 
                                                 const ResourceList &globals) : 
                                                 Strategy(definition, globals), 
                                                 m_parameters(new Resource("PdsTableFormat",definition)), 
                                                 m_columns(),  m_delimiter(",") {
  
    // Verify input parameters
    makeColumns(m_parameters);
    m_columns.clear();
    m_delimiter = m_parameters->value("Delimiter", ",");
    return;
  }