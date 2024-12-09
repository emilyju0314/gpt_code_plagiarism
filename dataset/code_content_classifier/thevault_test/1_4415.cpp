int vtkColorTransferFunction::AddRGBPoint( double x, double r,
                                           double g, double b,
                                           double midpoint,
                                           double sharpness )
{
  // Error check
  if ( midpoint < 0.0 || midpoint > 1.0 )
    {
    vtkErrorMacro("Midpoint outside range [0.0, 1.0]");
    return -1;
    }

  if ( sharpness < 0.0 || sharpness > 1.0 )
    {
    vtkErrorMacro("Sharpness outside range [0.0, 1.0]");
    return -1;
    }
  
  // remove any node already at this X location
  if (!this->AllowDuplicateScalars)
    {
    this->RemovePoint( x );
    }
  
  // Create the new node
  vtkCTFNode *node = new vtkCTFNode;
  node->X         = x;
  node->R         = r;
  node->G         = g;
  node->B         = b;
  node->Midpoint  = midpoint;
  node->Sharpness = sharpness;
  
  // Add it, then sort to get everyting in order
  this->Internal->Nodes.push_back(node);
  this->SortAndUpdateRange();
  
  // We need to find the index of the node we just added in order
  // to return this value
  unsigned int i;
  for ( i = 0; i < this->Internal->Nodes.size(); i++ )
    {
    if ( this->Internal->Nodes[i]->X == x )
      {
      break;
      }
    }
  
  int retVal;
  
  // If we didn't find it, something went horribly wrong so
  // return -1  
  if ( i < this->Internal->Nodes.size() )
    {
    retVal = i;
    }
  else
    {
    retVal = -1;
    }
  
  return retVal;  
}