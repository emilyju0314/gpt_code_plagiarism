int NodeHasCommonParentImpl(const Node* left, const Node* right, const Node* initialLeft, const Node* initialRight)
    {
        if (left == right || (!left && !right))
        {
            return 0;
        }
        if (left == initialRight)
        {
            // right is a parent of left
            return 1;
        }
        if (right == initialLeft)
        {
            // left is a parent of right
            return -1;
        }

        const Node* leftParent = left ? left->GetParentNode() : nullptr;
        const Node* rightParent = right ? right->GetParentNode() : nullptr;
        return NodeHasCommonParentImpl(leftParent, rightParent, initialLeft, initialRight);
    }