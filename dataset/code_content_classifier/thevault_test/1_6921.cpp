void WirelessNetModel::placeEdge(Edge* e, Node* src) const
{
        if (e->marked() == 0) {
                double hyp, dx, dy;
                Node *dst = e->neighbor();
                dx=dst->x()-src->x();
                dy=dst->y()-src->y();
                hyp=sqrt(dx*dx + dy*dy);
           //   e->setAngle(atan2(dy,dx));
                double x0 = src->x() + src->size() * (dx/hyp) * .75;
                double y0 = src->y() + src->size() * (dy/hyp) * .75;
                double x1 = dst->x() - dst->size() * (dx/hyp) * .75;
                double y1 = dst->y() - dst->size() * (dy/hyp) * .75;
                e->place(x0, y0, x1, y1);

                /* Place the queue here too.  */
                EdgeHashNode *h = lookupEdgeHashNode(e->src(), e->dst());
		if (h != 0) {
                    if (h->queue != 0)
                        h->queue->place(e->size(), e->x0(), e->y0());
		}

                e->mark();
        }
}