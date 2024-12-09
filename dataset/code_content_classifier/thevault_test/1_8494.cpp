static void cs_base64_emit_code(struct cs_base64_ctx *ctx, int v) {
    if (v < NUM_UPPERCASES) {
        ctx->b64_putc(v + 'A', ctx->user_data);
    } else if (v < (NUM_LETTERS)) {
        ctx->b64_putc(v - NUM_UPPERCASES + 'a', ctx->user_data);
    } else if (v < (NUM_LETTERS + NUM_DIGITS)) {
        ctx->b64_putc(v - NUM_LETTERS + '0', ctx->user_data);
    } else {
        ctx->b64_putc(v - NUM_LETTERS - NUM_DIGITS == 0 ? '+' : '/',
                      ctx->user_data);
    }
}