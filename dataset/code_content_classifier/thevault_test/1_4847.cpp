Vector2 Vector2::getOneUnitOrthogonalVector() const {

    decimal l = length();
    assert(l > MACHINE_EPSILON);

    return Vector2(-y / l, x / l);
}