int vtkGenericEnSightReader2::ReadLine(char result[256])
{
  this->IS->getline(result,256);
//  if (this->IS->eof())
  if (this->IS->fail())
      {
      // Reset the error flag before returning. This way, we can keep working
      // if we handle the error downstream.
      this->IS->clear();
      return 0;
      }

  return 1;
}