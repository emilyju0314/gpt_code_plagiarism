void vtkScatterPlotMapper::CopyInformationToSubMapper(
  vtkPainterPolyDataMapper *mapper)
{
  assert("pre: mapper_exists" && mapper!=0);
  if(!mapper)
    {
    vtkErrorMacro("Mapper can't be NULL. ");
    return;
    }

  // see void vtkPainterPolyDataMapper::UpdatePainterInformation()

  mapper->SetStatic(this->Static);
  mapper->ScalarVisibilityOff();
  // not used
  //mapper->SetClippingPlanes(this->ClippingPlanes);

  mapper->SetResolveCoincidentTopology(this->GetResolveCoincidentTopology());
  mapper->SetResolveCoincidentTopologyZShift(
    this->GetResolveCoincidentTopologyZShift());

  // ResolveCoincidentTopologyPolygonOffsetParameters is static
  mapper->SetResolveCoincidentTopologyPolygonOffsetFaces(
    this->GetResolveCoincidentTopologyPolygonOffsetFaces());
  mapper->SetImmediateModeRendering(this->NestedDisplayLists);//this->ImmediateModeRendering
                                    // || vtkMapper::GetGlobalImmediateModeRendering());// ||
                                    //!this->NestedDisplayLists);
}