real field::fieldMax() {
    real localMax, globalMax;

    localMax = blitz::max(blitz::abs(F));

    /***************************************************************************************************************
     * DID YOU KNOW?                                                                                               *
     * In the line above, most compilers will not complain even if you omitted the namespace specification blitz:: *
     * This behaviour wasted an hour of my development time (including the effort of making this nice box).        *
     * Check Ref. [4] in README for explanation.                                                                   *
     ***************************************************************************************************************/

    MPI_Allreduce(&localMax, &globalMax, 1, MPI_FP_REAL, MPI_MAX, MPI_COMM_WORLD);

    return globalMax;
}