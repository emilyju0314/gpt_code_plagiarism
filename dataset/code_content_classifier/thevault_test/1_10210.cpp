bool ParameterisedG4::CheckOverlaps(int res, double tol, bool verbose, int max_err) {
    if(check_overlaps_) {
        G4PVParameterised::CheckOverlaps(res, tol, verbose, max_err);
    }
    return false;
}