void noveltyarchive::evaluate_population(Population* p1,vector<Organism*> p2,bool fitness)
{
    vector<Organism*>::iterator it;
    for(it=p1->organisms.begin(); it<p1->organisms.end(); it++)
        evaluate_individual((*it),p2,fitness);
}