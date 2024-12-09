void sortByName(tChatsList &list) {

	bool inter = true;
	int i = 0;

	while ((i < list.counter - 1) && inter) {
		inter = false;
		for (int j = list.counter - 1; j > i; j--) {
			if (list.chat[j].idChat < list.chat[j - 1].idChat) {
				tChat tmp;
				tmp = list.chat[j];
				list.chat[j] = list.chat[j - 1];
				list.chat[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}
}