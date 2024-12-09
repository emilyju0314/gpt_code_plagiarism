double TwoRayGround::TwoRay(double Pt, double Gt, double Gr, double ht, double hr, double L, double d)
{
        /*
         *  Two-ray ground reflection model.
         *
         *	     Pt * Gt * Gr * (ht^2 * hr^2)
         *  Pr = ----------------------------
         *           d^4 * L
         *
         * The original equation in Rappaport's book assumes L = 1.
         * To be consistant with the free space equation, L is added here.
         */
  return Pt * Gt * Gr * (hr * hr * ht * ht) / (d * d * d * d * L);
}