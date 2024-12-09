void NegotiateOrder::validate()
{
	if (this->getValid())
		std::cout << "This " << this->getName() << " order is valid." << std::endl;
	else {

		std::cout << "Not a valid order." << std::endl;

	}

}