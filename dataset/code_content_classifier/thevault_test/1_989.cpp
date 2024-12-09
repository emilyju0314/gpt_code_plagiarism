string OpalPythonServer::createUniqueId_ (const string& client_id)
{
  string unique_id; 
  { 
    ProtectScope lock(mapMutex_);
    unique_id = Stringize(++nextUniqueId_);
    uniqueClientMap_.put(unique_id, client_id);
  }
  UniqueIdToClientIdMapping.post(uniqueClientMap_);
  return unique_id;
}