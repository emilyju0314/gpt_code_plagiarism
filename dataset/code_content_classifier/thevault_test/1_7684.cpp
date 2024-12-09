void Circuit::ShowWhoDidNotFinish() {
	std::cout << "The cars that did not finish are:";
	for (int i = 0; i < CarVector.size(); i++)
	{
		if (CarVector[i]->getFuelCap() / CarVector[i]->getFuelCons() * 100 <= this->length)
			std::cout << CarVector[i] << ' ';
	}
}