MeshLink::~MeshLink()
{
	RemoveAsSource();
	RemoveAsDest();
	SetSource ( NULL );
	SetDest ( NULL );
	SetOwner ( NULL );
}