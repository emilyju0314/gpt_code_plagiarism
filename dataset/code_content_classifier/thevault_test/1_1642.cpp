int PdsTableFormatStrategy::apply(SharedResource &resource, const ResourceList &globals) { 
    throw IException(IException::Programmer, 
                     "Should not be calling apply(SharedResource &resource).",
                     _FILEINFO_);
  
    //  Keeps the Resource
    return (0);
  }