bool SynchronizeGridExtents(StructuredGridBlockStructure& localBlockStructure,
    StructuredGridBlockStructure& blockStructure)
{
  const ExtentType& extent = blockStructure.Extent;

  if (localBlockStructure.DataDimension != blockStructure.DataDimension ||
      extent[0] > extent[1] || extent[2] > extent[3] || extent[4] > extent[5])
  {
    return false;
  }
  const ExtentType& localExtent = localBlockStructure.Extent;
  const vtkSmartPointer<vtkPoints>* localPoints = localBlockStructure.OuterPointLayers;
  const vtkSmartPointer<vtkPoints>* points = blockStructure.OuterPointLayers;

  // This grid will be set by the structured grid fitting worker if the 2 blocks are connected.
  StructuredGridBlockStructure::Grid2D& gridInterface = blockStructure.GridInterface;

  // We need locators to query points inside grids.
  // Locators need `vtkDataSet`, so we create a `vtkPointSet` with the points of each face of the
  // neighboring block.
  vtkNew<vtkStaticPointLocator> locator[6];
  for (int id = 0; id < 6; ++id)
  {
    vtkNew<vtkPointSet> ps;
    ps->SetPoints(points[id]);
    locator[id]->SetDataSet(ps);
    locator[id]->BuildLocator();
  }

  int dimension = (localExtent[0] != localExtent[1]) + (localExtent[2] != localExtent[3]) +
    (localExtent[4] != localExtent[5]);

  using Dispatcher = vtkArrayDispatch::Dispatch;
  StructuredGridFittingWorker worker(points, locator, extent, gridInterface, dimension);

  // We look for a connection until either we tried them all, or if we found the best connection,
  // i.e. a full 2D grid has been found.
  // We iterate on each face of the local block.
  for (int dim = 0; dim < 3 && !worker.BestConnectionFound; ++dim)
  {
    if (localExtent[2 * dim] == localExtent[2 * dim + 1])
    {
      continue;
    }

    for (worker.LocalExtentIndex = 2 * dim;
        !worker.BestConnectionFound && worker.LocalExtentIndex <= 2 * dim + 1;
        ++worker.LocalExtentIndex)
    {
      vtkNew<vtkStaticPointLocator> localLocator;
      vtkNew<vtkPointSet> ps;

      ps->SetPoints(localPoints[worker.LocalExtentIndex]);
      localLocator->SetDataSet(ps);
      localLocator->BuildLocator();

      worker.LocalLocator = localLocator;
      worker.LocalExtent = localExtent;
      worker.LocalExtent[worker.LocalExtentIndex + (worker.LocalExtentIndex % 2 ? -1 : 1)] =
        localExtent[worker.LocalExtentIndex];

      Dispatcher::Execute(localPoints[worker.LocalExtentIndex]->GetData(), worker);
    }
  }

  if (!worker.Connected)
  {
    return false;
  }

  const auto& localGrid = worker.LocalGrid;
  int xdim = (localGrid.ExtentId + 2) % 6;
  xdim -= xdim % 2;
  int ydim = (localGrid.ExtentId + 4) % 6;
  ydim -= ydim % 2;

  ExtentType& shiftedExtent = blockStructure.ShiftedExtent;

  // We match extents to local extents.
  // We know the intersection already, so we ca just use the local grid interface extent.
  shiftedExtent[xdim] = localGrid.StartX;
  shiftedExtent[xdim + 1] = localGrid.EndX;
  shiftedExtent[ydim] = localGrid.StartY;
  shiftedExtent[ydim + 1] = localGrid.EndY;

  const auto& grid = worker.Grid;

  // Concerning the dimension orthogonal to the interface grid, we just copy the corresponding value
  // from the local extent, and we add the "depth" of the neighbor grid by looking at what is in
  // `extent`.
  int oppositeExtentId = grid.ExtentId + (grid.ExtentId % 2 ? -1 : 1);
  int deltaExtent = (localGrid.ExtentId % 2 ? 1 : -1) *
    std::abs(extent[grid.ExtentId] - extent[oppositeExtentId]);
  shiftedExtent[localGrid.ExtentId + (localGrid.ExtentId % 2 ? -1 : 1)] =
    localExtent[localGrid.ExtentId];
  shiftedExtent[localGrid.ExtentId] = localExtent[localGrid.ExtentId] + deltaExtent;

  int xxdim = (grid.ExtentId + 2) % 6;
  xxdim -= xxdim % 2;
  int yydim = (grid.ExtentId + 4) % 6;
  yydim -= yydim % 2;

  // We want to match 2 adjacent grids that could have dimension x of local grid map dimension z of
  // neighboring grid. For each dimension, 2 cases are to be taken into account:
  // - grids touch on the corner (case A)
  //   In this case, when warping neighbors extent into our referential, one of the neighbor's
  //   extent matches one of ours, and the other is shifted by the width of the neighbor
  // - grids actually overlap (case B)
  //   In this case, we can use the difference between respective StartX of each grid and reposition
  //   it w.r.t. local extent.

  // Dim X
  // case A
  if (localGrid.StartX == localGrid.EndX)
  {
    if (localGrid.StartX == localExtent[xdim])
    {
      shiftedExtent[xdim + 1] = localExtent[xdim];
      shiftedExtent[xdim] = shiftedExtent[xdim + 1] - (extent[xxdim + 1] - extent[xxdim]);
    }
    else
    {
      shiftedExtent[xdim] = localExtent[xdim + 1];
      shiftedExtent[xdim + 1] = shiftedExtent[xdim + 1] + (extent[xxdim + 1] - extent[xxdim]);
    }
  }
  // case B
  else
  {
    shiftedExtent[xdim] = localGrid.StartX - grid.StartX + extent[xdim];
    shiftedExtent[xdim + 1] = shiftedExtent[xdim] + extent[xxdim + 1] - extent[xxdim];
  }

  // Dim Y
  // case A
  if (localGrid.StartY == localGrid.EndY)
  {
    if (localGrid.StartY == localExtent[ydim])
    {
      shiftedExtent[ydim + 1] = localExtent[ydim];
      shiftedExtent[ydim] = shiftedExtent[ydim + 1] - (extent[yydim + 1] - extent[yydim]);
    }
    else
    {
      shiftedExtent[ydim] = localExtent[ydim + 1];
      shiftedExtent[ydim + 1] = shiftedExtent[ydim + 1] + (extent[yydim + 1] - extent[yydim]);
    }
  }
  // case B
  else
  {
    shiftedExtent[ydim] = localGrid.StartY - grid.StartY + extent[ydim];
    shiftedExtent[ydim + 1] = shiftedExtent[ydim] + extent[yydim + 1] - extent[yydim];
  }

  return true;
}