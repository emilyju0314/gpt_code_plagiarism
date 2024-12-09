void vtkCamera::PartialCopy(vtkCamera *source)
{
  assert("pre: source_exists" && source!=0);
  assert("pre: not_this" && source!=this);

  int i;

  i=0;
  while(i<2)
    {
    this->WindowCenter[i]=source->WindowCenter[i];
    this->ObliqueAngles[i]=source->ObliqueAngles[i];
    this->ClippingRange[i]=source->ClippingRange[i];
    ++i;
    }
  i=0;
  while(i<3)
    {
    this->FocalPoint[i]=source->FocalPoint[i];
    this->Position[i]=source->Position[i];
    this->ViewUp[i]=source->ViewUp[i];
    this->DirectionOfProjection[i]=source->DirectionOfProjection[i];
    this->ViewPlaneNormal[i]=source->ViewPlaneNormal[i];
    this->ViewShear[i]=source->ViewShear[i];
    ++i;
    }

  this->ViewAngle=source->ViewAngle;
  this->EyeAngle=source->EyeAngle;
  this->ParallelProjection=source->ParallelProjection;
  this->ParallelScale=source->ParallelScale;
  this->Stereo=source->Stereo;
  this->LeftEye=source->LeftEye;
  this->Thickness=source->Thickness;
  this->Distance=source->Distance;
  this->UseHorizontalViewAngle=source->UseHorizontalViewAngle;
  this->FocalDisk=source->FocalDisk;
  this->ViewingRaysMTime=source->ViewingRaysMTime;
}