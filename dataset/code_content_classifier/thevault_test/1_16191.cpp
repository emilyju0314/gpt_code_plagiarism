PlayerSpecificSettings* CloneSettings(PlayerSpecificSettings* settings) {
        PlayerSpecificSettings* clone = PlayerSpecificSettings::New_ctor();
        clone->adaptiveSfx = settings->adaptiveSfx;
        clone->advancedHud = settings->advancedHud;
        clone->automaticPlayerHeight = settings->automaticPlayerHeight;
        clone->autoRestart = settings->autoRestart;
        clone->hideNoteSpawnEffect = settings->hideNoteSpawnEffect;
        clone->leftHanded = settings->leftHanded;
        clone->noFailEffects = settings->noFailEffects;
        clone->noteJumpStartBeatOffset = settings->noteJumpStartBeatOffset;
        clone->noTextsAndHuds = settings->noTextsAndHuds;
        clone->playerHeight = settings->playerHeight;
        clone->reduceDebris = settings->reduceDebris;
        clone->saberTrailIntensity = settings->saberTrailIntensity;
        clone->sfxVolume = settings->sfxVolume;
        clone->environmentEffectsFilterDefaultPreset = settings->environmentEffectsFilterDefaultPreset;
        clone->environmentEffectsFilterExpertPlusPreset = settings->environmentEffectsFilterExpertPlusPreset;
        return clone;
    }