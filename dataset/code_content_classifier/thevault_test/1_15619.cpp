void Graph::read(const char *filename)
{
    ifstream fin(filename);
    char buffer[20], buffer1[20];
    int nrv;
    fin >> buffer; // read the letter U or D
    if (buffer[0] == 'd' || buffer[0] == 'D')
        directed = true;
    fin >> nrv; // read the number of vertices

    for (int i = 0; i < nrv; i++) // read all the names of vertices
    {
        fin >> buffer; // read the vertex name
        addVertex(string(buffer)); // this will also update numVertices
    }

    // read all the edges until the end of the file 
    while (!fin.eof() && fin.good()) // we have not reached the end of the file
    {
        fin >> buffer;
        if (strlen(buffer) && fin.good()) // was the first name read correctly?
        {
            fin >> buffer1;
            if (strlen(buffer) && strlen(buffer1))  // how about the second?
            {
                // we know both names are valid here
                buffer[strlen(buffer) - 1] = '\0'; // Deleting the ','
                addEdge(string(buffer), string(buffer1));
            }
        }
    }
    fin.close();
}