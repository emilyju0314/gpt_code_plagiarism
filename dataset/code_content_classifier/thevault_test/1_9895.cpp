void
DataNode::SetChar(char val)
{
    FreeData();
    NodeType = CHAR_NODE;
    Data = (void *)(new char(val));
}