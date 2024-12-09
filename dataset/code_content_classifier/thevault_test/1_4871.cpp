std::string HeightFieldShape::to_string() const {

    std::stringstream ss;

    ss << "HeightFieldShape{" << std::endl;

    ss << "nbColumns=" << mNbColumns << std::endl;
    ss << ", nbRows=" << mNbRows << std::endl;
    ss << ", width=" << mWidth << std::endl;
    ss << ", length=" << mLength << std::endl;
    ss << ", minHeight=" << mMinHeight << std::endl;
    ss << ", maxHeight=" << mMaxHeight << std::endl;
    ss << ", upAxis=" << mUpAxis << std::endl;
    ss << ", integerHeightScale=" << mIntegerHeightScale << std::endl;
    ss << "}";

    return ss.str();
}