void Population::reassign_species(Organism *org) {

    Organism *comporg;
    bool found=false;  //Note we don't really need this flag but it
    //might be useful if we change how this function works
    std::vector<Species*>::iterator curspecies;
    Species *newspecies;
    Species *orig_species;

    curspecies=(species).begin();

    comporg=(*curspecies)->first();
    while((curspecies!=(species).end()) && (!found))
    {
        if (comporg==0) {
            //Keep searching for a matching species
            ++curspecies;
            if (curspecies!=(species).end())
                comporg=(*curspecies)->first();
        }
        else if (((org->gnome)->compatibility(comporg->gnome))<NEAT::compat_threshold) {
            //If we found the same species it's already in, return 0
            if ((*curspecies)==org->species) {
                found=true;
                break;
            }
            //Found compatible species
            else {
                switch_species(org,org->species,(*curspecies));
                found=true;  //Note the search is over
            }
        }
        else {
            //Keep searching for a matching species
            ++curspecies;
            if (curspecies!=(species).end())
                comporg=(*curspecies)->first();
        }
    }

    //If we didn't find a match, create a new species, move the org to
    // that species, check if the old species is empty,
    //re-estimate averages, and return 0
    if (found==false) {

        //Create a new species for the org
        newspecies=new Species(++(last_species),true);
        (species).push_back(newspecies);

        switch_species(org,org->species,newspecies);
    }

}