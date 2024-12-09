RootInputDesc::RootInputDesc( const StringArrayProperty& fileList, 
                              const std::string&         tree, 
                              const std::string&         branch, 
                              int                        readRetries,
                              TObject**                  branchPtr,
                              bool                       rebuildIndex, 
                              bool                       verbose )
   : m_tree(tree), 
     m_branch(branch), 
     m_chain(0), 
     m_dataObject(branchPtr), 
     m_myDataObject(true), 
     m_verbose(verbose),
     m_rebuildIndex(rebuildIndex), 
     m_runEvtIndex(0),
     m_chainIndex(0),
     m_readRetries(readRetries)
 {
    // Check ownership of data object
    if (branchPtr) m_myDataObject = false;

    // Set up the input file list
    m_numEvents = setFileList(fileList, m_verbose) ;

    return;
 }