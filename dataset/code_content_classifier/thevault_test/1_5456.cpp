void ChaCha_Policy::OperateKeystream(KeystreamOperation operation,
        byte *output, const byte *input, size_t iterationCount)
{
    do
    {
#if (CRYPTOPP_SSE2_INTRIN_AVAILABLE || CRYPTOPP_SSE2_ASM_AVAILABLE)
        if (HasSSE2())
        {
            while (iterationCount >= 4 && MultiBlockSafe())
            {
                const bool xorInput = (operation & INPUT_NULL) != INPUT_NULL;
                ChaCha_OperateKeystream_SSE2(m_state, xorInput ? input : NULLPTR, output, m_rounds);

                // MultiBlockSafe avoids overflow on the counter words
                m_state[12] += 4;
                //if (m_state[12] < 4)
                //    m_state[13]++;

                input += (!!xorInput)*4*BYTES_PER_ITERATION;
                output += 4*BYTES_PER_ITERATION;
                iterationCount -= 4;
            }
        }
#endif

#if (CRYPTOPP_ARM_NEON_AVAILABLE)
        if (HasNEON())
        {
            while (iterationCount >= 4 && MultiBlockSafe())
            {
                const bool xorInput = (operation & INPUT_NULL) != INPUT_NULL;
                ChaCha_OperateKeystream_NEON(m_state, xorInput ? input : NULLPTR, output, m_rounds);

                // MultiBlockSafe avoids overflow on the counter words
                m_state[12] += 4;
                //if (m_state[12] < 4)
                //    m_state[13]++;

                input += (!!xorInput)*4*BYTES_PER_ITERATION;
                output += 4*BYTES_PER_ITERATION;
                iterationCount -= 4;
            }
        }
#endif

#if (CRYPTOPP_POWER8_AVAILABLE)
        if (HasPower8())
        {
            while (iterationCount >= 4 && MultiBlockSafe())
            {
                const bool xorInput = (operation & INPUT_NULL) != INPUT_NULL;
                ChaCha_OperateKeystream_POWER8(m_state, xorInput ? input : NULLPTR, output, m_rounds);

                // MultiBlockSafe avoids overflow on the counter words
                m_state[12] += 4;
                //if (m_state[12] < 4)
                //    m_state[13]++;

                input += (!!xorInput)*4*BYTES_PER_ITERATION;
                output += 4*BYTES_PER_ITERATION;
                iterationCount -= 4;
            }
        }
#endif

        if (iterationCount)
        {
            word32 x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15;

            x0 = m_state[0];    x1 = m_state[1];    x2 = m_state[2];    x3 = m_state[3];
            x4 = m_state[4];    x5 = m_state[5];    x6 = m_state[6];    x7 = m_state[7];
            x8 = m_state[8];    x9 = m_state[9];    x10 = m_state[10];  x11 = m_state[11];
            x12 = m_state[12];  x13 = m_state[13];  x14 = m_state[14];  x15 = m_state[15];

            for (int i = static_cast<int>(m_rounds); i > 0; i -= 2)
            {
                CHACHA_QUARTER_ROUND(x0, x4,  x8, x12);
                CHACHA_QUARTER_ROUND(x1, x5,  x9, x13);
                CHACHA_QUARTER_ROUND(x2, x6, x10, x14);
                CHACHA_QUARTER_ROUND(x3, x7, x11, x15);

                CHACHA_QUARTER_ROUND(x0, x5, x10, x15);
                CHACHA_QUARTER_ROUND(x1, x6, x11, x12);
                CHACHA_QUARTER_ROUND(x2, x7,  x8, x13);
                CHACHA_QUARTER_ROUND(x3, x4,  x9, x14);
            }

            CRYPTOPP_KEYSTREAM_OUTPUT_SWITCH(CHACHA_OUTPUT, BYTES_PER_ITERATION);

            if (++m_state[12] == 0)
                m_state[13]++;
        }

    // We may re-enter a SIMD keystream operation from here.
    } while (iterationCount--);
}