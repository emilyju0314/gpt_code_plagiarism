LayerStack::~LayerStack()
{
	// Destroy all layers
	for (Layer* layer : _layers)
	{
		layer->onDetach(); // But before detach them
		delete layer;
	}
}