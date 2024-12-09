void normalise_prior(int row, int col){
    double s = 0.0;
    for(int i = 0; i < params.maxModes(); i++){
        s += pr[row][col][i];
    }
    if(s == 0){
        cout<<"Trouble at: "<< row <<" "<< col <<endl;
        return ;
    }
    for(int i = 0; i < params.maxModes(); i++)
        pr[row][col][i] /= s;
}