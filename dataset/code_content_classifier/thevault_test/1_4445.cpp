void vtkLookupTable::SetTableValue(vtkIdType indx, double rgba[4])
{
  // Check the index to make sure it is valid
  if (indx < 0)
    {
    vtkErrorMacro("Can't set the table value for negative index " << indx);
    return;
    }
  if (indx >= this->NumberOfColors)
    {
    vtkErrorMacro("Index " << indx << 
                  " is greater than the number of colors " << 
                  this->NumberOfColors);
    return;
    }

  unsigned char *_rgba = this->Table->WritePointer(4*indx,4);

  _rgba[0] = static_cast<unsigned char>(rgba[0]*255.0f + 0.5f);
  _rgba[1] = static_cast<unsigned char>(rgba[1]*255.0f + 0.5f);
  _rgba[2] = static_cast<unsigned char>(rgba[2]*255.0f + 0.5f);
  _rgba[3] = static_cast<unsigned char>(rgba[3]*255.0f + 0.5f);

  this->InsertTime.Modified();
  this->Modified();
}