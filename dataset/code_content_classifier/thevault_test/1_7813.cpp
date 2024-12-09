int
Rtree::RTreeSearchSphere(struct Point *queryPoint, float radius, vector<int> &answers)
{
    long disk_acc[10];
    struct Node *rootNode = TreeRoot;
    return RTreeSearchSphere(rootNode, queryPoint, radius, disk_acc, answers);
}