void ElectricFieldReaderModule::check_detector_match(std::array<double, 3> dimensions,
                                                     std::pair<double, double> thickness_domain,
                                                     std::array<double, 2> field_scale) {
    auto xpixsz = dimensions[0];
    auto ypixsz = dimensions[1];
    auto thickness = dimensions[2];

    auto model = detector_->getModel();
    // Do a several checks with the detector model
    if(model != nullptr) {
        // Check field dimension in z versus the requested thickness domain:
        auto eff_thickness = thickness_domain.second - thickness_domain.first;
        if(std::fabs(thickness - eff_thickness) > std::numeric_limits<double>::epsilon()) {
            LOG(WARNING) << "Thickness of electric field is " << Units::display(thickness, "um")
                         << " but the depleted region is " << Units::display(eff_thickness, "um");
        }

        // Check the field extent along the pixel pitch in x and y:
        if(std::fabs(xpixsz - field_scale[0]) > std::numeric_limits<double>::epsilon() ||
           std::fabs(ypixsz - field_scale[1]) > std::numeric_limits<double>::epsilon()) {
            LOG(WARNING) << "Electric field size is (" << Units::display(xpixsz, {"um", "mm"}) << ","
                         << Units::display(ypixsz, {"um", "mm"})
                         << ") but current configuration results in an field area of ("
                         << Units::display(field_scale[0], {"um", "mm"}) << ","
                         << Units::display(field_scale[1], {"um", "mm"}) << ")" << std::endl
                         << "The size of the area to which the electric field is applied can be changes using the "
                            "field_scale parameter.";
        }
    }
}