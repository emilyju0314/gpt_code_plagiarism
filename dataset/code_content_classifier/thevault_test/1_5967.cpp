Tree* Tree::add(Tree* node)
{
    if (!node) return 0;     // What?
    Tree* retval = this;

    int compareValue = value.compare(node->value);
    if (compareValue == 0)
    {
        cout << "Word " << node->value << " already in dictionary." << endl;
        return 0;
    }
    else if (compareValue > 0)
    {
        if (!left)
        {
            left = node;
            node->parent = this;
        }
        else
        {
            Tree* newLeft = left->add(node);
            if (!newLeft)
            {
                return 0;
            }
            left = newLeft;
            if (!right && !left->right && node->value.compare(left->value) < 0)
            {   // swap
                cout << "Swap from the left" << endl;
                retval = left;
                left->right = this;
                left->add(node);
                left = 0;
                right = 0;
            }
        }
    }
    else if (compareValue < 0)
    {
        if (!right)
        {
            right = node;
            node->parent = this;
        }
        else
        {
            Tree* newRight = right->add(node);
            if (!newRight)
            {
                return 0;
            }
            right = newRight;
            if (!left && !right->left && node->value.compare(right->value) > 0)
            {   // swap
                cout << "Swap from the right" << endl;
                retval = right;
                right->left = this;
                left = 0;
                right = 0;
            }
        }
    }
    
    return retval;
}