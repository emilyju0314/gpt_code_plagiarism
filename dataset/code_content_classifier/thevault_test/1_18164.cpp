void StarConfig::sl_star_config_changed(const QString& _text) {
    auto index = q_starSelector->currentIndex() - 1;
    try {
      Star star {
        std::stod(q_massEdit->text().toStdString()),
          {std::stod(q_starPosXEdit->text().toStdString()),
              std::stod(q_starPosYEdit->text().toStdString()),
              std::stod(q_starPosZEdit->text().toStdString())}
      };
      cout << "config changed for star: " << index << " sending: " << star << endl;
      sig_update_star(index, star);
    } catch (std::invalid_argument) {
      cout << "ignoring invalid strings in star config group" << endl;
    }   
  }