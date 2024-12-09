void PDBilinearFormIntegrator::ComputeElementGradientAdjoint_Internal(const FiniteElement *sel, const Vector& svals,
                                                                      const FiniteElement *ael, const Vector& avals,
                                                                      ElementTransformation *eltrans,
                                                                      Vector& ovals)
{
   pdcoeff->SetUseDerivCoefficients();
   ParFiniteElementSpace *pfes = pdcoeff->pfes;

   int e = eltrans->ElementNo;
   Array<int> pdofs;
   pfes->GetElementVDofs(e, pdofs);

   const int ngf = pdcoeff->GetComponents();
   ovals.SetSize(pdofs.Size()*ngf);

   DenseMatrix elmat;
   for (int g = 0; g < ngf; g++)
   {
      for (int k = 0; k < pdofs.Size(); k++)
      {
         pdcoeff->ElemDeriv(g,e,k,1.0);

         if (sel != ael)
         {
            AssembleElementMatrix2(*ael,*sel,*eltrans,elmat);
         }
         else
         {
            AssembleElementMatrix(*sel,*eltrans,elmat);
         }
         ovals[k + g*pdofs.Size()] = elmat.InnerProduct(avals,svals);
      }
   }
   pdcoeff->SetUseDerivCoefficients(false);
}