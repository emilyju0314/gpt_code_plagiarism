struct Node* insertNode(struct Node *genesisNode,string key)
{
    if(genesisNode==NULL)
    {
        struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->timestamp=time_t;
        ptr->data=data;
        ptr->nodeNumber=nodeno++;
        ptr->nodeId=nodeid++;
        ptr->leftchildRefrenceNodeId=NULL;
        ptr->rightchildRefrenceNodeId=NULL;
   }
   if(key<genesisNode->data)
   {
       genesisNode->leftchildRefrenceNodeId=insertNode(genesisNode->leftchildRefrenceNodeId);
   }
   else
   {
       genesisNode->rightchildRefrenceNodeId=insertNode(genesisNode->rightchildRefrenceNodeId);
   }
   return genesisNode;
}