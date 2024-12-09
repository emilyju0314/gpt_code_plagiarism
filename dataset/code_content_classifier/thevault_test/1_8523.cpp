bool ParseObjFile(const char* fileName,
        std::vector<Vector3>& positions,
        std::vector<Vector3>& normals,
        std::vector<Vector2>& uvs,
        std::vector<std::array<std::array<int, 3>, 3>>& faces)
    {
        std::string line;
        std::ifstream file;

        //Try to open the file
        file.open(fileName);
        if (!file.is_open())
        {
            std::cout << "Failed to open file " << fileName << ".\n";
            return false;
        }

        //Read line by line
        while (std::getline(file, line))
        {
            std::vector<std::string> items = Parse::Split(line);

            if (items.size() == 0)
            {
                //Empty line; ignore
                continue;
            }
            //Vertex position line
            else if (items[0] == "v")
            {
                Vector3 position;
                for (int i = 0; i < 3; i++)
                {
                    position[i] = Parse::ToFloat(items[i + 1]);
                }
                positions.push_back(position);
            }
            //UV coordinate line
            else if (items[0] == "vt")
            {
                Vector2 uv;
                for (int i = 0; i < 2; i++)
                {
                    uv[i] = Parse::ToFloat(items[i + 1]);
                }
                uvs.push_back(uv);
            }
            //Normal line
            else if (items[0] == "vn")
            {
                Vector3 normal;
                for (int i = 0; i < 3; i++)
                {
                    normal[i] = Parse::ToFloat(items[i + 1]);
                }
                normals.push_back(normal);
            }
            //Face line
            else if (items[0] == "f")
            {
                std::array<std::array<int, 3>, 3> face;
                for (unsigned int v = 0; v < 3; v++)
                {
                    //Split the item into vertex, uv, and normal
                    auto vItems = Parse::Split(items[v + 1], '/');

                    //Subtract 1 from each of the indices because an OBJ file is 1-indexed

                    //Read vertex
                    face[v][0] = Parse::ToInt(vItems[0]) - 1;

                    //Read uv if it exists
                    if (vItems.size() > 1 && vItems[1] != "")
                        face[v][1] = Parse::ToInt(vItems[1]) - 1;
                    else
                        face[v][1] = -1;

                    //Read normal if it exists
                    if (vItems.size() > 2)
                        face[v][2] = Parse::ToInt(vItems[2]) - 1;
                    else
                        face[v][2] = -1;
                }
                faces.push_back(face);
            }
        }

        return true;
    }