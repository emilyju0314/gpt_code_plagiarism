void
DataNode::RemoveNode(const vtkstd::string &key, bool deleteNode)
{
    if(NodeType != INTERNAL_NODE)
        return;
    if(Length < 1)
        return;

    if(Length == 1)
    {
        DataNode *node = (DataNode *)Data;
        if(node->Key == key)
        {
            if(deleteNode)
                delete node;
            Data = 0;
            Length = 0;
        }
    }
    else
    {
        DataNode **nodeArray = (DataNode **)Data;
        bool start = false;

        for(int i = 0; i < Length; ++i)
        {
            if(!start && nodeArray[i]->Key == key)
            {
                if(deleteNode)
                    delete nodeArray[i];
                start = true;
            }

            if(start && (i < (Length - 1)))
                nodeArray[i] = nodeArray[i + 1];
        }
        if(start)
        {
            --Length;

            // If we're down to 1, convert to a single pointer.
            if(Length == 1)
            {
                DataNode *temp = nodeArray[0];
                delete [] nodeArray;
                Data = (void *)temp;
            } 
        }
    }
}