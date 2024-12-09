static void mrsEffectDrop(void)
{
	for (size_t i = 0; i < MinosPerPiece; i += 1) {
		int x = mrsTet.player.pos.x + mrsTet.player.shape[i].x;
		int y = mrsTet.player.pos.y + mrsTet.player.shape[i].y;
		if (fieldGet(mrsTet.field, (ivec2){x, y - 1})) {
			particlesGenerate((vec3){
				(f32)x - (f32)FieldWidth / 2,
				(f32)y,
				0.0f
			}, 8, &particlesThump);
		}
	}
}