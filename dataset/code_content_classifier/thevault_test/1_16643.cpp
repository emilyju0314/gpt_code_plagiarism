static GroupId calculateGroupId(Node* node)
{
    if (node->inDocument() || (node->hasTagName(HTMLNames::imgTag) && !static_cast<HTMLImageElement*>(node)->haveFiredLoadEvent()))
        return GroupId(node->document());

    Node* root = node;
    if (node->isAttributeNode()) {
        root = static_cast<Attr*>(node)->ownerElement();
        // If the attribute has no element, no need to put it in the group,
        // because it'll always be a group of 1.
        if (!root)
            return GroupId();
    } else {
        while (Node* parent = root->parentNode())
            root = parent;
    }

    return GroupId(root);
}