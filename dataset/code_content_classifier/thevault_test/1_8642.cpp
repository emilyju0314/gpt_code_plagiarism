void resetConfig()
{

    // delete EEPROM config
    EEPROM.begin(4095);
    for (unsigned int i = 0; i < sizeof(cfg); i++)
    {
        EEPROM.write(i, 0);
    }
    delay(CONFIG_COMMIT_DELAY);
    EEPROM.commit();
    EEPROM.end();

    // set to default config
    cfg = default_cfg;
    saveConfig(true);
}