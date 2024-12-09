void store_physics_tables(TFile* root_file, G4ParticleTable* particle_table)
{
    REQUIRE(root_file);
    REQUIRE(particle_table);

    // Start table writer
    GeantPhysicsTableWriter table_writer(root_file);

    cout << "Exporting physics tables..." << endl;

    G4ParticleTable::G4PTblDicIterator& particle_iterator
        = *(G4ParticleTable::GetParticleTable()->GetIterator());
    particle_iterator.reset();

    while (particle_iterator())
    {
        const G4ParticleDefinition& g4_particle_def
            = *(particle_iterator.value());

        // Skip "dummy" particles: generic ion and geantino
        if (g4_particle_def.GetPDGEncoding() == 0)
            continue;

        std::cout << "=============" << std::endl;
        std::cout << g4_particle_def.GetParticleName() << std::endl;
        std::cout << "=============" << std::endl;

        const G4ProcessVector& process_list
            = *(g4_particle_def.GetProcessManager()->GetProcessList());

        for (auto j : celeritas::range(process_list.size()))
        {
            const G4VProcess& process = *(process_list)[j];
            table_writer.add_physics_tables(process, g4_particle_def);
        }
    }
    cout << endl;

    root_file->Write();
}