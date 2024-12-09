SkRange<size_t> ParagraphImpl::getWordBoundary(unsigned offset) {
    TextBreaker breaker;
    if (!breaker.initialize(fTextSpan, UBRK_WORD)) {
        return {0, 0};
    }

    size_t currentPos = breaker.first();
    while (true) {
        auto start = currentPos;
        currentPos = breaker.next();
        if (breaker.eof()) {
            break;
        }
        if (start <= offset && currentPos > offset) {
            return {start, currentPos};
        }
    }
    return {0, 0};
}