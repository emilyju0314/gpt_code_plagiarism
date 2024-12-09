std::complex<double> 
gradIncident(const double nvec[], const double kvec[], 
             const double point[]) {
    return J1*(nvec[0]*kvec[0] + nvec[1]*kvec[1])*incident(kvec, point);
}