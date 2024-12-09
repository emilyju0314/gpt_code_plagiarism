void OrderList::remove(int x)
{

	this->orderQueue.erase(orderQueue.begin() + x);

}