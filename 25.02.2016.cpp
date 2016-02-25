#include<iostream>
#include<cmath>
using namespace std;
bool labyrinth[8][8] = {
	1, 0, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 1, 1, 0, 1, 1, 0, 1,
	0, 0, 0, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 1, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 1, 1, 1, 0, 1, 1
};
int endX = 7;
int endY = 7;
bool isWay(int startX, int startY)
{
	if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8)
		return false;
	if (!labyrinth[startX][startY])
		return false;
	if (startX == endX && startY == endY)
		return true;
	labyrinth[startX][startY] = false;
	return isWay(startX + 1, startY) || isWay(startX, startY + 1) || isWay(startX - 1, startY) || isWay(startX, startY - 1);
}
int main()
{
	int vector[8] = { 0 };
	int power = 0;
	for (int i = 0; i < 8; i++, power = 0)
		for (int j = 7; j >= 0; j--)
			vector[i] += labyrinth[i][j] * pow(2, power++);
	for (int i = 0; i < 8; i++)
		cout << vector[i] << " ";

	cout <<boolalpha<< isWay(0, 5)<<"\n";
	system("pause");
	return 0;
}
