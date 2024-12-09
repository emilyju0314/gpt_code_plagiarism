Element::~Element()
  {
    if (child[0])
      delete child[0];

    if (child[1])
      delete child[1];

    if (newCoord)
      delete newCoord;

    if (elementData)
    {
      elementData->deleteDecorated();
      delete elementData;
    }

    // ;TODO: eventuell nicht löschen!
    if (dof)
    {
      delete [] dof;
      dof = NULL;
    }
  }