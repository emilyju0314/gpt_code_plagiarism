void ParagraphImpl::markLineBreaks() {

    // Find all possible (soft) line breaks
    TextBreaker breaker;
    if (!breaker.initialize(fTextSpan, UBRK_LINE)) {
        return;
    }

    Cluster* current = fClusters.begin();
    while (!breaker.eof() && current < fClusters.end()) {
        size_t currentPos = breaker.next();
        while (current < fClusters.end()) {
            if (current->textRange().end > currentPos) {
                break;
            } else if (current->textRange().end == currentPos) {
                current->setBreakType(breaker.status() == UBRK_LINE_HARD
                                      ? Cluster::BreakType::HardLineBreak
                                      : Cluster::BreakType::SoftLineBreak);
                ++current;
                break;
            }
            ++current;
        }
    }

    // Walk through all the clusters in the direction of input text
    Block* currentStyle = this->fTextStyles.begin();
    SkScalar shift = 0;
    for (auto& cluster : fClusters) {
        auto run = cluster.run();

        // Shift the cluster
        run->shift(&cluster, shift);

        // Synchronize styles (one cluster can be covered by few styles)
        while (!cluster.startsIn(currentStyle->fRange)) {
            currentStyle++;
            SkASSERT(currentStyle != this->fTextStyles.end());
        }

        // Take spacing styles in account
        if (currentStyle->fStyle.getWordSpacing() != 0 &&
            fParagraphStyle.getTextAlign() != TextAlign::kJustify) {
            if (cluster.isWhitespaces() && cluster.isSoftBreak()) {
                shift += run->addSpacesAtTheEnd(currentStyle->fStyle.getWordSpacing(), &cluster);
            }
        }
        if (currentStyle->fStyle.getLetterSpacing() != 0) {
            shift += run->addSpacesEvenly(currentStyle->fStyle.getLetterSpacing(), &cluster);
        }
    }

    fClusters.emplace_back(this, EMPTY_RUN, 0, 0, SkSpan<const char>(), 0, 0);
}