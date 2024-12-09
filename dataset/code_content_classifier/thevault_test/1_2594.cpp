int PrimeSearch16::next()
{
    if (query == range)
    {
        return -1;
    }

    int next = pos;

    while (true)
    {
        next += skip;
        next %= prime;

        if (next < range)
        {
            pos = next;
            break;
        }
        else
        {
            // This overhead is the tradeoff from the "skip randomness".
            // It will be entered X times during the set iteration, where X is the difference between the chosen prime and the set size.
        }
    }

    query++;
    return pos;
}