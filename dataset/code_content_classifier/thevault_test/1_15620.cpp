void Graph::print()
{
    int i;
    if (directed)
        cout << "The graph is directed" << endl;
    else
        cout << "The graph is undirected" << endl;
    cout << "The graph contains " << numVertices
         << " vertices and " << numEdges << " edges" << endl;

    if (numVertices)
    {
        // print all the names
        cout << "The vertex names are: ";
        for (i = 0; i < numVertices; i++)
            cout << vertices[i].name << ' ';

        // print all the adjacency lists
        cout << endl
             << "The adjacency list for each vertex is:" << endl;
        for (i = 0; i < numVertices; i++)
        {
            cout << "vertex " << i << ": ";
            ListIntIter iter;
            iter = vertices[i].edgeList.begin();
            while (iter != vertices[i].edgeList.end())
            {
                // here we have an edge from i to *iter.
                cout << *iter << ' '; // output the content of the node
                iter++;               // move to the next node
            }
            cout << endl;
        }
    }
}