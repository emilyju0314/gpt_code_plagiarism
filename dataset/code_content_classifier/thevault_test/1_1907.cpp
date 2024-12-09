float phillips(float Kx, float Ky, float Vdir, float V, float A)
{
    float k_squared = Kx * Kx + Ky * Ky;
    float k_x = Kx / sqrtf(k_squared);
    float k_y = Ky / sqrtf(k_squared);
    float L = V * V / g;
    float w_dot_k = k_x * cosf(Vdir) + k_y * sinf(Vdir);

    if (k_squared == 0) return 0;

    return A * expf(-1.0 / (k_squared * L * L)) / (k_squared * k_squared) * w_dot_k * w_dot_k;
}