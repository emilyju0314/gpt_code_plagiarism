DataNode *
DataNode::GetNode(const vtkstd::string &key, DataNode *parentNode)
{
    DataNode *searchNode, *intermediate, *retval = 0;

    // Determine which node's children to search.        
    if(parentNode == 0)
        searchNode = this;
    else
        searchNode = parentNode;

    if(key == searchNode->Key)
        retval = searchNode;
    else if(searchNode->NodeType == INTERNAL_NODE)
    {
        if(searchNode->Length == 1)
        {
            DataNode *nodeArray = (DataNode *)(searchNode->Data);
            intermediate = GetNode(key, nodeArray);
            if(intermediate != 0)
            {
                retval = intermediate;
            }
        }
        else if(searchNode->Length > 1)
        {
            DataNode **nodeArray = (DataNode **)(searchNode->Data);

            for(int i = 0; i < searchNode->Length; ++i)
            {
                intermediate = GetNode(key, nodeArray[i]);
                if(intermediate != 0)
                {
                    retval = intermediate;
                       break;
                }
            }
        }
    }

    return retval;
}