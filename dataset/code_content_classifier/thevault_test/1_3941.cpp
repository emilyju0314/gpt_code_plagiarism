void Die::roll()
{
	std::srand(time(NULL));
	roll_value = (std::rand()%6) + 1;
}