dvariable Tier3_Calculator::calcBmsy(dvariable R, ostream& cout){
    if (debug) cout<<"starting double Tier3_Calculator::calcBmsy(dvariable R)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    Bmsy = XX*calcB100(R,cout);
    if (debug) {
        cout<<"Bmsy = "<<Bmsy<<endl;
        cout<<"finished double Tier3_Calculator::calcBmsy(dvariable R)"<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return 1.0*Bmsy;
}