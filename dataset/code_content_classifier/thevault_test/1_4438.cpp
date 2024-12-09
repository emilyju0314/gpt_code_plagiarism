void vtkVPICReader::LoadComponent(float* varData, float* block,
                                  int comp, int numberOfComponents)
{

  // Load into the data array by tuple so place data every comp'th spot
  int pos = comp;
  for (int k = 0; k < this->SubDimension[2]; k++) {
    int kk = k + this->Start[2];
    for (int j = 0; j < this->SubDimension[1]; j++) {
      int jj = j + this->Start[1];
      for (int i = 0; i < this->SubDimension[0]; i++) {
        int ii = i + this->Start[0];

        int index = (kk * this->GhostDimension[0] * this->GhostDimension[1]) +
                    (jj * this->GhostDimension[0]) + ii;

        varData[pos] = block[index];
        pos += numberOfComponents;
      }
    }
  }
}