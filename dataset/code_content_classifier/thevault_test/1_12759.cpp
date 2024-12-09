int CdCheckPair::collide(int* num, collision_data** cPair, int flag)
{
    int ret = collide(num, flag);
    *cPair = CdWrapper::getCollisionData(); // get collision information
    return ret;
}