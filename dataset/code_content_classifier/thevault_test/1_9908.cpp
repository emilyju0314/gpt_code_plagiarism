void
VolumeAttributes::SetDefaultColorControlPoints()
{
    const float positions[] = {0., 0.25, 0.5, 0.75, 1.};
    const unsigned char colors[5][4] = {
        {0,   0,   255, 255},
        {0,   255, 255, 255},
        {0,   255, 0,   255},
        {255, 255, 0,   255},
        {255, 0,   0,   255}};

    // Clear the color control point list.
    colorControlPoints.ClearControlPoints();

    // Set the default control points in the color control point list.
    for(int i = 0; i < 5; ++i)
    {
        ColorControlPoint cpt;
        cpt.SetPosition(positions[i]);
        cpt.SetColors(colors[i]);
        colorControlPoints.AddControlPoints(cpt);
    }
    SelectColorControlPoints();
}