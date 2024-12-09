Vector2 Entity::GetWorldPosition(const Vector2 &position)
	{
		Vector2 returnPos;

		Graphics::PushMatrix();
		Graphics::IdentityMatrix();

		MatrixChain();

		Graphics::Translate(position);

		returnPos = Graphics::GetMatrixPosition();

		Graphics::PopMatrix();

		return returnPos;
	}