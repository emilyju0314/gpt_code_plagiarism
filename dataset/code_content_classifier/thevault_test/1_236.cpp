void print_decay_properties(std::shared_ptr<XS4GCR::CosmicRayChart> decays, XS4GCR::PID particle) {
    if (decays->get_halftime(particle) > 0) {
        auto mode = decays->get_mode(particle);
        auto tau_kyr = decays->get_halftime(particle) / cgs::kyr;
        std::cout << particle << " decays in " << tau_kyr << " kyr";
        std::cout << " with mode " << decays->get_mode(particle) << "\n";
    } else {
        std::cout << particle << " is stable.\n";
    }
}