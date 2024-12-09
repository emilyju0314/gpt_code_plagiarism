void vtkIsoVolume::ThresholdBetween(double lower, double upper)
{
  if(this->LowerThreshold != lower || this->UpperThreshold != upper)
    {
    this->LowerThreshold = lower;
    this->UpperThreshold = upper;
    this->Modified();
    }
}