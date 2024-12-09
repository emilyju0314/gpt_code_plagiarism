void vtkColorTransferFunction::SortAndUpdateRange()
{
  vtkstd::sort( this->Internal->Nodes.begin(),
                this->Internal->Nodes.end(),
                this->Internal->CompareNodes );
  
  int size = static_cast<int>(this->Internal->Nodes.size());
  if ( size )
    {
    this->Range[0] = this->Internal->Nodes[0]->X;
    this->Range[1] = this->Internal->Nodes[size-1]->X;
    }
  else
    {
    this->Range[0] = 0;
    this->Range[1] = 0;
    }
  
  this->Modified();  
}