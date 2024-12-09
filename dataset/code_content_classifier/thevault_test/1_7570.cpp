void noveltyarchive::evaluate_population(vector<Organism*> orgs, bool fitness)
{
    vector<Organism*>::iterator it;
    for(it=orgs.begin(); it!=orgs.end(); it++)
        evaluate_individual((*it),orgs,fitness);
}