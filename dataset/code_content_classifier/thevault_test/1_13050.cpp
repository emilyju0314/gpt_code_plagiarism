void GameScene::Begin()
	{
		Debug::Log("AudioTest::GameScene::Begin()!");
        
		Scene::Begin();
		
		FontAsset* font = Assets::RequestFont("AudioTest/LiberationSans-Regular.ttf", 25.0f);
        scText = new Text("Dual-worlds Audio Demo", font);
        scText->position = Vector2(50, 50);
        Add(scText);
        
        // Make the deck, and it starts playing... (we need a play())
        deck = Audio::NewDeck( Assets::RequestAudio("AudioTest/ShortLoop.ogg", true) );
        
        if (!deck)
            return Game::Quit();
        
        deck->Play();
        deck->SetLoops(0);
        deck->SetFadeOut(500);
        
        Waveform* wave = new Waveform(deck,1);
        Add(wave);
        
        wave = new Waveform(deck,0);
        Add(wave);
	}