void stitchReduce(QImage& next, const LifeSlice &slice) {
    if (next.isNull()) 
        next = QImage(boardSize, QImage::Format_Mono);
    QPainter painter(&next);
    painter.drawImage(slice.rect.topLeft(), slice.image);   /* Draw one piece of 
                an image onto another. */
}