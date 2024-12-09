void Player::displayProperty(const vector<int> &property,
                             const vector<bool> &isOwner)
{
    displayHeader();
    displayBody(property, isOwner);
    displayTail();

}