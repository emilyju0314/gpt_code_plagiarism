int PdsTableFormatStrategy::validate(const QString &keynam, 
                                        SharedResource &definition, 
                                        const int &maxcols, const int &mincols,
                                        const bool &throwOnError) {
  
    int nvals = definition->count(keynam);
    if ( !((maxcols == nvals) || (mincols == nvals)) ) {
      if ( throwOnError ) {
        QString mess = "The keyword count [" + QString::number(nvals) + "] for the given " + keynam
                       + " Resource definition is invalid. Must equal maxcols [" 
                       + QString::number(maxcols) + "or mincols [" 
                       + QString::number(mincols) + "]."; 
        throw IException(IException::User, mess, _FILEINFO_);
      }
      return (-1);
    }
  
    // Has either maxcols or mincols
    return (nvals);
  }