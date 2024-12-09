void DrawTest::drawReferenceImage (const tcu::PixelBufferAccess& refImage) const
{
	using tcu::Vec2;
	using tcu::Vec4;
	using tcu::IVec4;

	const Vec2	perInstanceOffset[]	= { Vec2(0.0f, 0.0f), Vec2(-0.3f,  0.0f), Vec2(0.0f, 0.3f) };
	const Vec2	perDrawOffset[]		= { Vec2(0.0f, 0.0f), Vec2(-0.3f, -0.3f), Vec2(0.3f, 0.3f) };
	const Vec4	allColors[]			= { Vec4(1.0f), Vec4(0.0f, 0.0f, 1.0f, 1.0f), Vec4(0.0f, 1.0f, 0.0f, 1.0f) };
	const int	numInstances		= isInstanced() ? MAX_INSTANCE_COUNT		: 1;
	const int	numIndirectDraws	= isMultiDraw() ? MAX_INDIRECT_DRAW_COUNT	: 1;
	const int	rectWidth			= static_cast<int>(WIDTH  * 0.6f / 2.0f);
	const int	rectHeight			= static_cast<int>(HEIGHT * 0.6f / 2.0f);

	DE_ASSERT(DE_LENGTH_OF_ARRAY(perInstanceOffset) >= numInstances);
	DE_ASSERT(DE_LENGTH_OF_ARRAY(allColors) >= numInstances && DE_LENGTH_OF_ARRAY(allColors) >= numIndirectDraws);
	DE_ASSERT(DE_LENGTH_OF_ARRAY(perDrawOffset) >= numIndirectDraws);

	tcu::clear(refImage, tcu::Vec4(0.0f, 0.0f, 0.0f, 1.0f));

	for (int drawNdx     = 0; drawNdx     < numIndirectDraws; ++drawNdx)
	for (int instanceNdx = 0; instanceNdx < numInstances;     ++instanceNdx)
	{
		const Vec2	offset	= perInstanceOffset[instanceNdx] + perDrawOffset[drawNdx];
		const Vec4&	color	= allColors[isMultiDraw() ? drawNdx : instanceNdx];
		int			x		= static_cast<int>(WIDTH  * (1.0f - 0.3f + offset.x()) / 2.0f);
		int			y		= static_cast<int>(HEIGHT * (1.0f - 0.3f + offset.y()) / 2.0f);

		tcu::clear(tcu::getSubregion(refImage, x, y, rectWidth, rectHeight), color);
	}
}