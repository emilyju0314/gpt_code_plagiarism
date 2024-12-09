void vtkCamera::SetRoll(double roll)
{
// roll is a rotation of camera view up about the direction of projection
  vtkDebugMacro(<< " Setting Roll to " << roll << "");

// subtract the current roll
  roll -= this->GetRoll();

  if (fabs(roll) < 0.00001)
    {
    return;
    }

  this->Roll(roll);
}