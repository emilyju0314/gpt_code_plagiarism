BOOL CheckTangent(int n, Curve<TVec> &c) {
return (c[n].isProper() && c[n].getPrevious().isProper());
/*
 if ((c[n].getPoint()-c.getPrevious(n).getPoint()).dot(c[n].getTangent()) <= 0)
   return FALSE;
 if((c.getNext(n).getPoint()-c[n].getPoint()).dot(c[n].getTangent()) <= 0)
   return FALSE;
 return TRUE;
*/
}