Func blur_cols_transpose(Func input, Expr height, Expr alpha) {
    Func blur;

    // Pure definition: do nothing.
    blur(x, y, c) = undef<float>();
    // Update 0: set the top row of the result to the input.
    blur(x, 0, c) = input(x, 0, c);
    // Update 1: run the IIR filter down the columns.
    RDom ry(1, height - 1);
    blur(x, ry, c) =
        (1 - alpha)*blur(x, ry - 1, c) + alpha*input(x, ry, c);
    // Update 2: run the IIR blur up the columns.
    Expr flip_ry = height - ry - 1;
    blur(x, flip_ry, c) =
        (1 - alpha)*blur(x, flip_ry + 1, c) + alpha*blur(x, flip_ry, c);

    // Transpose the blur.
    Func transpose;
    transpose(x, y, c) = blur(y, x, c);

    // Schedule:
    // Split the transpose into tiles of rows. Parallelize over channels
    // and strips (Halide supports nested parallelism).
    Var xo, yo;
    transpose.compute_root()
        .tile(x, y, xo, yo, x, y, 8, 8)
        .vectorize(x)
        .parallel(yo)
        .parallel(c);

    // Run the filter on each row of tiles (which corresponds to a strip of
    // columns in the input).
    blur.compute_at(transpose, yo);

    // Vectorize computations within the strips.
    blur.update(1)
        .reorder(x, ry)
        .vectorize(x);
    blur.update(2)
        .reorder(x, ry)
        .vectorize(x);

    return transpose;
}