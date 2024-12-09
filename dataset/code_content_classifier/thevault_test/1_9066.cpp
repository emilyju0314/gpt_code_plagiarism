bool Maze::MoveCheck(Room* room, Direction dir)
{
	string form = room->getName() + "_";
	if (dir == Direction::NORTH)
	{
		form += "north";
	}
	else if (dir == Direction::EAST)
	{
		form += "east";
	}
	else if (dir == Direction::SOUTH)
	{
		form += "south";
	}
	else if (dir == Direction::WEST)
	{
		form += "west";
	}
	if (form == "h1_north" && !m_Player->hasItem("House Key"))
	{
		cout << "Surprisingly enough, while the door seemed to be just barely holding on\nto it's hinges it still stands\nsturdy enough to stop you from leaving, seemingly locked.\nPerhaps a key is around here somewhere?" << endl;
		return false;
	}
	else if (form == "h1_east" || form == "h1_south" || form == "h1_west")
	{
		cout << "You search for something on the walls to no avail." << endl;
		return false;
	}

	if (form == "f1_east" || form == "f1_west")
	{
		cout << "It doesn't look like you can head this way..." << endl;
		return false;
	}
	else if (form == "f1_south")
	{
		cout << "The door seems to have shut closed behind you, locking..." << endl;
		return false;
	}

	if (form == "reset_north" || form == "reset_west")
	{
		cout << "You don't seem to be able to find a path through this direction." << endl;
		return false;
	}
	else if (form == "reset_south")
	{
		cout << "Something odd seems to have occured\nas you entered the clearing.\nYou can't find a way back..." << endl;
		return false;
	}

	if (form == "f6_west")
	{
		cout << "You search the side of the house\nbut don't find anything." << endl;
		return false;
	}

	if (form == "end_west" || form == "end_north" || form == "end_south" || form == "end_east")
	{
		cout << "This path is blocked... They all seemed blocked... What is this?" << endl;
		return false;
	}
	if (form != "h1_north") { cout << "You step into the unknown and..." << endl; }
	else { cout << "The key fits nicely into the lock, you open the door and..." << endl; }

	if (room->getNext(dir) == 0)
	{
		cout << "...something seems to click,\nall the light around you seeming to fade away\nwithout so much as a whisper.\nYou stumble around in the darkness for a while,\nbumping into a few trees,\nbefore you return to a vaguely familiar clearing,\na statue of an Angel\nstanding in the middle..." << endl;
		m_Player->setHealth(m_Player->getHealth() - 2);
	}
	else
	{
		string next = room->getNext(dir)->getName();
		if (form == "h1_north")
		{
			cout << "...Step out into the woods." << endl;
		}
		else if (*next.cbegin() == 'f')
		{
			cout << "...find a small clearing in the woods." << endl;
		}
		else if (next == "reset" || next == "end")
		{
			cout << "...find a large clearing with an odd statue..." << endl;
		}
	}
	return true;
}