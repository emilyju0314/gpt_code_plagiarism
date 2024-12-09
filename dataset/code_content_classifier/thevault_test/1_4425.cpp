int vtkColorTransferFunction::GetNodeValue( int index, double val[6] )
{
  int size = static_cast<int>(this->Internal->Nodes.size());
  
  if ( index < 0 || index >= size )
    {
    vtkErrorMacro("Index out of range!");
    return -1;
    }
  
  val[0] = this->Internal->Nodes[index]->X;
  val[1] = this->Internal->Nodes[index]->R;
  val[2] = this->Internal->Nodes[index]->G;
  val[3] = this->Internal->Nodes[index]->B;
  val[4] = this->Internal->Nodes[index]->Midpoint;
  val[5] = this->Internal->Nodes[index]->Sharpness;
  
  return 1;
}