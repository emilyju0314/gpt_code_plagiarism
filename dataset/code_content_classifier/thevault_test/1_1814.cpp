bool Battle::CastSpell(Hero& hero, Monster& monster) 
{
    unsigned int totalDamage;
    unsigned int slotNumber;
    unsigned int typeOfSpell;
    Spell* chosenSpell;

    if (hero.DisplaySpells(chosenSpell , slotNumber , typeOfSpell) == false)
        return false;

    // Checks if the hero has enough magic power
    if (hero.UseSpell(*chosenSpell) == true) { 
        hero.ReduceMagicPower(chosenSpell->GetReqEnergy()); // Reduces the hero's magic power
        totalDamage = chosenSpell->HeroDamage(hero);        // Gets the total damage that will be caused
        monster.ChangeHealth(floor((double)(totalDamage * totalDamage) / (totalDamage + monster.MonsterGetDefence())));
        monster.HitBySpell(chosenSpell);                    // Applies the after attack effects of the spell
        hero.SpellUsed(slotNumber , typeOfSpell);           // Deletes the spell
        
        if (monster.Fainted()) {
            cout << "The hero " << hero.GetName() << " defeated the monster " << monster.GetName() << endl;
            return true;
        }
    }
    return true;
}