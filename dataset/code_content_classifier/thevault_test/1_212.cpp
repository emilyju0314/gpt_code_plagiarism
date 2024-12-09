void MouseClicked(int button, int state, int x, int y) {
	if (game_start==false)
		game_start=true;
	else if (second_click==false) //avoid bug due to double click detection
	{
		second_click=true;
		//checks any combinations formed in the random letters
		while (popped)
		{
			popped=false; //continues checking until no more words are formed
			for (int i=0; i<nfrows; i++)
			{
				for (int j=0; j<cells-9; j++)
				{
					tile_y=i;
					tile_x=j;
					temp_word=form_word(4); //forms horizontally right combinations of letters
					check_pop_word(temp_word); 
				}
			}
			for (int i=0; i<nfrows; i++)
			{
				for (int j=0; j<cells; j++)
				{
					if (Alphabets[i][j]==27)
						Alphabets[i][j]=GetAlphabet(); //generates new letters for the popped indices in the array
				}
			}
		}
	}
	else
	{
		if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{
			if (state == GLUT_UP && moving_ball==false && y<=height-bheight-10)
			{
				slope=float(x-ball_x)/(height-y-ball_y);
				moving_ball=true;
			}
		}
		else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
		{//right click swaps the two shooter balls
			if (swapped==false)
			{
				int temp=AlphShooter;
				AlphShooter=AlphSecond;
				AlphSecond=temp;
				swapped=true;
			}
			else
				swapped=false;
		}
	}
	glutPostRedisplay();
}