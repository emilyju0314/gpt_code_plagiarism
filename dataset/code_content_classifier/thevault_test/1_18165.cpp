void StarConfig::sl_overall_config_changed(const QString& _text) {
    try {
      m_overall = Overall {
        std::stod(q_gravitationalConstantEdit->text().toStdString()),
        std::stod(q_delta_t_Edit->text().toStdString()),
        std::stoi(q_iterationLimitEdit->text().toStdString()),
        std::stod(q_escapeRadiusEdit->text().toStdString()),
        std::stod(q_simulationSpeedEdit->text().toStdString())
      };
      sig_update_overall(m_overall);
    } catch (std::invalid_argument) {
      cout << "ignoring invalid strings in overall group" << '\n';
    }
  }