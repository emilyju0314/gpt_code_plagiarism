CNRGmatrix(CNRGbasisarray A1){
     UpperTriangular=false;
     SaveMatYN=false;
     CalcAvg=false;
     IsComplex=false;
     CNRGarray::Nshell=A1.Nshell;
     CNRGarray::NQNumbers=A1.NQNumbers;
     CNRGarray::QNumbers=A1.QNumbers;
     CNRGarray::BlockBegEnd=A1.BlockBegEnd;
     CNRGarray::Kept=A1.Kept;
     //     CNRGarray::sizeBlock=A1.sizeBlock;
     iType=A1.iType;
     CNRGarray::totalS=A1.totalS; // tru -> there are totalS QNs 
     CNRGarray::Sqnumbers=A1.Sqnumbers; // position(s) of total S in QNumbers
   }