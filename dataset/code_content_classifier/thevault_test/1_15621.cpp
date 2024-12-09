void Graph::write(const char *filename)
{
    //Open the output file and verify that it was opened successfully.
    ofstream fout(filename);
    if (!fout)
    {
        cout << "Opening file \"" << filename << "\" for output failed.\n";
        return;
    }

    //Write out the type of graph.
    fout << (directed ? 'D' : 'U') << '\n';
    
    //Write the number of vertices.
    fout << numVertices << '\n';
    
    //Write the name of each vertex.
    for (int i = 0; i < numVertices; ++i)
        fout << vertices[i].name << '\n';

    //Allocate and verify an array to keep track of the vertices visited.
    bool *visited = new (nothrow) bool[numVertices];
    testAllocation(visited);
    for (int i = 0; i < numVertices; ++i)
        visited[i] = false;

    //Write the edge list.
    for (int i = 0; i < numVertices; ++i)
    {
        //Mark the current vertex as visited.
        visited[i] = true;
        //Iterate through the current vertex's edge list.
        for (ListIntIter iter = vertices[i].edgeList.begin();
             iter != vertices[i].edgeList.end(); iter++)
            //If the graph is not directed, rely on whether the edge vertex has been visited
            //or not to determine whether to write the edge to the file.  If the graph is directed
            //write all the edges anyway.
            if (!visited[*iter] || directed)
                fout << vertices[i].name << ", " << vertices[*iter].name << '\n';
    }
        
    //Close the file.
    fout.close();
}