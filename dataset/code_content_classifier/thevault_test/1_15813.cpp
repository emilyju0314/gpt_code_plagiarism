SpectralSolverRZ::SpectralSolverRZ(amrex::BoxArray const & realspace_ba,
                                   amrex::DistributionMapping const & dm,
                                   int const n_rz_azimuthal_modes,
                                   int const norder_z, bool const nodal,
                                   amrex::RealVect const dx, amrex::Real const dt,
                                   int const lev,
                                   bool const pml )
{

    // Initialize all structures using the same distribution mapping dm

    // - The k space object contains info about the size of
    //   the spectral space corresponding to each box in `realspace_ba`,
    //   as well as the value of the corresponding k coordinates.
    SpectralKSpaceRZ k_space(realspace_ba, dm, dx);

    // - Select the algorithm depending on the input parameters
    //   Initialize the corresponding coefficients over k space
    //   PML is not supported.
    algorithm = std::unique_ptr<PsatdAlgorithmRZ>(
        new PsatdAlgorithmRZ(k_space, dm, n_rz_azimuthal_modes, norder_z, nodal, dt));

    // - Initialize arrays for fields in spectral space + FFT plans
    field_data = SpectralFieldDataRZ(realspace_ba, k_space, dm,
                                     algorithm->getRequiredNumberOfFields(),
                                     n_rz_azimuthal_modes, lev);

}