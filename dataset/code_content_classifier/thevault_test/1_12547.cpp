void vtkViewport::GetTiledSize(int* usize, int* vsize)
{
  int llx, lly;
  this->GetTiledSizeAndOrigin(usize, vsize, &llx, &lly);
}