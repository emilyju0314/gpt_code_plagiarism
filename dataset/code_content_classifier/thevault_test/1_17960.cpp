static float EdgeFunction(vec4 &v0, vec4 &v1, vec2 &p)
{
    float result = (v0.x - v1.x)*(p.y - v0.y) - (v0.y - v1.y)*(p.x - v0.x);	// Remapped because y is inverted in raster space
    return result;
}