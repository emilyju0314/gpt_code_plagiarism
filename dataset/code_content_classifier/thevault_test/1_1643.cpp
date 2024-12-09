void PdsTableFormatStrategy::makeColumns(SharedResource &definition) {
  
    int nColumns(definition->count("Column"));
    validate("DataType", definition, nColumns, nColumns);
    validate("Bytes", definition, nColumns, 0);
    int nfmt = validate("Format", definition, nColumns, 0);
    int nunit = validate("Unit", definition, nColumns, 0);
    validate("DataDescription", definition, nColumns, 0);
  
    for ( int i = 0 ; i < nColumns ; i++) {
      QString name = definition->value("Column", i);
      SharedResource column(new PdsColumn(name));
      column->add("COLUMN_NUMBER", toString(i+1));
  
      column->add("NAME", name);
  
      column->add("DATA_TYPE", definition->value("DataType", i));
  
      column->add("BYTES", definition->value(name+"_Bytes", 
                                             definition->value("BYTES", "0", i)));
  
      if ( nfmt > i ) { 
        column->add("FORMAT", definition->value("Format", i));
      }
      if ( nunit > i ) { 
        column->add("UNIT", definition->value("Unit", i)); 
      }
  
      column->add("DESCRIPTION", definition->value("DataDescription", "NULL", i)); 
      m_columns.append(column);
    } 
  }