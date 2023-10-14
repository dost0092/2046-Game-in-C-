#include<conio.h>
#include<ctime>
#include<iostream>
#include<cmath>

using namespace std;

void moveup(int a[4][4])
{
	int L, R;
	for (int j = 0; j < 4; j++)
	{
		L = 0, R = j;
		for (int i = 1; i < 4; i++)
		{
			if (a[i][j] != 0)
			{
				if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j])
				{
					if (a[L][R] == a[i][j])
					{
						a[L][R] *= 2;
						a[i][j] = 0;
					}
					else if (a[L][R] == 0)
					{
						a[L][R] = a[i][j];
						a[i][j] = 0;
					}
					else
					{
						a[++L][R] = a[i][j];
						a[i][j] = 0;
					}
				}
				else L++;
			}
		}
	}
}

void movedown(int a[4][4])
{
	int L, R;
	for (int j = 0; j < 4; j++)
	{
		L = 3, R = j;
		for (int i = 2; i >= 0; i--)
		{
			if (a[i][j] != 0)
			{
				if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j])
				{
					if (a[L][R] == a[i][j])
					{
						a[L][R] *= 2;
						a[i][j] = 0;
					}
					else if (a[L][R] == 0)
					{
						a[L][R] = a[i][j];
						a[i][j] = 0;
					}
					else
					{
						a[--L][R] = a[i][j];
						a[i][j] = 0;
					}

				}
				else L--;
			}
		}
	}
}

void leftmove(int a[4][4])
{
	int L, R;
	for (int i = 0; i < 4; i++)
	{
		L = i, R = 0;
		for (int j = 1; j < 4; j++)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j])
				{
					if (a[L][R] == a[i][j])
					{
						a[L][R] *= 2;
						a[i][j] = 0;
					}
					else if (a[L][R] == 0)
					{
						a[L][R] = a[i][j];
						a[i][j] = 0;
					}
					else
					{
						a[L][++R] = a[i][j];
						a[i][j] = 0;
					}

				}
				else R++;
			}
		}
	}
}

void rightmove(int a[4][4])
{
	int L, R;
	for (int i = 0; i < 4; i++)
	{
		L = i, R = 3;
		for (int j = 2; j >= 0; j--)
		{
			if (a[i][j] != 0)

			{
				if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j])
				{
					if (a[L][R] == a[i][j])
					{
						a[L][R] *= 2;
						a[i][j] = 0;
					}
					else if (a[L][R] == 0)
					{
						a[L][R] = a[i][j];
						a[i][j] = 0;
					}
					else
					{
						a[L][--R] = a[i][j];
						a[i][j] = 0;
					}
				}
				else R--;
			}
		}
	}
}

void block(int a[4][4])
{
	int L = 0, R = 0;
	rand();
	while (1)
	{
		L = rand() % 4;
		R = rand() % 4;
		if (a[L][R] == 0)
		{
			a[L][R] = pow(2, L % 3);
			break;
		}
	}

}

void display(int a[4][4])
{
	cout << "\n\n------>Press Esc to quit the game";
	cout << "\n\n\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\t\t\t_________________\n\t\t\t\t";
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0) cout << "|   ";
			else
				cout << "| " << a[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "\t\t\t\t_________________\n";
}

int check(int temp[4][4], int a[4][4])
{
	int x = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (temp[i][j] != a[i][j])
			{
				x = 0;
				break;
			}
	return x;
}




int main()
{

	cout << "\n\t\t*>--------------Let's Play 2048 Game---------------<*" << endl;
	int i1, i2, i3, i4;
	int a[4][4] = { 0 }, temp[4][4] = { 0 };
	srand(time(0));
	i1 = rand() % 4;
	i2 = rand() % 4;
	while (1)
	{
		i3 = rand() % 4;
		i4 = rand() % 4;
		if (i3 != i1 && i4 != i2) break;
	}
	a[i1][i2] = 2;
	a[i3][i4] = 4;
	display(a);

	char ch;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{

			for (int j = 0; j < 4; j++)
				temp[i][j] = a[i][j];
		}
		_getch();
		ch = _getch();
		system("cls");
		if (ch == 72) moveup(a);
		if (ch == 80) movedown(a);
		if (ch == 75) leftmove(a);
		if (ch == 77) rightmove(a);
		if (ch == 27)
			break;

		if (!check(temp, a))
			block(a);
		display(a);

	}
	return 0;
}