void vtkColorTransferFunction::AddRGBSegment( double x1, double r1, 
                                              double g1, double b1, 
                                              double x2, double r2, 
                                              double g2, double b2 )
{
  int done;  
  
  // First, find all points in this range and remove them
  done = 0;
  while ( !done )
    {
    done = 1;
    
    this->Internal->FindNodeInRange.X1 = x1;
    this->Internal->FindNodeInRange.X2 = x2;
  
    vtkstd::vector<vtkCTFNode*>::iterator iter = 
      vtkstd::find_if(this->Internal->Nodes.begin(),
                      this->Internal->Nodes.end(),
                      this->Internal->FindNodeInRange );
  
    if ( iter != this->Internal->Nodes.end() )
      {
      delete *iter;
      this->Internal->Nodes.erase(iter);
      this->Modified();
      done = 0;
      }
    }

  // Now add the points
  this->AddRGBPoint( x1, r1, g1, b1, 0.5, 0.0 );
  this->AddRGBPoint( x2, r2, g2, b2, 0.5, 0.0 );
}