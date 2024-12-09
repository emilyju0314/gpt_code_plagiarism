void myfcn(Int_t &, Double_t *, Double_t &f, Double_t *par, Int_t) {
   //minimisation function computing the sum of squares of residuals
   Int_t np = error->GetN();
   f = 0;
   Double_t *x = error->GetX();
   Double_t *y = error->GetY();
   Double_t *ey = error->GetEY();
   //   Double_t *ey = error->GetEY();

   for (Int_t i=0;i<np;i++) {
      Double_t dr = y[i] - (par[0]+par[1]*x[i]);
      f += (dr*dr)/(ey[i]*ey[i]);
   }
}