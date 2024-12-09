void render_chunk_water(chunk* the_chunk)
{
	if (the_chunk->water_target_size_in_floats > 0)
	{
		// Bind the water_target_vao to the current state.

		glBindVertexArray(the_chunk->water_target_vao);

		// Draw the water vertex array object as an array of triangles.

		glDrawArrays(GL_TRIANGLES, 0, the_chunk->water_target_size_in_floats / 7);

		// Unbind the water_target_vao from the current state.

		glBindVertexArray(0);
	}
}