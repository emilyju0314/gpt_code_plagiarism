void Agent_List::Union(Agent_List **result, Agent_List *list1)
{
  PrvCurPtr RetVal;
  Agent_List *dupAgent;
  
  for (Agent_List *cur=list1; cur != NULL; cur=AGENT_NEXT(cur)) {
    RetVal = Find(result, AGT_ADDR(cur));
    if (RetVal.cur == NULL) {
      dupAgent = new Agent_List;
      *dupAgent = *cur;
      InsertFront(result, dupAgent);
    }
  }
}