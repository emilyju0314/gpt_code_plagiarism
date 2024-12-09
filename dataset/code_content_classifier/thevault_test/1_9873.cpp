vtkPolyData *vtkScatterPlotMapper::GetGlyphSource(int id)
{
  if ( id < 0 || id >= this->GetNumberOfInputConnections(GLYPHS_PORT) )
    {
    return NULL;
    }

  return vtkPolyData::SafeDownCast(
    this->GetInputDataObject(GLYPHS_PORT, id));
}