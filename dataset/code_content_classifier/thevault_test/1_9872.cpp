void vtkScatterPlotMapper::SetGlyphSourceConnection(int id,
  vtkAlgorithmOutput *algOutput)
{
  if (id < 0)
    {
    vtkErrorMacro("Bad index " << id << " for source.");
    return;
    }

  int numConnections = this->GetNumberOfInputConnections(GLYPHS_PORT);
  if (id < numConnections)
    {
    this->SetNthInputConnection(GLYPHS_PORT, id, algOutput);
    }
  else if (id == numConnections && algOutput)
    {
    this->AddInputConnection(GLYPHS_PORT, algOutput);
    }
  else if (algOutput)
    {
    vtkWarningMacro("The source id provided is larger than the maximum "
      "source id, using " << numConnections << " instead.");
    this->AddInputConnection(GLYPHS_PORT, algOutput);
    }
}