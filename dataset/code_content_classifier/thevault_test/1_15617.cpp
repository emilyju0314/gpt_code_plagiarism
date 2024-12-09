void Graph::addVertex(int index)
{
    string s = "A";
    for (int i = numVertices; i <= index; i++)
    {
        s[0] = char('A' + i);
        addVertex(s);
    }
}