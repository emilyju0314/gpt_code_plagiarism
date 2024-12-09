status_t MessageTreeDatabaseObject :: RemoveDataNodes(const String & nodePath, const ConstQueryFilterRef & filterRef, bool quiet, const String & optOpTag)
{
   MessageTreeDatabasePeerSession * zsh = GetMessageTreeDatabasePeerSession();
   if (zsh == NULL) return B_BAD_OBJECT;

   DECLARE_OP_TAG_GUARD;

   const SafeQueryFilter safeQF(this);
   AndQueryFilter andQF = AndQueryFilter(DummyConstQueryFilterRef(safeQF));
   if (filterRef()) (void) andQF.GetChildren().AddTail(filterRef);
   return zsh->RemoveDataNodes(nodePath, DummyConstQueryFilterRef(andQF), quiet);
}