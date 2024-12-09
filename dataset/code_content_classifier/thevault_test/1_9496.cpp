void ImageFunctional::Update(int it, const Vector& F, const Vector& X,
                             const Vector& dX, const Vector& pX)
{
   if (!tv) return;
   if (!it)
   {
      tv->UpdateDual(X);
   }
   else
   {
      double lambda = 0.0;
      for (int i = 0; i < pX.Size(); i++)
      {
         if (dX[i] != 0.0)
         {
            lambda = (pX[i] - X[i])/dX[i];
            break;
         }
      }
      tv->UpdateDual(pX,dX,lambda);
   }
}