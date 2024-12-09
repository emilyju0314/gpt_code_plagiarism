void Imc::Initialize()
{
    // do some output
    if(_do_imc)
	    cout << "begin to calculate inverse monte carlo parameters\n";
    else
	    cout << "begin to calculate distribution functions\n";
    cout << "# of bonded interactions: " << _bonded.size() << endl;
    cout << "# of non-bonded interactions: " << _nonbonded.size() << endl;

    if ( _bonded.size()+_nonbonded.size() == 0 )
            throw std::runtime_error("No interactions defined in options xml-file - nothing to be done");

    
   // initialize non-bonded structures
   for (list<Property*>::iterator iter = _nonbonded.begin();
            iter != _nonbonded.end(); ++iter) {
        interaction_t *i = AddInteraction(*iter);
        i->_is_bonded = false;
    }

    // initialize non-bonded structures
   for (list<Property*>::iterator iter = _bonded.begin();
        iter != _bonded.end(); ++iter) {
            interaction_t *i = AddInteraction(*iter);
            i->_is_bonded = true;
   }
   
   // initialize the group structures
    if(_do_imc)
        InitializeGroups();
}