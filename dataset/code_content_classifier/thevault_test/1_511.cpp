bool ChessHash::operator==(const ChessHash& hash) noexcept {
    /// I need to decide what I mean by equal, to do that, I need to use this function.
    /// Equal could mean having the exact same member variables
    /// OR equal could mean having all member variables equal except ones that would change depending on the search information (like score, depth, hash flag, and age)
    return this->key == hash.key;
}