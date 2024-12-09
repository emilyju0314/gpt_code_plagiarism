int PdsTableFormatStrategy::apply(ResourceList &resources, 
                                    const ResourceList &globals) {
  
    QString fmtfile = translateKeywordArgs("PdsFormatFile", 
                                           getGlobals(m_parameters, globals));

    QString keyfmt = translateKeywordArgs("KeywordFormatFile", 
                                          getGlobals(m_parameters, globals),
                                          "$ISISROOT/appdata/translations/pdsExportRootGen.typ");


    // Remake new columns each time
    m_columns.clear();
    makeColumns(m_parameters);
  
    int pos = 1;
    QString separator("");

    Pvl fmtpvl;
    // Apply only if provided
    if ( !keyfmt.isEmpty() ) {
      fmtpvl.setFormat(new PvlFormatPds(keyfmt)); 
    }
    fmtpvl.setTerminator("END");

    for (int c = 0 ; c < m_columns.size() ; c++) {
      PdsColumn *column = PdsColumn::promote(m_columns[c]);
    
      // Get the size of the column
      int datalen = column->bytes();
      if ( 0 <= datalen ) {
        datalen = column->bytes(resources); 
        column->setBytes(datalen);
      }
  
      // Determine formatted data size
      int nquotes = column->isQuoted();
      pos += (separator.size() + nquotes);
      column->setStartByte(pos);
  
      // Update for size
      pos += (datalen + nquotes);
      separator = m_delimiter;
  
      fmtpvl.addObject(column->toPvl());
    }
  
    // Now write the Pvl column file
    fmtpvl.write(fmtfile);
  
    return (resources.size());
  }