Array<Cut, max_cut_count> find_monotone_segments(const Generic_Bezier& curve) {
    auto cuts = Array<Cut, max_cut_count>();

    for(auto axis : Range<Uint32>(2)) {
        auto cuts_begin = axis*max_cuts_per_axis;

        auto& cut_0 = cuts[cuts_begin + 0];
        auto& cut_1 = cuts[cuts_begin + 1];
        // Initialize cuts to make sorting work.
        cut_0.t    = cut_1.t    = 1.f;
        cut_0.axis = cut_1.axis = axis;

        find_derivative_roots(curve, axis, cut_0.t, cut_1.t);
    }

    // Sort cuts by t. (We have to sort the entire array. Eg: [1, 1, 0.5, 0.75])
    insertion_sort(make_slice(cuts), [](const auto& a, const auto& b) { return a.t <= b.t; });

    return cuts;
}