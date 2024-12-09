TopologyMap *CGEngine::CreateCGTopology(Topology &in, Topology &out)
{
    MoleculeContainer &mols = in.Molecules();
    MoleculeContainer::iterator iter;
    TopologyMap *m = new TopologyMap(&in, &out);
    for(iter=mols.begin(); iter!=mols.end(); ++iter) {
        Molecule *mol = *iter;
        if(IsIgnored(mol->getName())) continue;
        CGMoleculeDef *def = getMoleculeDef(mol->getName());
        if(!def) {
            cout << "--------------------------------------\n"
                 << "WARNING: unknown molecule \"" << mol->getName() << "\" with id "
                 << mol->getId() << " in topology" << endl
                 << "molecule will not be mapped to CG representation\n"
                 << "Check weather a mapping file for all molecule exists, was specified in --cg "
                 << "separated by ; and the ident tag in xml-file matches the molecule name\n"
                 << "--------------------------------------\n";
            continue;
        }
        Molecule *mcg = def->CreateMolecule(out);
        Map *map = def->CreateMap(*mol, *mcg);
        m->AddMoleculeMap(map);
    }
    out.RebuildExclusions();    
    return m;
}