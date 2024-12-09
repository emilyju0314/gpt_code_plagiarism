void store_geometry(TFile*                       root_file,
                    const G4ProductionCutsTable& g4production_cuts,
                    const G4VPhysicalVolume&     world_volume)
{
    REQUIRE(root_file);

    cout << "Exporting material and volume information..." << endl;

    TTree tree_materials("geometry", "geometry");

    // Create geometry map and ROOT branch
    GdmlGeometryMap geometry;
    tree_materials.Branch("GdmlGeometryMap", &geometry);

    // Loop over materials and elements
    for (auto i : celeritas::range(g4production_cuts.GetTableSize()))
    {
        // Fetch material and element list
        const auto& g4material_cuts
            = g4production_cuts.GetMaterialCutsCouple(i);
        const auto& g4material = g4material_cuts->GetMaterial();
        const auto& g4elements = g4material->GetElementVector();

        CHECK(g4material_cuts);
        CHECK(g4material);
        CHECK(g4elements);

        // Populate material information
        ImportMaterial material;
        material.name             = g4material->GetName();
        material.state            = to_material_state(g4material->GetState());
        material.temperature      = g4material->GetTemperature(); // [K]
        material.density          = g4material->GetDensity() / (g / cm3);
        material.electron_density = g4material->GetTotNbOfElectPerVolume()
                                    / (1. / cm3);
        material.atomic_density = g4material->GetTotNbOfAtomsPerVolume()
                                  / (1. / cm3);
        material.radiation_length   = g4material->GetRadlen() / cm;
        material.nuclear_int_length = g4material->GetNuclearInterLength() / cm;

        // Populate element information
        for (auto j : celeritas::range(g4elements->size()))
        {
            const auto& g4element = g4elements->at(j);
            CHECK(g4element);

            ImportElement element;
            element.name                  = g4element->GetName();
            element.atomic_number         = g4element->GetZ();
            element.atomic_mass           = g4element->GetAtomicMassAmu();
            element.radiation_length_tsai = g4element->GetfRadTsai()
                                            / (g / cm2);
            element.coulomb_factor = g4element->GetfCoulomb();

            elem_id   elid = g4element->GetIndex();
            real_type frac = g4material->GetFractionVector()[j];

            // Add element to the global element map
            geometry.add_element(elid, element);

            // Add global element to the map of elements of a given material
            material.elements_fractions.insert({elid, frac});
        }
        // Add material to the global material map
        geometry.add_material(g4material_cuts->GetIndex(), material);
    }

    // Recursive loop over all logical volumes, starting from the world_volume
    // Populate volume information and map volumes with materials
    loop_volumes(geometry, *world_volume.GetLogicalVolume());

    tree_materials.Fill();
    root_file->Write();
}