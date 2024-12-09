status_t MessageTreeDatabasePeerSession :: GetPerClientPeerIDsForPath(const String & path, const ConstQueryFilterRef & optFilter, Hashtable<ZGPeerID, Void> & retPeerIDs)
{
   const ZGPeerID peerID = GetPeerIDFromReturnAddress(path, NULL);
   if (peerID.IsValid())
   {
      // path is something like "{f01898e8e4810001:fa4c50daa9eb}:_3_:_4_:" -- we'll use this to route it back to exactly one ITreeGatewaySubscriber
      return retPeerIDs.PutWithDefault(peerID);      
   }
   else
   {
      // path is e.g. "foo/bar/baz*" -- we want to send the Message on to any ITreeGatewaySubscribers who are subscribed to any of the nodes matching the path
      const bool isGlobal = path.StartsWith('/');

      status_t ret;
      NodePathMatcher matcher;
      if (matcher.PutPathString(isGlobal?path.Substring(1):path, optFilter).IsError(ret)) return ret;

      GetPerClientPeerIDsCallbackArgs args(retPeerIDs);
      (void) matcher.DoTraversal((PathMatchCallback) GetPerClientPeerIDsCallbackFunc, this, isGlobal?GetGlobalRoot():*GetSessionNode()(), true, &args);
      return args._sendToAll ? B_ERROR : B_NO_ERROR;
   }
}