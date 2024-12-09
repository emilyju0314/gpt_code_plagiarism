bool Battle::BattleHappens(void) 
{
    float chanceToFight = 0.05;
    float determ = (double)rand() / RAND_MAX;

    if (chanceToFight > determ)
        return true;
    else
        return false;
}