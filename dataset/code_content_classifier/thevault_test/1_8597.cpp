void Player::NextInput()
{
    srand(time(NULL));
    activeInput = rand() % iconNames.size();

    chordTimer->Reset();
}