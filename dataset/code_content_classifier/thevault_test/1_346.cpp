void Topology::CreateMoleculesByRange(string name, int first, int nbeads, int nmolecules)
{
    Molecule *mol = CreateMolecule(name);
    int beadcount=0;
    int res_offset=0;
   
    BeadContainer::iterator bead;
    for(bead=_beads.begin(); bead!=_beads.end(); ++bead) {
        //xml numbering starts with 1
        if(--first > 0) continue;
	//This is not 100% correct, but let's assume for now that the resnr do increase
	if ( beadcount == 0 ) {
	    res_offset = (*bead)->getResnr();
	}
        stringstream bname;
	bname << (*bead)->getResnr() - res_offset + 1 << ":" << getResidue((*bead)->getResnr())->getName() << ":" << (*bead)->getName();
        mol->AddBead((*bead), bname.str());
        if(++beadcount == nbeads) {
            if(--nmolecules <= 0) break;
            mol = CreateMolecule(name);            
            beadcount = 0;
        }
    }
}