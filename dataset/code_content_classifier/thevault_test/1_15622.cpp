void Graph::input()
{
    //Empty the graph in preparation for the user entering one of their own.
    makeEmpty();

    //Ask the user for the number of vertices, initialize the graph with that number of vertices,
    //and give feedback to the user stating that the specified number of vertices have been added
    //with names beginning at 'A' and progressing alphabetically.
    int localNumVertices = 0;
    while (localNumVertices < 1 || localNumVertices > 26)
    {
        cout << "How many vertices will be in the graph? (1-26) ";
        getInput(localNumVertices);
    }
    init(localNumVertices);
    cout << localNumVertices << (localNumVertices == 1 ? " vertex has" : " vertices have")
         << " been added to the graph.\n"
         << "The names of the vertices begin at \"A\" and progress alphabetically.\n\n";

    //Ask the user if the graph is directed or not and if it is, proceed to call setDirected() to
    //set the graph as directed.
    char isDirected = 0;
    while (isDirected != 'Y' && isDirected != 'N')
    {
        cout << "Is the graph directed? (Y/N) ";
        cin >> isDirected;
        isDirected = toupper(isDirected);
    }
    if (isDirected == 'Y')
        setDirected();

    //Add edges to the graph.
    char edge1[2] = {'A'}, edge2[2] = {'A'};
    cout << "\nAdd edges in the format \"First-Vertex-Name Second-Vertex-Name\", for\n"
         << "example: \"A B\".  Enter anything other than capital letters to finish.\n";
    //Loop while the variables used to input the edges are valid.
    while (edge1[0] >= 'A' && edge1[0] <= 'Z' && edge2[0] >= 'A' && edge2[0] <= 'Z')
    {
        //Ask the user to add an edge.
        cout << "Add an edge: ";

        //Get the first vertex of the edge.
        cin >> edge1;
        //Check that the user hasn't typed a non-capital-letter, and if so, immediately break
        //of the while loop.
        if (edge1[0] < 'A' || edge1[0] > 'Z')
            break;

        //Eat the space in between the vertices.
        cin.get();

        //Get the second vertex of the edge.
        cin >> edge2;
        //Check that the user hasn't typed a non-capital-letter, and if so, immediately break
        //of the while loop.
        if (edge2[0] < 'A' || edge2[0] > 'Z')
            break;

        //Logic to validate the edges before adding them.
        //Checks to make sure the edges aren't the same (e.g. - A A).
        if (edge1[0] == edge2[0])
        {
            cout << "Cannot add an edge from a vertex to itself.\n";
        }
        //Checks to make sure the edges are within the bounds of the graph.
        else if (index(edge1) >= numVertices || index(edge2) >= numVertices)
        {
            cout << "One or both of those vertices don't exist.\n";
        }
        //Edges aren't obviously bad.
        else
        {
            //Check to make sure the edge doesn't already exist.
            bool edgeExists = false;
            //Iterate through the edgeList of the vertex specified by edge1.
            for (ListIntIter iter = vertices[index(edge1)].edgeList.begin();
                 iter != vertices[index(edge1)].edgeList.end() && !edgeExists; iter++)
                if (*iter == index(edge2))
                    //If the edge exists in the edgeList of the vertex specified by edge1, set the
                    //sentinel variable edgeExists to true.
                    edgeExists = true;

            //Depending on whether the edge already exists, either warn the user that it already
            //exists or add it then give feedback to the user saying as such.
            if (edgeExists)
                cout << "Edge already exists.\n";
            else
            {
                addEdge(edge1, edge2);
                cout << "Edge added.\n";
            }
        }
    }
}