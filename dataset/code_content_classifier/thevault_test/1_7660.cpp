void fresnel(const VectorXd &t, VectorXd *s, VectorXd *c)
{
    s->resize(t.size());
    c->resize(t.size());
    for(int i = 0; i < t.size(); ++i)
        fresnel(t[i], &((*s)[i]), &((*c)[i]));
}