static bool refine_block(uint n, const color_quad_u8* block, uint& max16, uint& min16, const uint8* pSelectors)
        {
            static const int w1Tab[4] = { 3, 0, 2, 1 };

            static const int prods_0[4] = { 0x00, 0x00, 0x02, 0x02 };
            static const int prods_1[4] = { 0x00, 0x09, 0x01, 0x04 };
            static const int prods_2[4] = { 0x09, 0x00, 0x04, 0x01 };

            double akku_0 = 0;
            double akku_1 = 0;
            double akku_2 = 0;
            double At1_r, At1_g, At1_b;
            double At2_r, At2_g, At2_b;

            At1_r = At1_g = At1_b = 0;
            At2_r = At2_g = At2_b = 0;
            for (uint i = 0; i < n; i++)
            {
                double r = block[i].r;
                double g = block[i].g;
                double b = block[i].b;
                int step = pSelectors[i];

                int w1 = w1Tab[step];

                akku_0 += prods_0[step];
                akku_1 += prods_1[step];
                akku_2 += prods_2[step];
                At1_r += w1 * r;
                At1_g += w1 * g;
                At1_b += w1 * b;
                At2_r += r;
                At2_g += g;
                At2_b += b;
            }

            At2_r = 3 * At2_r - At1_r;
            At2_g = 3 * At2_g - At1_g;
            At2_b = 3 * At2_b - At1_b;

            double xx = akku_2;
            double yy = akku_1;
            double xy = akku_0;

            double t = xx * yy - xy * xy;
            if (!yy || !xx || (fabs(t) < .0000125f))
            {
                return false;
            }

            double frb = (3.0f * 31.0f / 255.0f) / t;
            double fg = frb * (63.0f / 31.0f);

            uint oldMin = min16;
            uint oldMax = max16;

            // solve.
            max16 = math::clamp<int>(static_cast<int>((At1_r * yy - At2_r * xy) * frb + 0.5f), 0, 31) << 11;
            max16 |= math::clamp<int>(static_cast<int>((At1_g * yy - At2_g * xy) * fg + 0.5f), 0, 63) << 5;
            max16 |= math::clamp<int>(static_cast<int>((At1_b * yy - At2_b * xy) * frb + 0.5f), 0, 31) << 0;

            min16 = math::clamp<int>(static_cast<int>((At2_r * xx - At1_r * xy) * frb + 0.5f), 0, 31) << 11;
            min16 |= math::clamp<int>(static_cast<int>((At2_g * xx - At1_g * xy) * fg + 0.5f), 0, 63) << 5;
            min16 |= math::clamp<int>(static_cast<int>((At2_b * xx - At1_b * xy) * frb + 0.5f), 0, 31) << 0;

            return (oldMin != min16) || (oldMax != max16);
        }