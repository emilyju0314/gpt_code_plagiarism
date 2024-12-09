void
ColorTableAttributes::AddColorTable(const vtkstd::string &name,
    const ColorControlPointList &cpts)
{
    // Remove the color table if it already exists in the list.
    int index = GetColorTableIndex(name);
    if(index != -1)
        RemoveColorTable(index);

    // Append the color table to the list.
    names.push_back(name);
    AddColorTables(cpts);

    // Store the name, colortable pairs into a map.
    vtkstd::map<vtkstd::string, AttributeGroup *> sortMap;
    unsigned int i;
    for(i = 0; i < names.size(); ++i)
        sortMap[names[i]] = colorTables[i];

    // Traverse the map, it will be sorted. Store the names and color table
    // pointer back into the old vectors.
    vtkstd::map<vtkstd::string, AttributeGroup *>::iterator pos;
    for(i = 0, pos = sortMap.begin(); pos != sortMap.end(); ++pos, ++i)
    {
        names[i] = pos->first;
        colorTables[i] = pos->second;
    }

    Select(0, (void *)&names);
}