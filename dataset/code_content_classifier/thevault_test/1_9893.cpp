DataNode::DataNode(const vtkstd::string &name) : Key(name)
{
    NodeType = INTERNAL_NODE;
    Length = 0;
    Data = 0;
}