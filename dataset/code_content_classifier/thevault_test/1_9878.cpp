const ColorControlPointList *
ColorTableAttributes::GetColorControlPoints(const vtkstd::string &name) const
{
    int index = GetColorTableIndex(name);

    if(index >= 0 && index < static_cast<int>(colorTables.size()))
        return ((ColorControlPointList *)colorTables[index]);
    else
        return 0;
}