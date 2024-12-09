bool GameScene::init()
{
	if (!Scene::initWithPhysics())
    {
        return false;
    }

	this->getPhysicsWorld()->setGravity(Vect(0, -900));
    
	// Add the background
	auto backgroundLayer = BackgroundLayer::create();
	if (backgroundLayer) {
		this->addChild(backgroundLayer);
	}

    return true;
}