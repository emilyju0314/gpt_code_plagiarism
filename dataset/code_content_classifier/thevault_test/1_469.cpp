void game::next(){
	tab nxt(board.lar,board.alt);
	FOR(i,board.lar){
		FOR(j,board.alt){
			int neigh=board.neigh(i,j);
			if((isAlive(i,j) && willSurvive(neigh)) || (!isAlive(i,j) && willBeBorn(neigh))){
			
				//TODO: maybe we can add a DEBUG feature that prints those information
				//if((isAlive(i,j) && willSurvive(i,j,neigh)))cout << i << " " << j << " alive and survive" << endl;
				//if((!isAlive(i,j) && willBeBorn(i,j,neigh)))cout << i << " " << j << " dead and born" << endl;
				//cout << "survive = " << rS << " born = " << rB << " neigh = " << neigh << endl;
				nxt.v[i][j]=neigh+1;
				nxt.cont++;
			}
		}
	}
	prev[prevEnd]=board;
	prevEnd = (prevEnd+1)%10;
	if(prevEnd==prevBegin)prevBegin = (prevBegin+1)%10;
	board = nxt;
}