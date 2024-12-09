floatBO EchoBay::Reservoir::wr_scale_radius(SparseBO &Wr, const double scalingFactor)
{
    // Spectra solver for eigenvalues
    SparseGenMatProd<floatBO, 0x1> op(Wr);

    int param = 6 > Wr.rows() ? Wr.rows() : 6;
    VComplexBO evalues;
    floatBO scale_radius;
    int nconv;

    // General case with Nr > 2
    if(Wr.rows() > 2)
    {
        do
        {
            GenEigsSolver<floatBO, LARGEST_MAGN, SparseGenMatProd<floatBO, 0x1>> eigs(&op, 1, param);
            eigs.init();
            nconv = eigs.compute();
            param = (param + 10 > Wr.rows()) ? Wr.rows() : param + 10;
            if (nconv > 0){ //ok == SUCCESSFUL)
                evalues = eigs.eigenvalues();
            }
        } while (nconv < 1); //ok == NOT_CONVERGING);

        // Rescale Wr matrix with desired rho value
        floatBO spectral_radius = sqrt(pow(std::real(evalues[0]), 2) + pow(std::imag(evalues[0]), 2));
        scale_radius = scalingFactor / spectral_radius;
    }
    else // 2-by-2 matrix
    {
        // Find trace and determinant
        floatBO trace = Wr.coeff(0,0) + Wr.coeff(1,1);
        floatBO determinant = Wr.coeff(0,0)*Wr.coeff(1,1) - Wr.coeff(1,0)*Wr.coeff(0,1);

        // Calculate the two eigenvalues
        VComplexBO eigens = VComplexBO::Zero(2,1);
        eigens(0) = (trace + sqrt(trace*trace - 4.0*determinant))/2.0;
        eigens(1) = (trace - sqrt(trace*trace - 4.0*determinant))/2.0;
        floatBO magEigen[2] = {0};
        magEigen[0] = sqrt(eigens(0).real()*eigens(0).real() + eigens(0).imag()*eigens(0).imag());
        magEigen[1] = sqrt(eigens(1).real()*eigens(1).real() + eigens(1).imag()*eigens(1).imag());
        scale_radius = magEigen[0] > magEigen[1] ? scalingFactor/magEigen[0] : scalingFactor/magEigen[1];
    }
    return scale_radius;
}