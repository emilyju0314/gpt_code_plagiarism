void 
PinoPacket::displayComments()
{
	list<PinoComment>	cmtList;
	list<PinoComment>::iterator it;
	
	cmtList = getCommentList();		

    for (it = cmtList.begin(); it != cmtList.end(); it++)
    {
         cout << "URL:" <<  it->getURL() << endl;
         cout << "Author:" <<  it->getAuthor() << endl;
         cout << "Time:" <<  it->getTime() << endl;
         cout << "Comment:" <<  it->getContent() << endl;
		 cout << " ------------------------------------- " << endl;
    } 
}