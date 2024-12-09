void Node::RecursiveCollectParents(AZStd::vector<size_t>& parents, bool clearParentsArray) const
    {
        if (clearParentsArray)
        {
            parents.clear();
        }

        // loop until we reached a root node
        const Node* node = this;
        while (node)
        {
            // get the parent index and add it to the list of parents if the current node is not a root node
            const size_t parentIndex = node->GetParentIndex();
            if (parentIndex != InvalidIndex)
            {
                // check if the parent is already in our array, if not add it so that we only store each node once
                if (AZStd::find(begin(parents), end(parents), parentIndex) == end(parents))
                {
                    parents.emplace_back(parentIndex);
                }
            }

            // down the hierarchy
            node = node->GetParentNode();
        }
    }