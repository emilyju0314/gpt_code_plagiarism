std::vector<double> JMT(std::vector< double> start, std::vector <double> end, double t)
{
    double t2 = t * t, t3 = t2 * t, t4 = t3 * t, t5 = t4 * t;
    Eigen::MatrixXd A(3,3);
    Eigen::VectorXd b(3);
     
    A << t3, t4, t5, 3*t2, 4*t3, 5*t4, 6*t, 12*t2, 20*t3;
    b << end[0] - (start[0] + start[1]*t + start[2]*t2/2),
         end[1] - (start[1] + start[2] * t),
         end[2] - start[2];
    Eigen::VectorXd alpha = A.colPivHouseholderQr().solve(b);
    return {start[0], start[1], start[2]/2, alpha(0), alpha(1), alpha(2)};
}