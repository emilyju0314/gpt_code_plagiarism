void vtkCamera::ComputeProjAndViewParams()
{
  this->eyeOffsetMat->Identity();
  this->eyePosMat->Identity();
  this->negEyePosMat->Identity();
  this->HeadTrackedViewMat->Identity();

// Compute Projection Matrix Parameters using head
  if ( this->LeftEye )
    {
    eyeOffsetMat->SetElement( 0, 3, -this->EyeOffset );
    vtkMatrix4x4::Multiply4x4( this->HeadPose, eyeOffsetMat, eyePosMat );
    }
  else
    {
    eyeOffsetMat->SetElement( 0, 3, this->EyeOffset );
    vtkMatrix4x4::Multiply4x4( this->HeadPose, eyeOffsetMat, eyePosMat );
    }

// Get eye position on the surface of the screen which is nothing
// but the translation component of the eyePosMat
  double eyeSurface[4];
  eyeSurface[0] = eyePosMat->GetElement( 0, 3 );
  eyeSurface[1] = eyePosMat->GetElement( 1, 3 );
  eyeSurface[2] = eyePosMat->GetElement( 2, 3 );
  eyeSurface[3] = 0.0;

  this->Surface2Base->MultiplyPoint( eyeSurface, eyeSurface );

  double e2Screen = ( this->ScaleFactor * this->O2Screen ) + eyeSurface[2];
  double e2Right  = ( this->ScaleFactor * this->O2Right )  - eyeSurface[0];
  double e2Left   = ( this->ScaleFactor * this->O2Left )   + eyeSurface[0];
  double e2Top    = ( this->ScaleFactor * this->O2Top )    - eyeSurface[1];
  double e2Bottom = ( this->ScaleFactor * this->O2Bottom ) + eyeSurface[1];

  //double o2Near = this->ClippingRange[0] / e2Screen;
  double o2Near = 0.01 / e2Screen;

  // Setting the Projection matrix parameters for HeadTracked Camera
  this->AsymLeft   = -( e2Left   * o2Near ) ;
  this->AsymRight  =   e2Right   * o2Near ;
  this->AsymTop    =     e2Top   * o2Near;
  this->AsymBottom = -( e2Bottom * o2Near );

  // Setting the View (ModelView) matrix for HeadTracked Camera
  this->EyePos[0] = eyePosMat->GetElement( 0, 3 );
  this->EyePos[1] = eyePosMat->GetElement( 1, 3 );
  this->EyePos[2] = eyePosMat->GetElement( 2, 3 );

  negEyePosMat->SetElement( 0, 3, this->EyePos[0]*-1 );
  negEyePosMat->SetElement( 1, 3, this->EyePos[1]*-1 );
  negEyePosMat->SetElement( 2, 3, this->EyePos[2]*-1 );
  vtkMatrix4x4::Multiply4x4( this->Surface2Base->GetMatrix(),
                             this->negEyePosMat,
                             this->HeadTrackedViewMat);

}