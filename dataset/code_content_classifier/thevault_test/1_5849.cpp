bool FntWriter::setCharInfo(FT_ULong charcode, Rect<PackingSizeType> charArea, std::set<FT_ULong> charsWithoutRect) {

        size_t charAreaPosX;
        size_t charAreaPosY;
        size_t charAreaWidth;
        size_t charAreaHeight;

        const bool charIsDepictable = charsWithoutRect.find(charcode) == charsWithoutRect.end();
        if (charIsDepictable) {
            charAreaPosX = charArea.position.x;
            charAreaPosY = charArea.position.y;
            charAreaWidth = charArea.size.x;
            charAreaHeight = charArea.size.y;
        } else {
            // for example, the space char is not depictable (thus, is not contained in the glyph texture), but
            // actually has a width in typesetting (called xAdvance).
            // The position in the texture atlas (at the pixel's color at that position) has no meaning, as the
            // width and height of that glyph in the texture is zero.
            charAreaPosX = 0;
            charAreaPosY = 0;
            charAreaWidth = 0;
            charAreaHeight = 0;
        }

        FT_UInt gindex = FT_Get_Char_Index(face, charcode);
        FT_Load_Glyph(face, gindex, FT_LOAD_DEFAULT);

        // bearing is provided in 26.6 fixed - point format
        FT_Pos yBearing = from_26_6_fixed_precision(face->glyph->metrics.horiBearingY);
        maxYBearing = std::max(yBearing, maxYBearing);

        CharInfo charInfo;
        charInfo.id = charcode;
        charInfo.x = charAreaPosX;
        charInfo.y = charAreaPosY;
        charInfo.width = charAreaWidth;
        charInfo.height = charAreaHeight;
        charInfo.xAdvance = from_16_16_fixed_precision(face->glyph->linearHoriAdvance);
        charInfo.xOffset = from_26_6_fixed_precision(face->glyph->metrics.horiBearingX);
        charInfo.yOffset = yBearing;
        charInfo.page = 1;
        charInfo.chnl = 15;
        charInfos.push_back(charInfo);

        return charIsDepictable;
    }