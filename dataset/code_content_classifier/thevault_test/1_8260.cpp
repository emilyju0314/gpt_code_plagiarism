void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isDrawing) {
        drawLineTo(event->pos());
        isDrawing = false;
    }
}