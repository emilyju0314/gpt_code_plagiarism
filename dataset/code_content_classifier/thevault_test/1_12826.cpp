Window::Window(event::InputHandler const &inputHandler, Settings const &settings)
  : _actorModel(ActorAsset) {
  auto width = (unsigned int) settings.getWidth();
  auto height = (unsigned int) settings.getHeight();

  this->_window.create(sf::VideoMode(width, height), settings.getTitle());
  this->_window.setVerticalSyncEnabled(true);
  this->_window.setKeyRepeatEnabled(true);
  this->_window.setFramerateLimit(144);
  this->_isRunning = true;
  this->_inputHandler = inputHandler;
  this->_enemyModel[0] = new model::Model(EnemyRow1);
  this->_enemyModel[1] = new model::Model(EnemyRow2);
  this->_enemyModel[2] = new model::Model(EnemyRow3);
  this->_actor
    = std::unique_ptr<actor::Player>(
      new actor::Player(0, (int)height, (int)width, this->_actorModel)
    );
  for(size_t i = 0; i < 3; i++)
  {
    auto y = 160 * (int)i;

    for(auto j = 0; j < 11; j++) {
        this->_enemy[i][j]
          = std::unique_ptr<actor::Enemy>(
            new actor::Enemy(j * 104, y, (int)width, *(this->_enemyModel.at(i)))
          );
    }
  }
}