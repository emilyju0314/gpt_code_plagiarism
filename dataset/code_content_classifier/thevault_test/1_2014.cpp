float myrand(void)
{
    static int seed = 72191;
    char sq[22];

    if (g_bQAReadback) {
        seed *= seed;
        sprintf(sq, "%010d", seed);
        // pull the middle 5 digits out of sq
        sq[8] = 0;
        seed = atoi(&sq[3]);

        return seed/99999.f;
    } else {
        return rand()/(float)RAND_MAX;
    }
}