FieldFunction<double>
WeightingPotentialReaderModule::get_pad_potential_function(const ROOT::Math::XYVector& implant,
                                                           std::pair<double, double> thickness_domain) {

    LOG(TRACE) << "Calculating function for the plane condenser weighting potential." << std::endl;

    return [implant, thickness_domain](const ROOT::Math::XYZPoint& pos) {
        // Calculate values of the "f" function
        auto f = [implant](double x, double y, double u) {
            // Calculate arctan fractions
            auto arctan = [](double a, double b, double c) {
                return std::atan(a * b / c / std::sqrt(a * a + b * b + c * c));
            };

            // Shift the x and y coordinates by plus/minus half the implant size:
            double x1 = x - implant.x() / 2;
            double x2 = x + implant.x() / 2;
            double y1 = y - implant.y() / 2;
            double y2 = y + implant.y() / 2;

            // Calculate arctan sum and return
            return arctan(x1, y1, u) + arctan(x2, y2, u) - arctan(x1, y2, u) - arctan(x2, y1, u);
        };

        // Transform into coordinate system with sensor between d/2 < z < -d/2:
        auto d = thickness_domain.second - thickness_domain.first;
        auto local_z = -pos.z() + thickness_domain.second;

        // Calculate the series expansion
        double sum = 0;
        for(int n = 1; n <= 100; n++) {
            sum += f(pos.x(), pos.y(), 2 * n * d - local_z) - f(pos.x(), pos.y(), 2 * n * d + local_z);
        }

        return (1 / (2 * M_PI) * (f(pos.x(), pos.y(), local_z) - sum));
    };
}