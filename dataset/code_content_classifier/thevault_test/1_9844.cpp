int vtkGenericEnSightReader2::ReadBinaryLine(char result[80])
{
  int n = static_cast<int>(fread(result, sizeof(char), 80, this->IFile));

  if ((n<80) || feof(this->IFile) || ferror(this->IFile))
    {
    return 0;
    }

  return 1;
}