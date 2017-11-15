

#include "stdafx.h"
# include <vector>
#include <math.h>

using namespace std;
/*Class That implements the sudoku as a double array*/
class Sudoku {
private:
	int grid[9][9];
public:
	Sudoku(int clues[9][9]);
	Sudoku() {    /*Method to initialise the Sudoku to zeros*/
		int igrid;
		int jgrid;
		for (igrid = 0; igrid < 9; igrid++)
		{
			for (jgrid = 0; jgrid < 9; jgrid++)
			{
				this->grid[igrid][jgrid] = 0;
			}
		}
	};
	int getgrid(int i, int j); /*get the value at a position over the grid*/
	bool solve(); /*Solve the Sudoku */
	bool checktrial(int trial,int igrid,int jgrid); /*Check if the trial number can sit in its position*/
};

Sudoku::Sudoku(int clues[9][9]) {
	int igrid;
	int jgrid;
	for (igrid = 0; igrid < 9; igrid++)
	{
		for (jgrid = 0; jgrid < 9; jgrid++)
		{
			this->grid[igrid][jgrid] = clues[igrid][jgrid];
		}
	}
}

int Sudoku::getgrid(int i, int j)
{
	return this->grid[i][j];
}

bool Sudoku::solve()
{
	int igrid;
	int jgrid;
	vector<int> rows;
	vector<int> cols;
	int ntrials = 0;
	int trial = 0;

	for (igrid = 0; igrid < 9; igrid++)
	{		
		for (jgrid = 0; jgrid < 9; jgrid++)
		{
			if (this->grid[igrid][jgrid] == 0)
			{
				while(ntrials < 9 & trial < 10)
				{
					trial = trial + 1;
					if (this->checktrial(trial, igrid, jgrid))  //If the trial is not correct, use another number
					{
						ntrials++;
					}
					else //else accept the trial and move on
					{
						this->grid[igrid][jgrid] = trial;
						rows.push_back(igrid);
						cols.push_back(jgrid);
						break;
					}

				}
				if (ntrials < 9 & trial < 10)
				{
					trial = 0;
					ntrials = 0;
					//Solution accepted
				}
				else
				{
					igrid = rows.back();
					jgrid = cols.back();
					ntrials = 0;
					trial = this->grid[igrid][jgrid];
					rows.pop_back();
					cols.pop_back();
					this->grid[igrid][jgrid] = 0;
					jgrid--;
					// Skip to last igrid and jgrid, set new number of trials, try again 
				}
				

			}
		}
	}
	return true;
};

bool Sudoku::checktrial(int trial, int igrid, int jgrid)
{
	int iloop;
	int jloop;
	int isquare;
	int jsquare;
	int offseti;
	int offsetj;
	/*Check columns*/
	for (iloop = 0; iloop < 9; iloop++)
	{
		if (trial == this->grid[iloop][jgrid])
		{
			return true;
		}
	}

	/*Check rows*/
	for (jloop = 0; jloop < 9; jloop++)
	{
		if (trial == this->grid[igrid][jloop])
		{
			return true;
		}
	}

	/*Check square*/

	isquare = floor(igrid / 3);
	jsquare = floor(jgrid / 3);
	offseti = 3 * isquare;
	offsetj = 3 * jsquare; 

	for (iloop = 0; iloop < 3; iloop++)
	{
		for (jloop = 0; jloop < 3; jloop++)
		{
			if (trial == this->grid[iloop + offseti][jloop + offsetj])
			{
				return true;
			}
		}

	}



	return false;




};


int main()   /*Driver program, with a trial sudoku*/
{
	
	int clues[9][9];
	int igrid, jgrid;
	

	for (igrid = 0; igrid < 9; igrid++)
	{
		for (jgrid = 0; jgrid < 9; jgrid++)
		{
			clues[igrid][jgrid] = 0;
		}
	}

#if 0
	clues[0][1] = 7;
	clues[0][2] = 1;
	clues[0][4] = 9;
	clues[0][6] = 8;
	
	clues[1][3] = 3;
	clues[1][5] = 6;

	clues[2][0] = 4;
	clues[2][1] = 9;
	clues[2][6] = 7;
	clues[2][8] = 5;

	clues[3][1] = 1;
	clues[3][3] = 9;

	clues[4][0] = 9;
	clues[4][2] = 2;
	clues[4][6] = 6;
	clues[4][8] = 3;

	clues[5][5] = 8;
	clues[5][7] = 2;

	clues[6][0] = 8;
	clues[6][2] = 5;
	clues[6][7] = 7;
	clues[6][8] = 6;

	clues[7][3] = 6;
	clues[7][5] = 7;

	clues[8][2] = 7;
	clues[8][4] = 4;
	clues[8][6] = 3;
	clues[8][7] = 5;
#endif
	clues[0][1] = 7;
	clues[0][2] = 5;
	clues[0][4] = 9;
	clues[0][8] = 6;

	clues[1][1] = 2;
	clues[1][2] = 3;
	clues[1][4] = 8;
	clues[1][7] = 4;
	
	clues[2][0] = 8;
	clues[2][5] = 3;
	clues[2][8] = 1;

	clues[3][0] = 5;
	clues[3][3] = 7;
	clues[3][5] = 2;

	clues[4][1] = 4;
	clues[4][3] = 8;
	clues[4][5] = 6;
	clues[4][7] = 2;

	clues[5][3] = 9;
	clues[5][5] = 1;
	clues[5][8] = 3;

	clues[6][0] = 9;
	clues[6][3] = 4;
	clues[6][8] = 7;

	clues[7][1] = 6;
	clues[7][4] = 7;
	clues[7][6] = 5;
	clues[7][7] = 8;

	clues[8][0] = 7;
	clues[8][4] = 1;
	clues[8][6] = 3; 
	clues[8][7] = 9;




	Sudoku sudoku(clues);
	sudoku.solve();
			
    return 0;
}

