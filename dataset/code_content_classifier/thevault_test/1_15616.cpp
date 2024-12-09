Graph::Graph(int nv)
{
    numVertices = 0;
    numEdges = 0;
    directed = false;
    if (nv > 0)
        init(nv);
}