void Dealer::deal(Player &player, Deck &deck) {
    std::cout << std::endl;

    player.hit(deck);
    this->hit(deck);
    player.hit(deck);
    this->hit(deck);

    player.print();
    std::cout << "Dealer's first card is: " << hand.begin()->get()->value << " of " << hand.begin()->get()->suit << std::endl;
}