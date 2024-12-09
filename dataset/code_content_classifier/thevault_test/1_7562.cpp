void Population::switch_species(Organism *org, Species *orig_species, Species *new_species) {

    //Remove organism from the species we want to remove it from
    orig_species->remove_org(org);

    //Add the organism to the new species it is being moved to
    new_species->add_Organism(org);
    org->species=new_species;

    //KEN: Delete orig_species if empty, and remove it from pop
    if ((orig_species->organisms.size())==0) {

        remove_species(orig_species);
        delete orig_species;

        //Re-estimate the average of the species that now has a new member
        new_species->estimate_average();
    }
    //If not, re-estimate the species average after removing the organism
    // AND the new species with the new member
    else {
        orig_species->estimate_average();
        new_species->estimate_average();
    }
}