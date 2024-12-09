bool pqContextView::canDisplay(pqOutputPort* opPort) const
{
  pqPipelineSource* source = opPort? opPort->getSource() :0;
  vtkSMSourceProxy* sourceProxy = source ?
    vtkSMSourceProxy::SafeDownCast(source->getProxy()) : 0;
  if(!opPort || !source ||
     opPort->getServer()->GetConnectionID() !=
     this->getServer()->GetConnectionID() || !sourceProxy ||
     sourceProxy->GetOutputPortsCreated()==0)
    {
    return false;
    }

  if (sourceProxy->GetHints() &&
    sourceProxy->GetHints()->FindNestedElementByName("Plotable"))
    {
    return true;
    }

  vtkPVDataInformation* dataInfo = opPort->getDataInformation();
  if ( !dataInfo )
    {
    return false;
    }

  QString className = dataInfo->GetDataClassName();
  if( className == "vtkTable" )
    {
    return true;
    }
  else if(className == "vtkImageData" || className == "vtkRectilinearGrid")
    {
    int extent[6];
    dataInfo->GetExtent(extent);
    int temp[6]={0, 0, 0, 0, 0, 0};
    int dimensionality = vtkStructuredData::GetDataDimension(
      vtkStructuredData::SetExtent(extent, temp));
    if (dimensionality == 1)
      {
      return true;
      }
    }
  return false;
}