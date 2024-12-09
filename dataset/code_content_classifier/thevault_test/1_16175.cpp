void Dealer::prompt(Player& player, Deck& deck) {
    int staying = 0;

    std::cout << "Do you wish to hit (1) or stay (0)?" << std::endl;
    std::cin >> staying;

    if(staying) {
        player.hit(deck);
        player.print();
        if(Blackjack::countHand(player.hand) < 21)
            prompt(player, deck);
    }

    while(Blackjack::countHand(this->hand) < 17) {
        this->hit(deck);
    }
}