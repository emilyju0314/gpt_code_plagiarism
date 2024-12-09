void CollisionDetectionSystem::removeItemAtInArray(uint array[], uint8 index, uint8& arraySize) const {
    assert(index < arraySize);
    assert(arraySize > 0);
    array[index] = array[arraySize - 1];
    arraySize--;
}