void
SoKnot::computeBBox(SoAction * action, SbBox3f & box, SbVec3f & center)
{
  
  center = (const float*)&(knot->getCenter());
  Vector3 BBox_Min, BBox_Max;
  this->knot->getBoundingBox(BBox_Min,BBox_Max);
  
  box.setBounds(SbVec3f((const float*)&BBox_Min),
		SbVec3f((const float*)&BBox_Max));
  
}