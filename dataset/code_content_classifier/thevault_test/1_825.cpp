void Player::initializeProperty(vector<int> &property) {
    for (vector<int>::iterator it = property.begin();
        it != property.end();
        ++it)
    {
        // Assign each property an initial value from $300,000-500,000
        int price = 300000 + rand() % (200000 + 1);
        *it = price;
    }
}