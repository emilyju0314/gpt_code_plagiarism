Mapper::Mapper(const string dataFileName)
{
  ifstream dataFile(dataFileName.c_str(), ios::in | ios::binary);

  if (!dataFile)
    {
      cout << "Failed to open " << dataFileName << " to read." << endl;
      exit(1);
    }

  // dimensionality
  dataFile.read((char *)&dimensionality, sizeof(dimensionality));

  // strings and coordinates
  dataFile.read((char *)&size, sizeof(size));
  coordinatesVector.resize(size);

  char buffer[200];
  for (register int i = 0; i < size; i ++)
    {
      // string
      int len;
      dataFile.read((char *)&len, sizeof(len));
      dataFile.read(buffer, len);
      buffer[len] = '\0';
      stringVector.push_back(buffer);

      // coordinates
      for (register int j = 0; j < dimensionality; j ++)
	{
	  double coord;
	  dataFile.read((char *)&coord, sizeof(coord));
	  coordinatesVector[i].push_back(coord);
	}
    }

  // pivotsA
  for (register int i = 0; i < dimensionality; i ++)
    {
      int id;
      dataFile.read((char *)&id, sizeof(id));
      pivotsA.push_back(id);
    }

  // pivotsB
  for (register int i = 0; i < dimensionality; i ++)
    {
      int id;
      dataFile.read((char *)&id, sizeof(id));
      pivotsB.push_back(id);
    }

  dataFile.close();
}