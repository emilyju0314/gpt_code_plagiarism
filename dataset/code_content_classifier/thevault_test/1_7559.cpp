Population::Population(std::vector<Genome*> genomeList, float power) {

    winnergen=0;
    highest_fitness=0.0;
    highest_last_changed=0;

    int count;
    Genome *new_genome;
    Organism *new_organism;

    //Create size copies of the Genome
    //Start with perturbed linkweights
    for (std::vector<Genome*>::iterator iter = genomeList.begin(); iter != genomeList.end(); ++iter)
    {

        new_genome=(*iter);
        if(power>0)
            new_genome->mutate_link_weights(power,1.0,GAUSSIAN);
        //new_genome->mutate_link_weights(1.0,1.0,COLDGAUSSIAN);
        new_genome->randomize_traits();
        new_organism=new Organism(0.0,new_genome,1);
        organisms.push_back(new_organism);
    }

    //Keep a record of the innovation and node number we are on
    cur_node_id=new_genome->get_last_node_id();
    cur_innov_num=new_genome->get_last_gene_innovnum();

    set_compatibility(&NEAT::genotypic_compatibility);
    //Separate the new Population into species
    speciate();
}