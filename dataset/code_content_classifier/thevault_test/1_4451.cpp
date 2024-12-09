int vtkActor::GetIsOpaque()
{
  // make sure we have a property
  if(!this->Property)
    {
    // force creation of a property
    this->GetProperty();
    }
  
  int result=this->Property->GetOpacity() >= 1.0;
  
  if(result && this->Texture)
    {
    result = !this->Texture->IsTranslucent();
    }
  if(result)
    {
    if(this->Mapper!=0 && this->Mapper->GetLookupTable()!=0)
      {
      result=this->Mapper->GetLookupTable()->IsOpaque();
      }
    }
  return result;
}