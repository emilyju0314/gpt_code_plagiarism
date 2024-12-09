void Graph::addEdge(char *name1, char *name2)
{
    int index1 = index(string(name1));
    int index2 = index(string(name2));
    if (index1 > numVertices)
        addVertex(index1);
    if (index2 >= numVertices)
        addVertex(index2);
    addEdge(index1, index2);
}