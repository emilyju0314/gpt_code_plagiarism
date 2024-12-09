void ModelHeat::ComputeHessian(int A,int B,const Vector& tdstate,const Vector& st,const Vector& m,
                          const Vector& l,const Vector& x,Vector& y)
{
   MFEM_VERIFY(m.Size() >= GetParameterSize(),"Invalid Vector size " << m.Size() << ", should be (at least) " << GetParameterSize());

   /* XXX multiple coeffs */
   if (A == 1 && B == 2) /* L^T \otimes I_N F_XtM x */
   {
      MFEM_VERIFY(y.Size() == tdstate.Size(),"Invalid Vector size " << y.Size() << ", should be " << tdstate.Size());
      MFEM_VERIFY(x.Size() >= GetParameterSize(),"Invalid Vector size " << x.Size() << ", should be (at least) " << GetParameterSize());
      mpd->ComputeHessian_XM(l,m,x,y);
   }
   else if (A == 2 && B == 1) /* L^T \otimes I_P F_MXt x */
   {
      MFEM_VERIFY(x.Size() == tdstate.Size(),"Invalid Vector size " << x.Size() << ", should be " << tdstate.Size());
      MFEM_VERIFY(y.Size() >= GetParameterSize(),"Invalid Vector size " << y.Size() << ", should be (at least) " << GetParameterSize());
      mpd->ComputeHessian_MX(l,x,m,y);
   }
   else
   {
      MFEM_VERIFY(0,"ModelHeat::ComputeHessian not implemented for " << A << ", " << B << " pair");
   }
}