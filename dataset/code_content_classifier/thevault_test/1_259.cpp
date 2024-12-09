void sort_boundary_fragments(List<Boundary_Fragment>& fragments) {
    struct Compare_Boundary_Fragments {
        Bool operator()(const Boundary_Fragment& a, const Boundary_Fragment& b) {
            if(a.y() != b.y()) { return a.y() < b.y(); }
            else               { return a.x() < b.x(); }
        }
    };
    std::sort(fragments.begin(), fragments.end(), Compare_Boundary_Fragments());
}