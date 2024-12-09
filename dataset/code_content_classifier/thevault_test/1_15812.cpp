void
WarpX::AddRhoFromFineLevelandSumBoundary(int lev, int icomp, int ncomp)
{
    if (!rho_fp[lev]) return;

    ApplyFilterandSumBoundaryRho(lev, PatchType::fine, icomp, ncomp);

    if (lev < finest_level){

        const auto& period = Geom(lev).periodicity();
        MultiFab mf(rho_fp[lev]->boxArray(),
                    rho_fp[lev]->DistributionMap(),
                    ncomp, 0);
        mf.setVal(0.0);
        if (use_filter && charge_buf[lev+1])
        {
            // coarse patch of fine level
            IntVect ng = rho_cp[lev+1]->nGrowVect();
            ng += bilinear_filter.stencil_length_each_dir-1;
            MultiFab rhofc(rho_cp[lev+1]->boxArray(),
                         rho_cp[lev+1]->DistributionMap(), ncomp, ng);
            bilinear_filter.ApplyStencil(rhofc, *rho_cp[lev+1], icomp, 0, ncomp);

            // buffer patch of fine level
            MultiFab rhofb(charge_buf[lev+1]->boxArray(),
                           charge_buf[lev+1]->DistributionMap(), ncomp, ng);
            bilinear_filter.ApplyStencil(rhofb, *charge_buf[lev+1], icomp, 0, ncomp);

            MultiFab::Add(rhofb, rhofc, 0, 0, ncomp, ng);
            mf.ParallelAdd(rhofb, 0, 0, ncomp, ng, IntVect::TheZeroVector(), period);
            WarpXSumGuardCells( *rho_cp[lev+1], rhofc, period, icomp, ncomp );
        }
        else if (use_filter) // but no buffer
        {
            IntVect ng = rho_cp[lev+1]->nGrowVect();
            ng += bilinear_filter.stencil_length_each_dir-1;
            MultiFab rf(rho_cp[lev+1]->boxArray(), rho_cp[lev+1]->DistributionMap(), ncomp, ng);
            bilinear_filter.ApplyStencil(rf, *rho_cp[lev+1], icomp, 0, ncomp);
            mf.ParallelAdd(rf, 0, 0, ncomp, ng, IntVect::TheZeroVector(), period);
            WarpXSumGuardCells( *rho_cp[lev+1], rf, period, icomp, ncomp );
        }
        else if (charge_buf[lev+1]) // but no filter
        {
            MultiFab::Add(*charge_buf[lev+1],
                           *rho_cp[lev+1], icomp, icomp, ncomp,
                           rho_cp[lev+1]->nGrow());
            mf.ParallelAdd(*charge_buf[lev+1], icomp, 0,
                           ncomp,
                           charge_buf[lev+1]->nGrowVect(), IntVect::TheZeroVector(),
                           period);
            WarpXSumGuardCells(*(rho_cp[lev+1]), period, icomp, ncomp);
        }
        else // no filter, no buffer
        {
            mf.ParallelAdd(*rho_cp[lev+1], icomp, 0, ncomp,
                           rho_cp[lev+1]->nGrowVect(), IntVect::TheZeroVector(),
                           period);
            WarpXSumGuardCells(*(rho_cp[lev+1]), period, icomp, ncomp);
        }
        MultiFab::Add(*rho_fp[lev], mf, 0, icomp, ncomp, 0);
        NodalSyncRho(lev+1, PatchType::coarse, icomp, ncomp);
    }

    NodalSyncRho(lev, PatchType::fine, icomp, ncomp);
}