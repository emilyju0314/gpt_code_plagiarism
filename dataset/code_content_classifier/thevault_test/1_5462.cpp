static void aaResize(uvec2 size)
{
	ASSERT(size.x > 0);
	ASSERT(size.y > 0);
	if (size.x == currentSize.x && size.y == currentSize.y) return;
	currentSize.x = size.x;
	currentSize.y = size.y;

	if (msaaFbColor.id)
		msaaFbColor.resize(size);
	if (msaaFbDepthStencil.id)
		msaaFbDepthStencil.resize(size);

	if (smaaSeparateFbColor.id)
		smaaSeparateFbColor.resize(size);
	if (smaaEdgeFbColor.id)
		smaaEdgeFbColor.resize(size);
	if (smaaEdgeFbDepthStencil.id)
		smaaEdgeFbDepthStencil.resize(size);
	if (smaaBlendFbColor.id)
		smaaBlendFbColor.resize(size);

	if (smaaSeparateFbColor2.id)
		smaaSeparateFbColor2.resize(size);
	if (smaaEdgeFbColor2.id)
		smaaEdgeFbColor2.resize(size);
	if (smaaEdgeFbDepthStencil2.id)
		smaaEdgeFbDepthStencil2.resize(size);
	if (smaaBlendFbColor2.id)
		smaaBlendFbColor2.resize(size);
}