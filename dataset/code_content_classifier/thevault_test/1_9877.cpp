const ColorControlPointList *
ColorTableAttributes::GetColorControlPoints(int index) const
{
    if(index >= 0 && index < static_cast<int>(colorTables.size()))
        return ((ColorControlPointList *)colorTables[index]);
    else
        return 0;
}