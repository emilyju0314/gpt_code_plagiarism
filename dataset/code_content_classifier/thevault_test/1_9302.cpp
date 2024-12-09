void ModelOptions::writeToR(ostream& os, std::string nm, int indent) {
    for (int n=0;n<indent;n++) os<<tb;
        os<<nm<<"=list("<<endl;
    indent++;
        for (int n=0;n<indent;n++) os<<tb;
        os<<"initNatZ="<<optInitNatZ<<cc<<"natmort="<<optParamNM<<cc<<"growth="<<optGrowthPDF<<cc<<endl;
        os<<"prM2M=list(";
            os<<"pen.smoothing="; wts::writeToR(os,wgtPenSmthPrM2M); os<<cc<<endl;
            os<<"pen.nondecreasing="; wts::writeToR(os,wgtPenNonDecPrM2M); os<<"),"<<endl;
        os<<"npSel=list(";
            os<<"pen.smoothing="; wts::writeToR(os,wgtPenSmthNPSel); os<<"),"<<endl;
        os<<"cvFDevsPen="<<cvFDevsPen<<cc<<"phsDecr="<<phsDecrFDevsPen<<cc<<"phsZero="<<phsZeroFDevsPen<<cc
          <<"wgtLastDevPen="<<wgtSqSumDevsPen<<cc<<"phsLastDevsPen="<<phsSqSumDevsPen<<cc;
        os<<"effXtrapScenarios="; ptrEffXtrapScenarios->writeToR(os); os<<"),"<<endl;
        os<<"oflOptions=list(";
            os<<"optAvgCapRate="; wts::writeToR(os,optOFLAvgCapRate); os<<cc<<endl;
            os<<"numYears="; wts::writeToR(os,oflNumYrsForAvgCapRate); os<<cc<<endl;
            os<<"rateInfo="; wts::writeToR(os,oflAvgCapRateInfo); os<<")"<<cc<<endl;
        os<<"itRewgtOptions=list(";
            os<<"option="<<optIterativeReweighting<<cc<<endl;
            os<<"phase="<<phsIterativeReweighting<<cc<<endl;
            os<<"maxIts="<<maxIterations<<")"<<endl;
    indent--;
    for (int n=0;n<indent;n++) os<<tb;
        os<<")";
}