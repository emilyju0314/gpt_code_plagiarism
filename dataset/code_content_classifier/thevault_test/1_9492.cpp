void ModelHeat::ComputeGradientAdjoint(const Vector& adj, const Vector& tdstate, const Vector& state, const Vector& m, Vector& g)
{
   MFEM_VERIFY(m.Size() >= GetParameterSize(),"Invalid Vector size " << m.Size() << ", should be (at least) " << GetParameterSize());
   MFEM_VERIFY(g.Size() >= GetParameterSize(),"Invalid Vector size " << g.Size() << ", should be (at least) " << GetParameterSize());

   /* XXX multiple coeffs */
   mpd->ComputeGradientAdjoint(adj,tdstate,m,g);
}