void FiniteDifferenceSolver::EvolveBPML (
    std::array< amrex::MultiFab*, 3 > Bfield,
    std::array< amrex::MultiFab*, 3 > const Efield,
    amrex::Real const dt ) {

   // Select algorithm (The choice of algorithm is a runtime option,
   // but we compile code for each algorithm, using templates)
#ifdef WARPX_DIM_RZ
    amrex::Abort("PML are not implemented in cylindrical geometry.");
#else
    if (m_do_nodal) {

        EvolveBPMLCartesian <CartesianNodalAlgorithm> ( Bfield, Efield, dt );

    } else if (m_fdtd_algo == MaxwellSolverAlgo::Yee) {

        EvolveBPMLCartesian <CartesianYeeAlgorithm> ( Bfield, Efield, dt );

    } else if (m_fdtd_algo == MaxwellSolverAlgo::CKC) {

        EvolveBPMLCartesian <CartesianCKCAlgorithm> ( Bfield, Efield, dt );

    } else {
        amrex::Abort("Unknown algorithm");
    }
#endif
}