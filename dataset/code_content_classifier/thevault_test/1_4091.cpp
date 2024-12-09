double eval_gaussian(Vec3d X,int row,int col, int k){
    double sig_square = covar[row][col][k];
    double gaus  = exp(-0.5 * norm(X - mu[row][col][k] , NORM_L2SQR) / sig_square );
    gaus /= pow(2*PI*sig_square,1.5);
    return gaus;
}