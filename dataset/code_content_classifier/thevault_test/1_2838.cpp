void FoundObject::CalculateValues()
{
    float x = 0, y = 0, z = 0;
    float ly, lx, hy, hx, maxsize = 0;
    int numPoints = objectCloud.size();
    for (int i = 0; i < numPoints; i++)
    {
        x += objectCloud.points[i].x;
        y += objectCloud.points[i].y;
        z += objectCloud.points[i].z;
    }

    float cx, cy, cz, cx2, cy2, cz2;
    cx = x / numPoints;
    cy = y / numPoints;
    cz = z / numPoints;
    location.x = cx;
    location.y = cy;
    location.z = cz;

    centerMass = std::tuple<float, float, float>{cx, cy, cz};

    for (int i = 0; i < numPoints; i++)
    {
        //Can possibly result in inaccuracies, use location instead of objectCloud.points[0] for the right values
        float tempsize = euclideanDistance(objectCloud.points[i], objectCloud.points[0]);
        tempsize = abs(tempsize);
        if (tempsize > maxsize)
        {
            maxsize = tempsize;
        }
    }
    size = maxsize;
}