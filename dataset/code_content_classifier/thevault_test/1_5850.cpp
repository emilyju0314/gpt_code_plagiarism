Image::Image(FT_Bitmap bitmap, size_t padding, size_t divisibleBy)
        : Image(divisiblePadding(bitmap.width, padding, divisibleBy),
                divisiblePadding(bitmap.rows, padding, divisibleBy),
                1) {
        if (padding > 0 || bitmap.width % divisibleBy != 0 || bitmap.rows % divisibleBy != 0) {
            Vec2<size_t> paddingVec{padding, padding},
                         imgSize{bitmap.width, bitmap.rows};
            Image&& paddedView = view(paddingVec, imgSize + paddingVec);
            paddedView.load(bitmap);
            fillPadding({paddingVec, imgSize});
        } else {
            load(bitmap);
        }
    }