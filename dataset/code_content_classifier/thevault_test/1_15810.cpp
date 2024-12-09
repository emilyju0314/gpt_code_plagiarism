void
WarpX::RestrictCurrentFromFineToCoarsePatch (int lev)
{
    current_cp[lev][0]->setVal(0.0);
    current_cp[lev][1]->setVal(0.0);
    current_cp[lev][2]->setVal(0.0);

    const IntVect& refinement_ratio = refRatio(lev-1);

    std::array<const MultiFab*,3> fine { current_fp[lev][0].get(),
                                         current_fp[lev][1].get(),
                                         current_fp[lev][2].get() };
    std::array<      MultiFab*,3> crse { current_cp[lev][0].get(),
                                         current_cp[lev][1].get(),
                                         current_cp[lev][2].get() };
    CoarsenMR::Coarsen( *crse[0], *fine[0], refinement_ratio );
    CoarsenMR::Coarsen( *crse[1], *fine[1], refinement_ratio );
    CoarsenMR::Coarsen( *crse[2], *fine[2], refinement_ratio );
}