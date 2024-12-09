Monster* Battle::FindMonster(unsigned int heroLvl) 
{
    short monChance = rand() % 3;
    Monster* newMon = NULL;

    switch(monChance)
    {
        case 0:
            newMon = new Exoskeleton("Exoskeleton",/*increased defence*/
                                     Monster::MonsterGetBaseHP() + heroLvl * 4 , heroLvl,
                                     Monster::MonsterGetBaseDamage() + heroLvl,
                                     Monster::MonsterGetBaseDamage() + heroLvl * 2,
                                     Monster::MonsterGetBaseDefence() + heroLvl * 3,
                                     Monster::MonsterGetBaseAvoidance() + heroLvl * 0.001);
            break;
        case 1:
            newMon = new Spirit("Spirit",/*increased avoidance*/
                                Monster::MonsterGetBaseHP() + heroLvl * 4 , heroLvl,
                                Monster::MonsterGetBaseDamage() + heroLvl,
                                Monster::MonsterGetBaseDamage() + heroLvl * 2,
                                Monster::MonsterGetBaseDefence() + heroLvl * 2,
                                Monster::MonsterGetBaseAvoidance() + heroLvl * 0.0015);
            break;
        case 2:
            newMon = new Dragon("Dragon",/*increased damage*/
                                Monster::MonsterGetBaseHP() + heroLvl * 4 , heroLvl,
                                Monster::MonsterGetBaseDamage() + heroLvl,
                                Monster::MonsterGetBaseDamage() + heroLvl * 2,
                                Monster::MonsterGetBaseDefence() + heroLvl * 2,
                                Monster::MonsterGetBaseAvoidance() + heroLvl * 0.001);
            break;
    }
    return newMon;
}