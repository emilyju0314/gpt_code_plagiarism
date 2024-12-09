void vtkScatterPlotPainter::ReleaseDisplayList()
{
  if(this->DisplayListId>0)
    {
    glDeleteLists(this->DisplayListId,1);
    this->DisplayListId = 0;
    }
}