void
WarpX::AddCurrentFromFineLevelandSumBoundary (int lev)
{
    ApplyFilterandSumBoundaryJ(lev, PatchType::fine);

    if (lev < finest_level) {
        // When there are current buffers, unlike coarse patch,
        // we don't care about the final state of them.

        const auto& period = Geom(lev).periodicity();
        for (int idim = 0; idim < 3; ++idim) {
            MultiFab mf(current_fp[lev][idim]->boxArray(),
                        current_fp[lev][idim]->DistributionMap(), current_fp[lev][idim]->nComp(), 0);
            mf.setVal(0.0);
            if (use_filter && current_buf[lev+1][idim])
            {
                // coarse patch of fine level
                IntVect ng = current_cp[lev+1][idim]->nGrowVect();
                ng += bilinear_filter.stencil_length_each_dir-1;
                MultiFab jfc(current_cp[lev+1][idim]->boxArray(),
                             current_cp[lev+1][idim]->DistributionMap(), current_cp[lev+1][idim]->nComp(), ng);
                bilinear_filter.ApplyStencil(jfc, *current_cp[lev+1][idim]);

                // buffer patch of fine level
                MultiFab jfb(current_buf[lev+1][idim]->boxArray(),
                             current_buf[lev+1][idim]->DistributionMap(), current_buf[lev+1][idim]->nComp(), ng);
                bilinear_filter.ApplyStencil(jfb, *current_buf[lev+1][idim]);

                MultiFab::Add(jfb, jfc, 0, 0, current_buf[lev+1][idim]->nComp(), ng);
                mf.ParallelAdd(jfb, 0, 0, current_buf[lev+1][idim]->nComp(), ng, IntVect::TheZeroVector(), period);

                WarpXSumGuardCells(*current_cp[lev+1][idim], jfc, period, 0, current_cp[lev+1][idim]->nComp());
            }
            else if (use_filter) // but no buffer
            {
                // coarse patch of fine level
                IntVect ng = current_cp[lev+1][idim]->nGrowVect();
                ng += bilinear_filter.stencil_length_each_dir-1;
                MultiFab jf(current_cp[lev+1][idim]->boxArray(),
                            current_cp[lev+1][idim]->DistributionMap(), current_cp[lev+1][idim]->nComp(), ng);
                bilinear_filter.ApplyStencil(jf, *current_cp[lev+1][idim]);
                mf.ParallelAdd(jf, 0, 0, current_cp[lev+1][idim]->nComp(), ng, IntVect::TheZeroVector(), period);
                WarpXSumGuardCells(*current_cp[lev+1][idim], jf, period, 0, current_cp[lev+1][idim]->nComp());
            }
            else if (current_buf[lev+1][idim]) // but no filter
            {
                MultiFab::Add(*current_buf[lev+1][idim],
                               *current_cp [lev+1][idim], 0, 0, current_buf[lev+1][idim]->nComp(),
                               current_cp[lev+1][idim]->nGrow());
                mf.ParallelAdd(*current_buf[lev+1][idim], 0, 0, current_buf[lev+1][idim]->nComp(),
                               current_buf[lev+1][idim]->nGrowVect(), IntVect::TheZeroVector(),
                               period);
                WarpXSumGuardCells(*(current_cp[lev+1][idim]), period, 0, current_cp[lev+1][idim]->nComp());
            }
            else // no filter, no buffer
            {
                mf.ParallelAdd(*current_cp[lev+1][idim], 0, 0, current_cp[lev+1][idim]->nComp(),
                               current_cp[lev+1][idim]->nGrowVect(), IntVect::TheZeroVector(),
                               period);
                WarpXSumGuardCells(*(current_cp[lev+1][idim]), period, 0, current_cp[lev+1][idim]->nComp());
            }
            MultiFab::Add(*current_fp[lev][idim], mf, 0, 0, current_fp[lev+1][idim]->nComp(), 0);
        }
        NodalSyncJ(lev+1, PatchType::coarse);
    }
    NodalSyncJ(lev, PatchType::fine);
}