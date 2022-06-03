#include<iostream>

using namespace std;

struct player
{
	int score;
	int pos;
};

int main()
{
	struct player winner, runnerup, last, sndlast;
	winner.score = 0;
	runnerup.score = 0;
	last.score = 99999;
	sndlast.score = 99999;

	int size;
	cout << "size: ";
	cin >> size;
	
	int score[size];
	for(int i=0; i<size; i++)
		cin >> score[i];

	for(int i=0; i<size; i++)
	{
		if(score[i] > winner.score)
		{
			runnerup.score = winner.score;
			runnerup.pos = winner.pos;
			winner.score = score[i];
			winner.pos = i;	
		}
		else if(score[i] > runnerup.score)
		{
			runnerup.score = score[i];
			runnerup.pos = i;
		}
		if(score[i] < last.score)
		{
			sndlast.score = last.score;
			sndlast.pos = last.pos;
			last.score = score[i];
			last.pos = i;
		}
		else if(score[i] < sndlast.score && score[i] > last.score)
		{
			sndlast.score = score[i];
			sndlast.pos = i;
		}
	}

	cout << endl;
	cout << "winner: player " << winner.pos + 1 << endl;
	cout << "runnerup: player " << runnerup.pos + 1 << endl;
	cout << "last: player " << last.pos + 1 << endl;
	cout << "second last: player " << sndlast.pos + 1 << endl;
}