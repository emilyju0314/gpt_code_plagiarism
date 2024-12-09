bool compVector3fX(const vtkIndexedVector2f& v1,
                   const vtkIndexedVector2f& v2)
{
  if (v1.pos.X() < v2.pos.X())
    {
    return true;
    }
  else
    {
    return false;
    }
}