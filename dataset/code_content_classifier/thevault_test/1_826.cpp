void Player::valueProperty(vector<int> &property) {
    for (vector<int>::iterator it = property.begin();
        it != property.end();
        ++it)
    {
        // Use iterator to read and write data from property vector
        *it *= (1 + (this->getGrowth() * 0.01));
    }
}