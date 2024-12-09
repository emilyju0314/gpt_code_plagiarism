Vector<const MultiFab*> Maestro::PlotFileMF(
    const int nPlot, const Real t_in, const Real dt_in,
    const Vector<MultiFab>& a, const Vector<MultiFab>& b,
    const Vector<MultiFab>& c, const Vector<MultiFab>& d,
    const Vector<MultiFab>& u_in, Vector<MultiFab>& e, const BaseState<Real>& f,
    const BaseState<Real>& g, const Vector<MultiFab>& h) {
    // timer for profiling
    BL_PROFILE_VAR("Maestro::PlotFileMF()", PlotFileMF);

    // MultiFab to hold plotfile data
    Vector<const MultiFab*> plot_mf;

    // temporary MultiFab to hold plotfile data
    Vector<MultiFab*> plot_mf_data(finest_level + 1);

    int dest_comp = 0;

    // build temporary MultiFab to hold plotfile data
    for (int i = 0; i <= finest_level; ++i) {
        plot_mf_data[i] =
            new MultiFab((u_in[i]).boxArray(), (u_in[i]).DistributionMap(),
                         AMREX_SPACEDIM, 0);
    }

    // velocity
    for (int i = 0; i <= finest_level; ++i) {
        plot_mf_data[i]->copy((u_in[i]), 0, dest_comp, AMREX_SPACEDIM);
    }
    dest_comp += AMREX_SPACEDIM;

    // add plot_mf_data[i] to plot_mf
    for (int i = 0; i <= finest_level; ++i) {
        plot_mf.push_back(plot_mf_data[i]);
        // delete [] plot_mf_data[i];
    }

    return plot_mf;
}