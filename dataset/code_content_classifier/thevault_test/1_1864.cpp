void Search::addAssignmentToPattern(size_t var, size_t val, bool sens, bool skip)
{
    double maxParams[2] = {
        NB.leafParams[var][maxInstances[var]],
        NB.leafParams[var][maxInstances[var] + 2]};
    double minParams[2] = {
        NB.leafParams[var][(1 - maxInstances[var])],
        NB.leafParams[var][(1 - maxInstances[var]) + 2]};

    if (skip)
    {
        // Do nothing to curPattern
        // Remove var from extensions
        allExtension.pDMax /= maxParams[targetValue];
        allExtension.pNotDMax /= maxParams[1 - targetValue];
        allExtension.pDMin /= minParams[targetValue];
        allExtension.pNotDMin /= minParams[1 - targetValue];

        baseExtension.pDMax /= maxParams[targetValue];
        baseExtension.pNotDMax /= maxParams[1 - targetValue];
        baseExtension.pDMin /= minParams[targetValue];
        baseExtension.pNotDMin /= minParams[1 - targetValue];

        baseOnlyExtension.pDMax /= maxParams[targetValue];
        baseOnlyExtension.pNotDMax /= maxParams[1 - targetValue];
        baseOnlyExtension.pDMin /= minParams[targetValue];
        baseOnlyExtension.pNotDMin /= minParams[1 - targetValue];

        if (isSensitive[var])
        {
            sensOnlyExtension.pDMax /= maxParams[targetValue];
            sensOnlyExtension.pNotDMax /= maxParams[1 - targetValue];
            sensOnlyExtension.pDMin /= minParams[targetValue];
            sensOnlyExtension.pNotDMin /= minParams[1 - targetValue];
        }
        return;
    }

    double *toAdd = (val == maxInstances[var]) ? maxParams : minParams;
    double *toRemove = (val == maxInstances[var]) ? minParams : maxParams;

    curPattern.pDXY *= toAdd[targetValue];
    curPattern.pNotDXY *= toAdd[1 - targetValue];

    pair<size_t, size_t> assignment = make_pair(var, val);
    if (sens)
    {
        curPattern.sens.push_back(assignment);
    }
    else
    {
        curPattern.base.push_back(assignment);
        curPattern.pDY *= toAdd[targetValue];
        curPattern.pNotDY *= toAdd[1 - targetValue];
    }

    double dRatio = toAdd[targetValue] / toRemove[targetValue];
    double notDRatio = toAdd[1 - targetValue] / toRemove[1 - targetValue];
    if (val != maxInstances[var])
    {
        allExtension.pDMax *= dRatio;
        allExtension.pNotDMax *= notDRatio;
        if (sens)
        {
            sensOnlyExtension.pDMax *= dRatio;
            sensOnlyExtension.pNotDMax *= notDRatio;
        }
        else
        {
            baseExtension.pDMax *= dRatio;
            baseExtension.pNotDMax *= notDRatio;
            baseOnlyExtension.pDMax *= dRatio;
            baseOnlyExtension.pNotDMax *= notDRatio;
        }
    }
    else
    {
        allExtension.pDMin *= dRatio;
        allExtension.pNotDMin *= notDRatio;
        if (sens)
        {
            sensOnlyExtension.pDMin *= dRatio;
            sensOnlyExtension.pNotDMin *= notDRatio;
        }
        else
        {
            baseExtension.pDMin *= dRatio;
            baseExtension.pNotDMin *= notDRatio;
            baseOnlyExtension.pDMin *= dRatio;
            baseOnlyExtension.pNotDMin *= notDRatio;
        }
    }

    if (sens)
    {
        baseOnlyExtension.pDMax /= maxParams[targetValue];
        baseOnlyExtension.pNotDMax /= maxParams[1 - targetValue];
        baseOnlyExtension.pDMin /= minParams[targetValue];
        baseOnlyExtension.pNotDMin /= minParams[1 - targetValue];
    }
    else if (isSensitive[var])
    {
        sensOnlyExtension.pDMax /= maxParams[targetValue];
        sensOnlyExtension.pNotDMax /= maxParams[1 - targetValue];
        sensOnlyExtension.pDMin /= minParams[targetValue];
        sensOnlyExtension.pNotDMin /= minParams[1 - targetValue];
    }
}