vtkPolyData *vtkScatterPlotPainter::GetGlyphSource(int id)
{
  if (!this->SourceGlyphMappers)
    {
    return NULL;
    }
  vtkPainterPolyDataMapper* mapper = vtkPainterPolyDataMapper::SafeDownCast(
    this->SourceGlyphMappers->GetItemAsObject(id));
  return mapper ? vtkPolyData::SafeDownCast(mapper->GetInput()) : NULL;
}