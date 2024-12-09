int CPLabelDrawing (XPLMDrawingPhase     /*inPhase*/,
                    int                  /*inIsBefore*/,
                    void *               /*inRefcon*/)
{
    UPDATE_CYCLE_NUM;               // DEBUG only: Store current cycle number in glob.xpCycleNum
    TwoDDrawLabels();
    return 1;
}