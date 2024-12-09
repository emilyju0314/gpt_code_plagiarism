void Search::recurse(size_t level)
{
    if (level >= numLeaves
        || (stopAfterK && patterns.top().kld != (useKLD ? 0 : threshold)))
        return;
    numVisits++;

    // If sensitive attribute, add to sens and recurse
    if (isSensitive[level])
    {
        // Compute Pr(d | y)
        for (size_t val = 0; val <= 1; val++)
        {
            addAssignmentToPattern(level, val, true);

            curPattern.kld = useKLD ? computeDivergence2() : computeDifference();
            if (leq(patterns.top().kld, curPattern.kld))
            {
                patterns.pop();
                patterns.push(curPattern);
            }
            if (level + 1 < numLeaves)
            {
                double bound = useKLD ? computeDivergenceBound2() : computeDifferenceBound();
                // cout << "Divergence: " << curPattern.kld << "; Bound: " << bound << endl;

                if (bound > patterns.top().kld)
                {
                    recurse(level + 1);
                }
            }

            removeAssignmentFromPattern(level, val, true);
        }
    }

    // Add to base and recurse
    for (size_t val = 0; val <= 1; val++)
    {
        addAssignmentToPattern(level, val, false);

        curPattern.kld = useKLD ? computeDivergence2() : computeDifference();
        if (leq(patterns.top().kld, curPattern.kld))
        {
            patterns.pop();
            patterns.push(curPattern);
        }

        if (level + 1 < numLeaves)
        {
            double bound = useKLD ? computeDivergenceBound2() : computeDifferenceBound();
            // cout << "Divergence: " << curPattern.kld << "; Bound: " << bound << endl;

            if (bound > patterns.top().kld)
            {
                recurse(level + 1);
            }
        }

        removeAssignmentFromPattern(level, val, false);
    }

    // Skip and recurse
    addAssignmentToPattern(level, -1, false, true);
    recurse(level + 1);
    removeAssignmentFromPattern(level, -1, false, true);
}