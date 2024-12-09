void GameScene::Begin()
	{
		Debug::Log("AudioTest::GameScene::Begin()!");

		Scene::Begin();
		
		FontAsset* font = Assets::RequestFont("AudioTest/LiberationSans-Regular.ttf", 25.0f);
        scText = new Text("Dual-worlds Audio Demo", font);
        scText->position = Vector2(50, 50);
        Add(scText);
        
		// Make the deck, and it starts playing... (we need a play())
		//deck1 = Audio::NewDeck(Assets::RequestAudio("AudioTest/City01.g2m",true,"hellogirl"));
        deck1 = Audio::NewDeck(Assets::RequestAudio("AudioTest/City01.g2m", true, "hellogirl"));
		deck2 = Audio::NewDeck(Assets::RequestAudio("AudioTest/City01Hell.g2m",true,"hellogirl"));
        
        if (!deck1 || !deck2)
            return Game::Quit();
        
        deck2->Mute();

		deck1->EnableVis();
        deck2->EnableVis();
        deck1->Play();
        deck2->Play();

        Waveform* wave = new Waveform(deck1,1);
        Add(wave);

        Waveform* wave2 = new Waveform(deck2,1);
        Add(wave2);
	}