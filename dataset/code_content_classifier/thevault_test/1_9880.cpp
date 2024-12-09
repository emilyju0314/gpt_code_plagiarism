void
ColorTableAttributes::RemoveColorTable(int index)
{
    if(index >= 0 && index < static_cast<int>(names.size()))
    {
        // Determine if the color table is active.
        bool isActiveContinuous, isActiveDiscrete;
        isActiveContinuous = (names[index] == activeContinuous);
        isActiveDiscrete = (names[index] == activeDiscrete);

        // Iterate through the vector "index" times. 
        stringVector::iterator pos = names.begin();
        for(int i = 0; i < index; ++i)
            ++pos;

        // If pos is still a valid iterator, remove that element.
        if(pos != names.end())
        {
            names.erase(pos);
        }

        // Indicate that things have changed by selecting the list.
        Select(0, (void *)&names);

        // erase the color table from the vector.
        RemoveColorTables(index);

        // If it is the active color table that was removed, reset the
        // active color table to the first element.
        if(isActiveContinuous)
        {
            if(names.size() > 0)
                SetActiveContinuous(names[0]);
            else
                SetActiveContinuous(vtkstd::string(""));
        }
        if(isActiveDiscrete)
        {
            if(names.size() > 0)
                SetActiveDiscrete(names[0]);
            else
                SetActiveDiscrete(vtkstd::string(""));
        }
    }
}