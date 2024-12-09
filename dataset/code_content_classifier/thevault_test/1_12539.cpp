bool TestDeepMultiBlock()
{
  vtkNew<vtkMultiBlockDataSet> multiBlock;
  vtkNew<vtkMultiPieceDataSet> multiPiece;
  vtkNew<vtkUnstructuredGrid> ug;

  multiBlock->SetNumberOfBlocks(1);
  multiBlock->SetBlock(0, multiPiece);
  multiPiece->SetNumberOfPieces(1);
  multiPiece->SetPiece(0, ug);

  vtkNew<vtkGhostCellsGenerator> generator;
  generator->SetNumberOfGhostLayers(1);
  generator->BuildIfRequiredOff();
  generator->SetInputData(multiBlock);

  // We are just checking if the output structure is generated without crashing.
  // This will crash if the structure of the output doesn't take deep multi blocks into account.
  generator->Update();

  return true;
}