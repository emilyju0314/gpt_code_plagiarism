void autoFocus(){
    Vector3 viewDir = camera->dirInWorldCoords(Vector3(0, 0, -1));
    Ray ray = Ray(camera->pos + viewDir * 0.1f, viewDir, 0.0f, FLT_MAX, 555);
    Hitpoint p;

    scene->aStruct->intersect(ray, p);
    if (p.hit) {
        camera->focus(p.dist * 1000.0f);
    }
    sensor->clear();
}