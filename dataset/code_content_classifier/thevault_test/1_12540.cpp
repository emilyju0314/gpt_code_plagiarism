vtkViewport::vtkViewport()
{
  this->VTKWindow = nullptr;

  this->Background[0] = 0;
  this->Background[1] = 0;
  this->Background[2] = 0;

  this->Background2[0] = 0.2;
  this->Background2[1] = 0.2;
  this->Background2[2] = 0.2;

  this->BackgroundAlpha = 0.0;

  this->GradientBackground = false;

  this->EnvironmentalBG[0] = 0;
  this->EnvironmentalBG[1] = 0;
  this->EnvironmentalBG[2] = 0;

  this->EnvironmentalBG2[0] = 0.2;
  this->EnvironmentalBG2[1] = 0.2;
  this->EnvironmentalBG2[2] = 0.2;

  this->GradientEnvironmentalBG = false;

  this->Viewport[0] = 0;
  this->Viewport[1] = 0;
  this->Viewport[2] = 1;
  this->Viewport[3] = 1;

  this->WorldPoint[0] = 0;
  this->WorldPoint[1] = 0;
  this->WorldPoint[2] = 0;
  this->WorldPoint[3] = 0;

  this->DisplayPoint[0] = 0;
  this->DisplayPoint[1] = 0;
  this->DisplayPoint[2] = 0;

  this->ViewPoint[0] = 0;
  this->ViewPoint[1] = 0;
  this->ViewPoint[2] = 0;

  this->Aspect[0] = this->Aspect[1] = 1.0;
  this->PixelAspect[0] = this->PixelAspect[1] = 1.0;
  this->Center[0] = 0.0;
  this->Center[1] = 0.0;

  this->Size[0] = 0;
  this->Size[1] = 0;

  this->Origin[0] = 0;
  this->Origin[1] = 0;

  this->PickedProp = nullptr;
  this->PickFromProps = nullptr;
  this->PickResultProps = nullptr;
  this->PickX1 = -1;
  this->PickY1 = -1;
  this->PickX2 = -1;
  this->PickY2 = -1;
  this->PickedZ = 1.0;

  this->Props = vtkPropCollection::New();
  this->Actors2D = vtkActor2DCollection::New();
}