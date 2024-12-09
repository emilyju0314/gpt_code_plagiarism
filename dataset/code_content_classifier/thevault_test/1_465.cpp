game::game(){
	int boardSizeX, boardSizeY;
	string survive="23", born="3";
	
	
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	boardSizeX=(w.ws_col-20)/2;
	boardSizeY=w.ws_row-12;
	
	rS=ruleStringToInt(survive);
	rB=ruleStringToInt(born);
	board = tab(boardSizeX,boardSizeY);
	prevBegin=0;
	prevEnd=0;
	randomize();
}