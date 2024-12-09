status_t MessageTreeDatabaseObject :: MoveIndexEntries(const String & nodePath, const String & optBefore, const ConstQueryFilterRef & filterRef, const String & optOpTag)
{
   MessageTreeDatabasePeerSession * zsh = GetMessageTreeDatabasePeerSession();
   if (zsh == NULL) return B_BAD_OBJECT;

   DECLARE_OP_TAG_GUARD;

   const SafeQueryFilter safeQF(this);
   AndQueryFilter andQF = AndQueryFilter(DummyConstQueryFilterRef(safeQF));
   if (filterRef()) (void) andQF.GetChildren().AddTail(filterRef);
   return zsh->MoveIndexEntries(nodePath, optBefore.HasChars()?&optBefore:NULL, DummyConstQueryFilterRef(andQF));
}