CNRGbasisarray(CNRGarray A1){
     CNRGarray::Nshell=A1.Nshell;
     CNRGarray::NQNumbers=A1.NQNumbers;
     CNRGarray::QNumbers=A1.QNumbers;
     CNRGarray::dEn=A1.dEn;
     CNRGarray::dEigVec=A1.dEigVec;
     CNRGarray::cEigVec=A1.cEigVec;
     CNRGarray::Kept=A1.Kept;
     CNRGarray::BlockBegEnd=A1.BlockBegEnd;
     CNRGarray::totalS=A1.totalS; // tru -> there are totalS QNs 
     CNRGarray::Sqnumbers=A1.Sqnumbers; // position(s) of total S in QNumbers
   }