double compute_block_ssim(uint t, const uint8* pX, const uint8* pY)
        {
            double ave_x = 0.0f;
            double ave_y = 0.0f;
            for (uint i = 0; i < t; i++)
            {
                ave_x += pX[i];
                ave_y += pY[i];
            }

            ave_x /= t;
            ave_y /= t;

            double var_x = 0.0f;
            double var_y = 0.0f;
            for (uint i = 0; i < t; i++)
            {
                var_x += math::square(pX[i] - ave_x);
                var_y += math::square(pY[i] - ave_y);
            }

            var_x = sqrt(var_x / (t - 1));
            var_y = sqrt(var_y / (t - 1));

            double covar_xy = 0.0f;
            for (uint i = 0; i < t; i++)
            {
                covar_xy += (pX[i] - ave_x) * (pY[i] - ave_y);
            }

            covar_xy /= (t - 1);

            const double c1 = 6.5025; //(255*.01)^2
            const double c2 = 58.5225; //(255*.03)^2

            double n = (2.0f * ave_x * ave_y + c1) * (2.0f * covar_xy + c2);
            double d = (ave_x * ave_x + ave_y * ave_y + c1) * (var_x * var_x + var_y * var_y + c2);

            return n / d;
        }