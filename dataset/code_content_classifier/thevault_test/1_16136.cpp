std::vector<TextBox> ParagraphImpl::getRectsForRange(unsigned start,
                                                     unsigned end,
                                                     RectHeightStyle rectHeightStyle,
                                                     RectWidthStyle rectWidthStyle) {
    std::vector<TextBox> results;
    if (start >= end || start > fTextSpan.size() || end == 0) {
        return results;
    }

    // Calculate the utf8 substring
    const char* first = fTextSpan.begin();
    for (unsigned i = 0; i < start; ++i) {
        utf8_next(&first, fTextSpan.end());
    }
    const char* last = first;
    for (unsigned i = start; i < end; ++i) {
        utf8_next(&last, fTextSpan.end());
    }
    TextRange text(first - fTextSpan.begin(), last  - fTextSpan.begin());

    for (auto& line : fLines) {
        auto lineText = line.textWithSpaces();
        auto intersect = lineText * text;
        if (intersect.empty() && (!lineText.empty() || lineText.start != text.start)) {
            continue;
        }

        SkScalar runOffset = 0;
        if (lineText.start != intersect.start) {
            TextRange before(lineText.start, intersect.start);
            runOffset = line.iterateThroughRuns(
                    before, 0, true,
                    [](Run*, size_t, size_t, SkRect, SkScalar, bool) { return true; });
        }
        auto firstBox = results.size();
        line.iterateThroughRuns(intersect,
                                runOffset,
                                true,
                                [&results, &line](Run* run, size_t pos, size_t size, SkRect clip,
                                                  SkScalar shift, bool clippingNeeded) {
                                    clip.offset(line.offset());
                                    results.emplace_back(clip, run->leftToRight()
                                                                       ? TextDirection::kLtr
                                                                       : TextDirection::kRtl);
                                    return true;
                                });

        if (rectHeightStyle != RectHeightStyle::kTight) {
            // Align all the rectangles
            for (auto i = firstBox; i < results.size(); ++i) {
                auto& rect = results[i].rect;
                if (rectHeightStyle == RectHeightStyle::kMax) {
                    rect.fTop = line.offset().fY + line.roundingDelta();
                    rect.fBottom = line.offset().fY + line.height();

                } else if (rectHeightStyle == RectHeightStyle::kIncludeLineSpacingTop) {
                    rect.fTop = line.offset().fY;

                } else if (rectHeightStyle == RectHeightStyle::kIncludeLineSpacingMiddle) {
                    rect.fTop -= (rect.fTop - line.offset().fY) / 2;
                    rect.fBottom += (line.offset().fY + line.height() - rect.fBottom) / 2;

                } else if (rectHeightStyle == RectHeightStyle::kIncludeLineSpacingBottom) {
                    rect.fBottom = line.offset().fY + line.height();
                }
            }
        } else {
            // Just leave the boxes the way they are
        }

        if (rectWidthStyle == RectWidthStyle::kMax) {
            for (auto& i = firstBox; i < results.size(); ++i) {
                auto clip = results[i].rect;
                auto dir = results[i].direction;
                if (clip.fLeft > line.offset().fX) {
                    SkRect left = SkRect::MakeXYWH(0, clip.fTop, clip.fLeft - line.offset().fX,
                                                   clip.fBottom);
                    results.insert(results.begin() + i, {left, dir});
                    ++i;
                }
                if (clip.fRight < line.offset().fX + line.width()) {
                    SkRect right = SkRect::MakeXYWH(clip.fRight - line.offset().fX,
                                                    clip.fTop,
                                                    line.width() - (clip.fRight - line.offset().fX),
                                                    clip.fBottom);
                    results.insert(results.begin() + i, {right, dir});
                    ++i;
                }
            }
        }
    }

    return results;
}