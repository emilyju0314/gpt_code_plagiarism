RootInputDesc::RootInputDesc(TChain*            t,
                              const std::string& treeName,
                              const std::string& branchName, 
                              int                readRetries,
                              TObject**          branchPtr,
                              bool               rebuildIndex, 
                              bool               verbose)
     : m_tree(treeName), 
       m_branch(branchName), 
       m_chain(t), 
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

    m_numEvents = setEventCollection();

    return;
 }