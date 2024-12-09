void WeightingPotentialReaderModule::check_detector_match(std::array<double, 3> dimensions,
                                                          std::pair<double, double> thickness_domain) {
    auto xpixsz = dimensions[0];
    auto ypixsz = dimensions[1];
    auto thickness = dimensions[2];

    auto model = detector_->getModel();
    // Do a several checks with the detector model
    if(model != nullptr) {
        // Check field dimension in z versus the requested thickness domain:
        auto eff_thickness = thickness_domain.second - thickness_domain.first;
        if(std::fabs(thickness - eff_thickness) > std::numeric_limits<double>::epsilon()) {
            LOG(WARNING) << "Thickness of weighting potential is " << Units::display(thickness, "um")
                         << " but the depleted region is " << Units::display(eff_thickness, "um");
        }

        // Check that the total field size is n*pitch:
        if(std::fmod(xpixsz, model->getPixelSize().x()) > std::numeric_limits<double>::epsilon() ||
           std::fmod(ypixsz, model->getPixelSize().y()) > std::numeric_limits<double>::epsilon()) {
            LOG(WARNING) << "Potential map size is (" << Units::display(xpixsz, {"um", "mm"}) << ","
                         << Units::display(ypixsz, {"um", "mm"}) << ") but expecting a multiple of the pixel pitch ("
                         << Units::display(model->getPixelSize().x(), {"um", "mm"}) << ", "
                         << Units::display(model->getPixelSize().y(), {"um", "mm"}) << ")";
        } else {
            LOG(INFO) << "Potential map size is (" << Units::display(xpixsz, {"um", "mm"}) << ","
                      << Units::display(ypixsz, {"um", "mm"}) << "), matching detector model with pixel pitch ("
                      << Units::display(model->getPixelSize().x(), {"um", "mm"}) << ", "
                      << Units::display(model->getPixelSize().y(), {"um", "mm"}) << ")";
        }
    }
}