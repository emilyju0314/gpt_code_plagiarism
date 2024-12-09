void Projectile_normal::anim(int direction)
{
	if (actif && animation < ANIMATION_MAXIMALE)
	{
		animation++;
		if (animation % RHYTME_ANIM == 0)
		{
			if (rectangleAnimation.top < 350) //pour ne pas faire disparaitre le proj a la fin de lanim
			{
				setScale(0.5 *direction, getScale().y);
				rectangleAnimation.top += image;
				setTextureRect(rectangleAnimation);
			}
		}

	}
}