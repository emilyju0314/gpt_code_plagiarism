StructuredGridFittingWorker(const vtkSmartPointer<vtkPoints> points[6],
      vtkNew<vtkStaticPointLocator> locator[6],
      const ExtentType& extent, StructuredGridBlockStructure::Grid2D& grid, int dimension)
    : Points{ points[0]->GetData(), points[1]->GetData(), points[2]->GetData(), points[3]->GetData(),
        points[4]->GetData(), points[5]->GetData() }
    , Locator{ locator[0], locator[1], locator[2], locator[3], locator[4], locator[5] }
    , Grid(grid)
    , Dimension(dimension)
  {
    // We compute the extent of each external face of the neighbor block.
    for (int i = 0; i < 6; ++i)
    {
      ExtentType& e = this->Extent[i];
      e[i] = extent[i];
      e[i % 2 ? i - 1 : i + 1] = extent[i];
      for (int j = 0; j < 6; ++j)
      {
        if (i / 2 != j / 2)
        {
          e[j] = extent[j];
        }
      }
    }
  }