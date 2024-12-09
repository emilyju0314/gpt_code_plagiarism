void ParagraphImpl::buildClusterTable() {

    // Walk through all the run in the direction of input text
    for (RunIndex runIndex = 0; runIndex < fRuns.size(); ++runIndex) {
        auto& run = fRuns[runIndex];
        auto runStart = fClusters.size();
        fClusters.reserve(fClusters.size() + fRuns.size());
        // Walk through the glyph in the direction of input text
        run.iterateThroughClustersInTextOrder([runIndex, this](
                                                      size_t glyphStart,
                                                      size_t glyphEnd,
                                                      size_t charStart,
                                                      size_t charEnd,
                                                      SkScalar width,
                                                      SkScalar height) {
            SkASSERT(charEnd >= charStart);
            SkSpan<const char> text(fTextSpan.begin() + charStart, charEnd - charStart);

            auto& cluster = fClusters.emplace_back(this, runIndex, glyphStart, glyphEnd, text, width, height);
            cluster.setIsWhiteSpaces();
        });

        run.setClusterRange(runStart, fClusters.size());
        fMaxIntrinsicWidth += run.advance().fX;
    }
}