void Init(size_t start, size_t size) {
    if (size > config::maxsize) {
        logger::print("Init size exceed maxsize: %lx\n", size);
        return;
    }
    logger::print("Taint\t(%p, %lx)\n", start, size);
    logger::info("Taint\t(%p, %lx)\n", start, size);
    inits.taint(start, size);
    mems.taint(start, size);
}