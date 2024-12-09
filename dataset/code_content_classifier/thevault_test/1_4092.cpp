void update_gaussian(Vec3d X, int row, int col, int k){

    double rho = params.learning_rate() * eval_gaussian(X, row, col, k);

    mu[row][col][k] = (1.0 - rho) * mu[row][col][k] + rho * X;

    covar[row][col][k] = (1.0 - rho) * covar[row][col][k] + rho * norm(X - mu[row][col][k] , NORM_L2SQR);
}