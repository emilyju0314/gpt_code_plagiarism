status_t ClientSideNetworkTreeGateway :: IncomingMuscledMessageReceivedFromServer(const MessageRef & msg)
{
   switch(msg()->what)
   {
      case PR_RESULT_DATATREES:
      {  
         String tag;
         if (msg()->FindString(PR_NAME_TREE_REQUEST_ID, tag).IsOK())
         {
            MessageRef sessionRelativeMsg = GetMessageFromPool();
            if (sessionRelativeMsg())
            {  
               // Convert the absolute paths back into user-friendly relative paths
               for (MessageFieldNameIterator iter = msg()->GetFieldNameIterator(B_MESSAGE_TYPE); iter.HasData(); iter++)
               {  
                  String sessionRelativeString = iter.GetFieldName();
                  if (ConvertPathToSessionRelative(sessionRelativeString).IsOK()) (void) msg()->ShareName(iter.GetFieldName(), *sessionRelativeMsg(), sessionRelativeString);
               }
               SubtreesRequestResultReturned(tag, sessionRelativeMsg);
            }
         }
      }
      break;

      case PR_RESULT_DATAITEMS:
      {
         const bool hasOpTags = msg()->HasName(_opTagFieldName, B_STRING_TYPE);

         const uint32 * opTagPutMap = NULL;
         uint32 opTagPutMapLength = 0;
         if ((hasOpTags)&&(msg()->GetInfo(_opTagPutMap, NULL, &opTagPutMapLength).IsOK())) (void) msg()->FindData(_opTagPutMap, B_INT32_TYPE, (const void **) &opTagPutMap, NULL);

         // Handle notifications of removed nodes
         {
            String nodePath;
            for (int i=0; msg()->FindString(PR_NAME_REMOVED_DATAITEMS, i, nodePath).IsOK(); i++)
               if (ConvertPathToSessionRelative(nodePath).IsOK())
                  TreeNodeUpdated(nodePath, MessageRef(), hasOpTags ? msg()->GetStringReference(_opTagFieldName, msg()->GetInt32(_opTagRemoveMap, -1, i)) : GetEmptyString());
         }

         // Handle notifications of added/updated nodes
         {
            uint32 currentFieldNameIndex = 0;
            MessageRef nodeRef;
            for (MessageFieldNameIterator iter = msg()->GetFieldNameIterator(); iter.HasData(); iter++,currentFieldNameIndex++)
            {
               String nodePath = iter.GetFieldName();
               if (ConvertPathToSessionRelative(nodePath).IsOK())
                  for (uint32 i=0; msg()->FindMessage(iter.GetFieldName(), i, nodeRef).IsOK(); i++)
                     TreeNodeUpdated(nodePath, nodeRef, LookupOpTagInPutMap(*msg(), opTagPutMap, opTagPutMapLength, currentFieldNameIndex, i));
            }
         }
      }
      break;

      case PR_RESULT_INDEXUPDATED:
      {
         const bool hasOpTags = msg()->HasName(_opTagFieldName, B_STRING_TYPE);

         const uint32 * opTagPutMap = NULL;
         uint32 opTagPutMapLength = 0;
         if ((hasOpTags)&&(msg()->GetInfo(_opTagPutMap, NULL, &opTagPutMapLength).IsOK())) (void) msg()->FindData(_opTagPutMap, B_INT32_TYPE, (const void **) &opTagPutMap, NULL);

         // Handle notifications of node-index changes
         uint32 currentFieldNameIndex = 0;
         for (MessageFieldNameIterator iter = msg()->GetFieldNameIterator(); iter.HasData(); iter++,currentFieldNameIndex++)
         {
            String sessionRelativePath = iter.GetFieldName();
            if (ConvertPathToSessionRelative(sessionRelativePath).IsOK())
            {
               const char * indexCmd;
               for (int i=0; msg()->FindString(iter.GetFieldName(), i, &indexCmd).IsOK(); i++)
               {
                  const String & optOpTag = LookupOpTagInPutMap(*msg(), opTagPutMap, opTagPutMapLength, currentFieldNameIndex, i);
                  const char * colonAt = strchr(indexCmd, ':');
                  char c = indexCmd[0];
                  switch(c)
                  {
                     case INDEX_OP_CLEARED:       TreeNodeIndexCleared(sessionRelativePath, optOpTag);                                                   break;
                     case INDEX_OP_ENTRYINSERTED: TreeNodeIndexEntryInserted(sessionRelativePath, atoi(&indexCmd[1]), colonAt?(colonAt+1):"", optOpTag); break;
                     case INDEX_OP_ENTRYREMOVED:  TreeNodeIndexEntryRemoved(sessionRelativePath,  atoi(&indexCmd[1]), colonAt?(colonAt+1):"", optOpTag); break;
                  }
               }
            }
         }
      }
      break;

      case PR_RESULT_PONG:
         TreeLocalPeerPonged(msg()->GetString(NTG_NAME_TAG));
      break;

      default:
         return B_UNIMPLEMENTED;  // unhandled/unknowm Message type!
   }

   return B_NO_ERROR;
}