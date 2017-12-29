/*
	Battleships.cpp
	Program to play battleships
	By: Humberto Gonzalez Sanchez, Gabriela Escarcega Salinas
	v. 1.0
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
refreshBoard
Refreshes the board
parameters: none
returns: 0
*/
void refreshBoard()
{
	cout << string(80, '\n');
}

/*
yourTurn
Displays big message that announces your turn
parameters: none
returns: 0
*/
void yourTurn()
{
	cout << "##    ##  #######  ##     ## ########     ######## ##     ## ########  ##    ## ####" << endl;
	cout << " ##  ##  ##     ## ##     ## ##     ##       ##    ##     ## ##     ## ###   ## ####" << endl;
	cout << "  ####   ##     ## ##     ## ##     ##       ##    ##     ## ##     ## ####  ## ####" << endl;
	cout << "   ##    ##     ## ##     ## ########        ##    ##     ## ########  ## ## ##  ## " << endl;
	cout << "   ##    ##     ## ##     ## ##   ##         ##    ##     ## ##   ##   ##  ####     " << endl;
	cout << "   ##    ##     ## ##     ## ##    ##        ##    ##     ## ##    ##  ##   ### ####" << endl;
	cout << "   ##     #######   #######  ##     ##       ##     #######  ##     ## ##    ## ####" << endl << endl;

	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.sync();
	cin.get();
}

/*
CPUTurn
Displays big message that announces computer's turn
parameters: none
returns: 0
*/
void CPUTurn()
{
	cout << "##     ## ##    ##    ######## ##     ## ########  ##    ## ####" << endl;
	cout << "###   ###  ##  ##        ##    ##     ## ##     ## ###   ## ####" << endl;
	cout << "#### ####   ####         ##    ##     ## ##     ## ####  ## ####" << endl;
	cout << "## ### ##    ##          ##    ##     ## ########  ## ## ##  ## " << endl;
	cout << "##     ##    ##          ##    ##     ## ##   ##   ##  ####     " << endl;
	cout << "##     ##    ##          ##    ##     ## ##    ##  ##   ### ####" << endl;
	cout << "##     ##    ##          ##     #######  ##     ## ##    ## ####" << endl;

	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.sync();
	cin.get();
}

/*
drawMyBoard
Displays the board to the player
parameters: int iArrMyBoard[22][22], string sUserName, string sEnemyName, int iArrCPU[22][22]
returns: 0
*/
void drawMyBoard(int iArrMyBoard[22][22], string sUserName, string sEnemyName, int iArrCPU[22][22])
{
    char cHLine = '-';
	char cVLine = '|';

    refreshBoard();

    cout << " " << sUserName << "'s Board" << string(32, 32) << sEnemyName << "'s Board" << endl << endl;

    for (int iRows = 0; iRows < 22; iRows++)
	{
		for (int iColumns = 0; iColumns < 22; iColumns++) // Draw Player's board
		{
			char cLetter = 64 + iColumns / 2;

			if (iArrMyBoard[iRows][iColumns] == 0)
			{
				cout << setw(2) << " ";
			}
			else if (iArrMyBoard[iRows][iColumns] == 1)
			{
				cout << setw(2) << "X";
			}
			else if (iArrMyBoard[iRows][iColumns] == 2)
			{
				cout << setw(2) << cLetter;
			}
			else if (iArrMyBoard[iRows][iColumns] == 3)
			{
				cout << setw(2) << (iRows / 2);
			}
			else if (iArrMyBoard[iRows][iColumns] == 4)
			{
				cout << setw(2) << cHLine;
			}
			else if (iArrMyBoard[iRows][iColumns] == 5)
			{
				cout << setw(2) << cVLine;
			}
			else if (iArrMyBoard[iRows][iColumns] == 6)
			{
				cout << setw(2) << "C";
			}
			else if (iArrMyBoard[iRows][iColumns] == 7)
			{
				cout << setw(2) << "B";
			}
			else if (iArrMyBoard[iRows][iColumns] == 8)
			{
				cout << setw(2) << "U";
			}
			else if (iArrMyBoard[iRows][iColumns] == 9)
			{
				cout << setw(2) << "S";
			}
			else if (iArrMyBoard[iRows][iColumns] == 10)
			{
				cout << setw(2) << "D";
			}
		}
		cout << setw(2) << " ";

		// Draw CPU Board
		for (int iColumns = 0; iColumns < 22; iColumns++) // Draw Computer's board
		{
			char cLetter = 64 + iColumns / 2;

			if (iArrCPU[iRows][iColumns] == 0)
			{
				cout << setw(2) << " ";
			}
			else if (iArrCPU[iRows][iColumns] == 1)
			{
				cout << setw(2) << "X";
			}
			else if (iArrCPU[iRows][iColumns] == 2)
			{
				cout << setw(2) << cLetter;
			}
			else if (iArrCPU[iRows][iColumns] == 3)
			{
				cout << setw(2) << (iRows / 2);
			}
			else if (iArrCPU[iRows][iColumns] == 4)
			{
				cout << setw(2) << cHLine;
			}
			else if (iArrCPU[iRows][iColumns] == 5)
			{
				cout << setw(2) << cVLine;
			}
			else if (iArrCPU[iRows][iColumns] == 6) // Carrier
			{
				cout << setw(2) << " ";
			}
			else if (iArrCPU[iRows][iColumns] == 7) // Battleship
			{
				cout << setw(2) << " ";
			}
			else if (iArrCPU[iRows][iColumns] == 8) // Cruiser
			{
				cout << setw(2) << " ";
			}
			else if (iArrCPU[iRows][iColumns] == 9) // Submarine
			{
				cout << setw(2) << " ";
			}
			else if (iArrCPU[iRows][iColumns] == 10) // Destroyer
			{
				cout << setw(2) << " ";
			}
			else if (iArrCPU[iRows][iColumns] == 11) // Missed shot
			{
				cout << setw(2) << "O";
			}
		}
		cout << endl;
	}
}

/*
helloUser
Starts the game asking for player's name and his enemy's
parameters: string &sUserName, string &sEnemyName
returns: 0
*/
void helloUser(string &sUserName, string &sEnemyName)
{
	refreshBoard();

	cout << "Welcome to the Navy" << endl;
	cin.get();
	refreshBoard();

	cout << "What's your name?" << endl;
	cin >> sUserName;
	refreshBoard();

	cout << "Ok, what's your enemy's name?" << endl;
	cin >> sEnemyName;
	refreshBoard();

	cout << endl << "Cooler name than yours..." << endl;
	cin.clear();
	cin.sync();
	cin.get();
	refreshBoard();

	cout << "Anyway, let's begin!" << endl;
	cin.clear();
	cin.sync();
	cin.get();
}

/*
setBoard
Initializes the player's empty board
parameters: int iArrMyBoard[22][22]
return: 0
*/
void setBoard(int iArrMyBoard[22][22])
{

	for (int iRows = 0; iRows < 22; iRows++)
	{
		for (int iColumns = 0; iColumns < 22; iColumns++)
		{
			if (iRows == 0 && iColumns == 0)
			{
				iArrMyBoard[iRows][iColumns] = 0;
			}
			else if (iRows == 0 && iColumns % 2 == 0)
			{
				iArrMyBoard[iRows][iColumns] = 2;
			}
			else if (iColumns == 0 && iRows % 2 == 0)
			{
				iArrMyBoard[iRows][iColumns] = 3;
			}
			else if (iRows % 2 != 0 && iColumns != 0)
			{
				iArrMyBoard[iRows][iColumns] = 4;
			}
			else if (iColumns % 2 != 0 && iRows != 0)
			{
				iArrMyBoard[iRows][iColumns] = 5;
			}
			else
			{
				iArrMyBoard[iRows][iColumns] = 0;
			}
		}
	}
}

/*
setCPUBoard
Initializes the computer's board with random ship placement
parameters: int iArrCPU[22][22]
returns:
*/
void setCPUBoard(int iArrCPU[22][22])
{
	// Set Empty board
	for (int iRows = 0; iRows < 22; iRows++)
	{
		for (int iColumns = 0; iColumns < 22; iColumns++)
		{
			if (iRows == 0 && iColumns == 0)
			{
				iArrCPU[iRows][iColumns] = 0;
			}
			else if (iRows == 0 && iColumns % 2 == 0)
			{
				iArrCPU[iRows][iColumns] = 2;
			}
			else if (iColumns == 0 && iRows % 2 == 0)
			{
				iArrCPU[iRows][iColumns] = 3;
			}
			else if (iRows % 2 != 0 && iColumns != 0)
			{
				iArrCPU[iRows][iColumns] = 4;
			}
			else if (iColumns % 2 != 0 && iRows != 0)
			{
				iArrCPU[iRows][iColumns] = 5;
			}
			else
			{
				iArrCPU[iRows][iColumns] = 0;
			}
		}
	}

	int iCount = 0;
	while (iCount < 5)
	{
		int iCPURow = (rand() % 10 + 1) * 2;
		int iCPUColumn = (rand()% 10 + 1) * 2;
		int iCPUOrient = rand() % 10 + 1;

		if (iCount == 0)
		{
			if (iCPUOrient >= 1 && iCPUOrient <= 5)
			{
				if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow + 2][iCPUColumn] == 0 && iArrCPU[iCPURow + 4][iCPUColumn] == 0 && iArrCPU[iCPURow + 6][iCPUColumn] == 0 && iArrCPU[iCPURow + 8][iCPUColumn] == 0)
				{
					for (int iNum = 0; iNum < 5; iNum++)
					{
						iArrCPU[iCPURow + iNum * 2][iCPUColumn] = 6;
					}
					iCount++;
				}
			}
			else if (iCPUOrient >= 6 && iCPUOrient <= 10)
			{
				if (iCPUColumn < 14)
				{
					if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow][iCPUColumn + 2] == 0 && iArrCPU[iCPURow][iCPUColumn + 4] == 0 && iArrCPU[iCPURow][iCPUColumn + 6] == 0 && iArrCPU[iCPURow][iCPUColumn + 8] == 0)
					{
						for (int iNum = 0; iNum < 5; iNum++)
						{
							iArrCPU[iCPURow][iCPUColumn + iNum * 2] = 6;
						}
						iCount++;
					}
				}
			}
		}
		else if (iCount == 1)
		{
			if (iCPUOrient >= 1 && iCPUOrient <= 5)
			{
				if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow + 2][iCPUColumn] == 0 && iArrCPU[iCPURow + 4][iCPUColumn] == 0 && iArrCPU[iCPURow + 6][iCPUColumn] == 0)
				{
					for (int iNum = 0; iNum < 4; iNum++)
					{
						iArrCPU[iCPURow + iNum * 2][iCPUColumn] = 7;
					}
					iCount++;
				}
			}
			else if (iCPUOrient >= 6 && iCPUOrient <= 10)
			{
				if (iCPUColumn < 16)
				{
					if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow][iCPUColumn + 2] == 0 && iArrCPU[iCPURow][iCPUColumn + 4] == 0 && iArrCPU[iCPURow][iCPUColumn + 6] == 0)
					{
						for (int iNum = 0; iNum < 4; iNum++)
						{
							iArrCPU[iCPURow][iCPUColumn + iNum * 2] = 7;
						}
						iCount++;
					}
				}
			}
		}
		else if (iCount == 2)
		{
			if (iCPUOrient >= 1 && iCPUOrient <= 5)
			{
				if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow + 2][iCPUColumn] == 0 && iArrCPU[iCPURow + 4][iCPUColumn] == 0)
				{
					for (int iNum = 0; iNum < 3; iNum++)
					{
						iArrCPU[iCPURow + iNum * 2][iCPUColumn] = 8;
					}
					iCount++;
				}
			}
			else if (iCPUOrient >= 6 && iCPUOrient <= 10)
			{
				if (iCPUColumn < 18)
				{
					if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow][iCPUColumn + 2] == 0 && iArrCPU[iCPURow][iCPUColumn + 4] == 0)
					{
						for (int iNum = 0; iNum < 3; iNum++)
						{
							iArrCPU[iCPURow][iCPUColumn + iNum * 2] = 8;
						}
						iCount++;
					}
				}
			}
		}
		else if (iCount == 3)
		{
			if (iCPUOrient >= 1 && iCPUOrient <= 5)
			{
				if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow + 2][iCPUColumn] == 0 && iArrCPU[iCPURow + 4][iCPUColumn] == 0)
				{
					for (int iNum = 0; iNum < 3; iNum++)
					{
						iArrCPU[iCPURow + iNum * 2][iCPUColumn] = 9;
					}
					iCount++;
				}
			}
			else if (iCPUOrient >= 6 && iCPUOrient <= 10)
			{
				if (iCPUColumn < 18)
				{
					if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow][iCPUColumn + 2] == 0 && iArrCPU[iCPURow][iCPUColumn + 4] == 0)
					{
						for (int iNum = 0; iNum < 3; iNum++)
						{
							iArrCPU[iCPURow][iCPUColumn + iNum * 2] = 9;
						}
						iCount++;
					}
				}
			}
		}
		else if (iCount == 4)
		{
			if (iCPUOrient >= 1 && iCPUOrient <= 5)
			{
				if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow + 2][iCPUColumn] == 0)
				{
					for (int iNum = 0; iNum < 2; iNum++)
					{
						iArrCPU[iCPURow + iNum * 2][iCPUColumn] = 10;
					}
					iCount++;
				}
			}
			else if (iCPUOrient >= 6 && iCPUOrient <= 10)
			{
				if (iCPUColumn < 20)
				{
					if (iArrCPU[iCPURow][iCPUColumn] == 0 && iArrCPU[iCPURow][iCPUColumn + 2] == 0)
					{
						for (int iNum = 0; iNum < 2; iNum++)
						{
							iArrCPU[iCPURow][iCPUColumn + iNum * 2] = 10;
						}
						iCount++;
					}
				}
			}
		}
	}
}

/*
placeShips
Lets the player place his 5 ships
parameters: string sUserName, int iArrMyBoard[22][22], string sEnemyName, int iArrCPU[22][22]
returns: 0
*/
void placeShips(string sUserName, int iArrMyBoard[22][22], string sEnemyName, int iArrCPU[22][22])
{
	cout << "Ok " << sUserName << ", let's place your ships" << endl;

	int iCarrierNum = 0, iBattleshipNum = 0, iCruiserNum = 0, iSubmarineNum = 0, iDestroyerNum = 0;
	int iShipTotal = 5, iShipNum = 0, iShipsLeft = 5;;
	string sType, sCoordinate, sOrientation;

	while (iShipNum < iShipTotal)
	{
		refreshBoard();
		drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU);

		iShipsLeft = iShipTotal - iShipNum;

		cout << "You have " << iShipsLeft << " ships left to place:" << endl;

		if (iCarrierNum != 1)
		{
			cout << "Carrier 5 cells long";
			if (iShipsLeft != 1)
			{
				cout << ", ";
			}
		}
		if (iBattleshipNum != 1)
		{
			cout << "Battleship 4 cells long";
			if (iShipsLeft != 1)
			{
				if (iShipsLeft > 2 || iCarrierNum == 1)
				{
					cout << ", ";
				}
			}
		}
		if (iCruiserNum != 1)
		{
			cout << "Cruiser 3 cells long";
			if (iShipsLeft != 1)
			{
				if (iShipsLeft > 3 || (iCarrierNum == 1 && iBattleshipNum == 1) || (iCarrierNum == 1 && iShipsLeft != 2) || (iBattleshipNum == 1 && iShipsLeft !=2))
				{
					cout << ", ";
				}
			}
		}
		if (iSubmarineNum != 1)
		{
			cout << "Submarine 3 cells long";
			if (iShipsLeft != 1)
			{
				if (iShipsLeft == 2)
				{
					if  (iCarrierNum == 1 && iBattleshipNum == 1 && iCruiserNum == 1)
					{
						cout << ", ";
					}
				}
				else if (iShipsLeft == 3)
				{
					if ((iCarrierNum == 1 && (iBattleshipNum == 1 || iCruiserNum == 1)) || (iBattleshipNum == 1 && iCruiserNum == 1))
					{
						cout << ", ";
					}
				}
				else if (iShipsLeft > 4 || iCarrierNum == 1 || iBattleshipNum == 1 || iCruiserNum == 1)
				{
					cout << ", ";
				}
			}
		}
		if (iDestroyerNum != 1)
		{
			cout << "Destroyer 2 cells long";
		}
		cout << "." << endl << endl;

		//cout << "Carrier 5 cells long, Battleship 4 cells long, Cruiser 3 cells long, Submarine 3 cells long, Destroyer 2 cells long." << endl << endl;
		cout << "Enter the type of ship, the coordinate to place it and the orientation (h for horizontal, v for vertical)" << endl;
		cout << "i.e: " << "Destroyer A1 v" << endl;

		cin >> sType >> sCoordinate >> sOrientation;

		int iColumn, iRow;
		bool bGoodCoord;
		// Check for Valid Coordinates
		// Valid row
		if (sCoordinate.length() == 2 && sCoordinate[1] <= 57 && sCoordinate[1] >= 49)
		{
			iRow = (sCoordinate[1] - 48) * 2;
			bGoodCoord = true;
		}
		else if (sCoordinate.length() == 3 && sCoordinate[1] == '1' && sCoordinate[2] == '0')
		{
			iRow = 10 * 2;
			bGoodCoord = true;
		}
		else
		{
			cout << "Invalid Coordinates..." << endl;
			bGoodCoord = false;
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
		}
		// Valid column
		if (bGoodCoord == true && sCoordinate[0] <= 74 && sCoordinate[0] >= 65)
		{
			iColumn = (sCoordinate[0] - 64) * 2;
			bGoodCoord = true;
		}
		else
		{
			cout << "Invalid Coordinates..." << endl;
			bGoodCoord = false;
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
		}

		if (sOrientation.length() != 1)
		{
			cout << "Invalid Orientation..." << endl;
			bGoodCoord = false;
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
		}
		else if ((sOrientation == "h")|| (sOrientation == "v"))
		{
			bGoodCoord = true;
		}
		else
		{
			cout << "Invalid Orientation..." << endl;
			cout << sOrientation << endl;
			bGoodCoord = false;
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
		}

		if (bGoodCoord == true)
		{
			int iCount;
			bool bNotOccupied;

			if (sType == "Carrier")
			{
				if (iCarrierNum != 0)
				{
					cout << "You've already placed that ship" << endl;
					cout << "Press enter to continue..." << endl;
					cin.clear();
					cin.sync();
					cin.get();
				}
				else
				{
					if (sOrientation ==  "v")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow + 2][iColumn] == 0 && iArrMyBoard[iRow + 4][iColumn] == 0 && iArrMyBoard[iRow + 6][iColumn] == 0 && iArrMyBoard[iRow + 8][iColumn] == 0)
						{
							for (int iCount = 0; iCount < 5; iCount++)
							{
								iArrMyBoard[iRow + iCount * 2][iColumn] = 6;
							}
							iCarrierNum = 1;
						}
						else
						{
							cout << "That space is already occupied" << endl;
							iCarrierNum = 0;
							bNotOccupied = false;
							cout << "Press enter to continue..." << endl;
							cin.clear();
							cin.sync();
							cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
					else if (sOrientation == "h")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iColumn < 14)
						{
							if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow][iColumn + 2] == 0 && iArrMyBoard[iRow][iColumn + 4] == 0 && iArrMyBoard[iRow][iColumn + 6] == 0 && iArrMyBoard[iRow][iColumn + 8] == 0)
							{
								for (int iCount = 0; iCount < 5; iCount++)
								{
									iArrMyBoard[iRow][iColumn + iCount * 2] = 6;
								}
								iCarrierNum = 1;
							}
						}
						else
						{
								cout << "That space is already occupied" << endl;
								iCarrierNum = 0;
								bNotOccupied = false;
								cout << "Press enter to continue..." << endl;
								cin.clear();
								cin.sync();
								cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
				}
			}
			else if (sType == "Battleship")
			{
				if (iBattleshipNum != 0)
				{
					cout << "You've already placed that ship." << endl;
					cout << "Press enter to continue..." << endl;
					cin.clear();
					cin.sync();
					cin.get();
				}
				else
				{
					if (sOrientation ==  "v")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow + 2][iColumn] == 0 && iArrMyBoard[iRow + 4][iColumn] == 0 && iArrMyBoard[iRow + 6][iColumn] == 0)
						{
							for (int iCount = 0; iCount < 4; iCount++)
							{
								iArrMyBoard[iRow + iCount * 2][iColumn] = 7;
							}
							iBattleshipNum = 1;
						}
						else
						{
							cout << "That space is already occupied" << endl;
							iBattleshipNum = 0;
							bNotOccupied = false;
							cout << "Press enter to continue..." << endl;
							cin.clear();
							cin.sync();
							cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
					else if (sOrientation == "h")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iColumn < 16)
						{
							if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow][iColumn + 2] == 0 && iArrMyBoard[iRow][iColumn + 4] == 0 && iArrMyBoard[iRow][iColumn + 6] == 0)
							{
								for (int iCount = 0; iCount < 4; iCount++)
								{
									iArrMyBoard[iRow][iColumn + iCount * 2] = 7;
								}
								iBattleshipNum = 1;
							}
						}
						else
						{
								cout << "That space is already occupied" << endl;
								iBattleshipNum = 0;
								bNotOccupied = false;
								cout << "Press enter to continue..." << endl;
								cin.clear();
								cin.sync();
								cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
				}
			}
			else if (sType == "Cruiser")
			{
				if (iCruiserNum != 0)
				{
					cout << "You've already placed that ship" << endl;
					cout << "Press enter to continue..." << endl;
					cin.clear();
					cin.sync();
					cin.get();
				}
				else
				{
					if (sOrientation ==  "v")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow + 2][iColumn] == 0 && iArrMyBoard[iRow + 4][iColumn] == 0)
						{
							for (int iCount = 0; iCount < 3; iCount++)
							{
								iArrMyBoard[iRow + iCount * 2][iColumn] = 8;
							}
							iCruiserNum = 1;
						}
						else
						{
							cout << "That space is already occupied" << endl;
							iCruiserNum = 0;
							bNotOccupied = false;
							cout << "Press enter to continue..." << endl;
							cin.clear();
							cin.sync();
							cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
					else if (sOrientation == "h")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iColumn < 18)
						{
							if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow][iColumn + 2] == 0 && iArrMyBoard[iRow][iColumn + 4] == 0)
							{
								for (int iCount = 0; iCount < 3; iCount++)
								{
									iArrMyBoard[iRow][iColumn + iCount * 2] = 8;
								}
								iCruiserNum = 1;
							}
						}
						else
						{
								cout << "That space is already occupied" << endl;
								iCruiserNum = 0;
								bNotOccupied = false;
								cout << "Press enter to continue..." << endl;
								cin.clear();
								cin.sync();
								cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
				}
			}
			else if (sType == "Submarine")
			{
				if (iSubmarineNum != 0)
				{
					cout << "You've already placed that ship" << endl;
					cout << "Press enter to continue..." << endl;
					cin.clear();
					cin.sync();
					cin.get();
				}
				else
				{
					if (sOrientation ==  "v")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow + 2][iColumn] == 0 && iArrMyBoard[iRow + 4][iColumn] == 0)
						{
							for (int iCount = 0; iCount < 3; iCount++)
							{
								iArrMyBoard[iRow + iCount * 2][iColumn] = 9;
							}
							iSubmarineNum = 1;
						}
						else
						{
							cout << "That space is already occupied" << endl;
							iSubmarineNum = 0;
							bNotOccupied = false;
							cout << "Press enter to continue..." << endl;
							cin.clear();
							cin.sync();
							cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
					else if (sOrientation == "h")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iColumn < 18)
						{
							if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow][iColumn + 2] == 0 && iArrMyBoard[iRow][iColumn + 4] == 0)
							{
								for (int iCount = 0; iCount < 3; iCount++)
								{
									iArrMyBoard[iRow][iColumn + iCount * 2] = 9;
								}
								iSubmarineNum = 1;
							}
						}
						else
						{
								cout << "That space is already occupied" << endl;
								iSubmarineNum= 0;
								bNotOccupied = false;
								cout << "Press enter to continue..." << endl;
								cin.clear();
								cin.sync();
								cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
				}
			}
			else if (sType == "Destroyer")
			{
				if (iDestroyerNum != 0)
				{
					cout << "You've already placed that ship" << endl;
					cout << "Press enter to continue..." << endl;
					cin.clear();
					cin.sync();
					cin.get();
				}
				else
				{
					if (sOrientation ==  "v")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow + 2][iColumn] == 0)
						{
							for (int iCount = 0; iCount < 2; iCount++)
							{
								iArrMyBoard[iRow + iCount * 2][iColumn] = 10;
							}
							iDestroyerNum = 1;
						}
						else
						{
							cout << "That space is already occupied" << endl;
							iDestroyerNum = 0;
							bNotOccupied = false;
							cout << "Press enter to continue..." << endl;
							cin.clear();
							cin.sync();
							cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
					else if (sOrientation == "h")
					{
						iCount = 0;
						bNotOccupied = true;
						if (iColumn < 20)
						{
							if (iArrMyBoard[iRow][iColumn] == 0 && iArrMyBoard[iRow][iColumn + 2] == 0)
							{
								for (int iCount = 0; iCount < 2; iCount++)
								{
									iArrMyBoard[iRow][iColumn + iCount * 2] = 10;
								}
								iDestroyerNum = 1;
							}
						}
						else
						{
								cout << "That space is already occupied" << endl;
								iDestroyerNum = 0;
								bNotOccupied = false;
								cout << "Press enter to continue..." << endl;
								cin.clear();
								cin.sync();
								cin.get();
						}

						if (bNotOccupied == true)
						{
							iShipNum++;
						}
					}
				}
			}
			else
			{
				cout << "Invalid ship type" << endl;
				cout << "Press enter to continue..." << endl;
				cin.clear();
				cin.sync();
				cin.get();
			}
		}
	}

	refreshBoard();
	drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU);

	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.sync();
	cin.get();
}

/*
giveCoord
Lets the player give a coord and check if hits
parameters: int iArrCPU[22][22], bool &bWin
returns: 0
*/
void giveCoord(int iArrCPU[22][22], bool &bWin)
{
	int iCoordRow, iCoordColumn;
	string sInput;
	bool bGoodCoord;
	cout << "Enter a Coordinate." << endl;
	cin >> sInput;

	// Check for Valid Coordinates
	if (sInput.length() == 2 && sInput[1] <= 57 && sInput[1] >= 49)
	{
		iCoordRow = (sInput[1] - 48) * 2;
		bGoodCoord = true;
	}
	else if (sInput.length() == 3 && sInput[1] == '1' && sInput[2] == '0')
	{
		iCoordRow = 10 * 2;
		bGoodCoord = true;
	}
	else
	{
		cout << "Invalid Coordinates..." << endl;
		bGoodCoord = false;
		cout << "Press enter to continue..." << endl;
		cin.clear();
		cin.sync();
		cin.get();
	}
	// Valid column
	if (bGoodCoord == true && sInput[0] <= 74 && sInput[0] >= 65)
	{
		iCoordColumn = (sInput[0] - 64) * 2;
		bGoodCoord = true;
	}
	else
	{
		cout << "Invalid Coordinates..." << endl;
		bGoodCoord = false;
		cout << "Press enter to continue..." << endl;
		cin.clear();
		cin.sync();
		cin.get();
	}

	if (bGoodCoord == true) // If the program received a valid coordinate
	{
		bool bNotSunk = false;
		switch (iArrCPU[iCoordRow][iCoordColumn])
		{
			case 6:
					{
						iArrCPU[iCoordRow][iCoordColumn] = 1;
						for (int iRow = 0; iRow < 22; iRow++)
						{
							for (int iColumn = 0; iColumn < 22; iColumn++)
							{
								if (iArrCPU[iRow][iColumn] == 6)
								{
									bNotSunk = true;
								}
							}
						}
						if (bNotSunk == true)
						{
							cout << "That's a Hit!" << endl;
						}
						else
						{
							cout << "Hit and Sunk!" << endl;
						}
						cout << "Press enter to continue..." << endl;
						cin.clear();
						cin.sync();
						cin.get();
						break;
					}
			case 7:
					{
						iArrCPU[iCoordRow][iCoordColumn] = 1;
						for (int iRow = 0; iRow < 22; iRow++)
						{
							for (int iColumn = 0; iColumn < 22; iColumn++)
							{
								if (iArrCPU[iRow][iColumn] == 7)
								{
									bNotSunk = true;
								}
							}
						}
						if (bNotSunk == true)
						{
							cout << "That's a Hit!" << endl;
						}
						else
						{
							cout << "Hit and Sunk!" << endl;
						}
						cout << "Press enter to continue..." << endl;
						cin.clear();
						cin.sync();
						cin.get();
						break;
					}
			case 8:
					{
						iArrCPU[iCoordRow][iCoordColumn] = 1;
						for (int iRow = 0; iRow < 22; iRow++)
						{
							for (int iColumn = 0; iColumn < 22; iColumn++)
							{
								if (iArrCPU[iRow][iColumn] == 8)
								{
									bNotSunk = true;
								}
							}
						}
						if (bNotSunk == true)
						{
							cout << "That's a Hit!" << endl;
						}
						else
						{
							cout << "Hit and Sunk!" << endl;
						}
						cout << "Press enter to continue..." << endl;
						cin.clear();
						cin.sync();
						cin.get();
						break;
					}
			case 9:
					{
						iArrCPU[iCoordRow][iCoordColumn] = 1;
						for (int iRow = 0; iRow < 22; iRow++)
						{
							for (int iColumn = 0; iColumn < 22; iColumn++)
							{
								if (iArrCPU[iRow][iColumn] == 9)
								{
									bNotSunk = true;
								}
							}
						}
						if (bNotSunk == true)
						{
							cout << "That's a Hit!" << endl;
						}
						else
						{
							cout << "Hit and Sunk!" << endl;
						}
						cout << "Press enter to continue..." << endl;
						cin.clear();
						cin.sync();
						cin.get();
						break;
					}
			case 10:
					{
						iArrCPU[iCoordRow][iCoordColumn] = 1;
						for (int iRow = 0; iRow < 22; iRow++)
						{
							for (int iColumn = 0; iColumn < 22; iColumn++)
							{
								if (iArrCPU[iRow][iColumn] == 10)
								{
									bNotSunk = true;
								}
							}
						}
						if (bNotSunk == true)
						{
							cout << "That's a Hit!" << endl;
						}
						else
						{
							cout << "Hit and Sunk!" << endl;
						}
						cout << "Press enter to continue..." << endl;
						cin.clear();
						cin.sync();
						cin.get();
						break;
					}
			default:
					{
						cout << "You Missed!" << endl;
						iArrCPU[iCoordRow][iCoordColumn] = 11; //Missed shot mark
						cout << "Press enter to continue..." << endl;
						cin.clear();
						cin.sync();
						cin.get();
						break;
					}
		}
	}

	int iHitNum = 0;
	for (int iRow = 0; iRow < 22; iRow++)
	{
		for (int iColumn = 0; iColumn < 22; iColumn++)
		{
			if (iArrCPU[iRow][iColumn] == 1)
			{
				iHitNum++;
			}
		}
	}

	if (iHitNum == 17)
	{
		bWin = true;
	}
}

/*
CPUCoord
Lets the computer give a coord and be "smart" if it hits something
parameters: int iArrMyBoard[22][22], string sEnemyName, bool &bOneHit, bool &bFinishHim, int iArrPreviousCoord[10][10], int &iTurn, int &iLastRow, int &iLastColumn, char &cOrientation, bool &bLose, string &sPrevShip
returns: 0
*/
void CPUCoord(int iArrMyBoard[22][22], string sEnemyName, bool &bOneHit, bool &bFinishHim, int iArrPreviousCoord[10][10], int &iTurn, int &iLastRow, int &iLastColumn, char &cOrientation, bool &bLose, string &sPrevShip)
{
	int iCoordRow;
	int iCoordColumn;
	int iRandom;
	bool bRepeated = true;
	if (bOneHit == false && bFinishHim == false)
	{
		while (bRepeated == true)
		{
			iCoordRow =  (rand() % 10 + 1) * 2;
			iCoordColumn = (rand()% 10 + 1) * 2;
			if (iTurn != 0)
			{
				if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
				{
					bRepeated = true;
				}
				else
				{
					bRepeated = false;
				}
			}
			else
			{
				bRepeated = false;
			}
		}
	}
	else if (bOneHit == true && bFinishHim == false)
	{
		bool bValidPlace = false;
		while (bValidPlace == false)
		{
			iRandom = rand() % 4 + 1;

			if (iRandom == 1) // Check above last coord
			{
				if (iLastRow > 2) // Check that last coord isnt the first in the column
				{
					iCoordColumn = iLastColumn;
					iCoordRow = iLastRow - 2;
					bValidPlace = true;
				}
				else
				{
					bValidPlace = false;
				}
			}
			else if (iRandom == 2) // Check below last coord
			{
				if (iLastRow < 20) // Check that last coord isnt the last in the column
				{
					iCoordColumn = iLastColumn;
					iCoordRow = iLastRow + 2;
					bValidPlace = true;
				}
				else
				{
					bValidPlace = false;
				}
			}
			else if (iRandom == 3) // Check to the right of last coord
			{
				if (iLastColumn < 20) // Check that last coord isnt the last in the row
				{
					iCoordColumn = iLastColumn + 2;
					iCoordRow = iLastRow;
					bValidPlace = true;
				}
				else
				{
					bValidPlace = false;
				}
			}
			else if (iRandom == 4) // Check to the left of last coord
			{
				if (iLastColumn > 2) // Check that last coord isnt the first in the row
				{
					iCoordColumn = iLastColumn - 2;
					iCoordRow = iLastRow;
					bValidPlace = true;
				}
				else
				{
					bValidPlace = false;
				}
			}

			if (bValidPlace == true)
			{
				if(iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
				{
					bValidPlace = false;
				}
			}

			if (iLastRow > 2 && iLastRow < 20 && iLastColumn > 2 && iLastColumn < 20)
			{
				bool bNotOut = true;
				int iRand, iLoopNum = 1;
				// Check if last cell is surrounded by previously guessed numbers
				if ((iArrPreviousCoord[(iLastRow / 2 - 1) + 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[(iLastRow / 2 - 1) - 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) + 2] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) - 2] == 1))
				{
					iRand = rand() % 4 + 1;

					switch (iRand)
					{
						case 1:
						{
							while (bNotOut == true)
							{
								if (iLastRow - 2 * iLoopNum >= 2)
								{
									iCoordRow = iLastRow - 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 2:
						{
							while (bNotOut == true)
							{
								if (iLastRow + 2 * iLoopNum <= 20)
								{
									iCoordRow = iLastRow + 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 3:
						{
							while (bNotOut == true)
							{
								if (iLastColumn - 2 * iLoopNum >= 2)
								{
									iCoordColumn = iLastColumn - 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 4:
						{
							while (bNotOut == true)
							{
								if (iLastColumn + 2 * iLoopNum <= 20)
								{
									iCoordColumn = iLastColumn + 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
					}
				}
			}
			else if (iLastRow < 20 && iLastColumn > 2 && iLastColumn < 20)
			{
				bool bNotOut = true;
				int iRand, iLoopNum = 1;
				// Check if last cell is surrounded by previously guessed numbers
				if ((iArrPreviousCoord[(iLastRow / 2 - 1) + 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) + 2] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) - 2] == 1))
				{
					iRand = rand() % 3 + 1;

					switch (iRand)
					{
						case 1:
						{
							while (bNotOut == true)
							{
								if (iLastRow + 2 * iLoopNum <= 20)
								{
									iCoordRow = iLastRow + 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 2:
						{
							while (bNotOut == true)
							{
								if (iLastColumn - 2 * iLoopNum >= 2)
								{
									iCoordColumn = iLastColumn - 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 3:
						{
							while (bNotOut == true)
							{
								if (iLastColumn + 2 * iLoopNum <= 20)
								{
									iCoordColumn = iLastColumn + 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
					}
				}
			}
			else if (iLastRow > 2 && iLastColumn > 2 && iLastColumn < 20)
			{
				bool bNotOut = true;
				int iRand, iLoopNum = 1;
				// Check if last cell is surrounded by previously guessed numbers
				if ((iArrPreviousCoord[(iLastRow / 2 - 1) - 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) + 2] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) - 2] == 1))
				{
					iRand = rand() % 3 + 1;

					switch (iRand)
					{
						case 1:
						{
							while (bNotOut == true)
							{
								if (iLastRow - 2 * iLoopNum >= 2)
								{
									iCoordRow = iLastRow - 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 2:
						{
							while (bNotOut == true)
							{
								if (iLastColumn - 2 * iLoopNum >= 2)
								{
									iCoordColumn = iLastColumn - 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 3:
						{
							while (bNotOut == true)
							{
								if (iLastColumn + 2 * iLoopNum <= 20)
								{
									iCoordColumn = iLastColumn + 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
					}
				}
			}
			else if (iLastRow > 2 && iLastRow < 20 && iLastColumn < 20)
			{
				bool bNotOut = true;
				int iRand, iLoopNum = 1;
				// Check if last cell is surrounded by previously guessed numbers
				if ((iArrPreviousCoord[(iLastRow / 2 - 1) + 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[(iLastRow / 2 - 1) - 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) + 2] == 1))
				{
					iRand = rand() % 3 + 1;

					switch (iRand)
					{
						case 1:
						{
							while (bNotOut == true)
							{
								if (iLastRow - 2 * iLoopNum >= 2)
								{
									iCoordRow = iLastRow - 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 2:
						{
							while (bNotOut == true)
							{
								if (iLastRow + 2 * iLoopNum <= 20)
								{
									iCoordRow = iLastRow + 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 3:
						{
							while (bNotOut == true)
							{
								if (iLastColumn + 2 * iLoopNum <= 20)
								{
									iCoordColumn = iLastColumn + 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
					}
				}
			}
			else if (iLastRow > 2 && iLastRow < 20 && iLastColumn > 2)
			{
				bool bNotOut = true;
				int iRand, iLoopNum = 1;
				// Check if last cell is surrounded by previously guessed numbers
				if ((iArrPreviousCoord[(iLastRow / 2 - 1) + 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[(iLastRow / 2 - 1) - 2][iLastColumn / 2 - 1] == 1) && (iArrPreviousCoord[iLastRow / 2 - 1][(iLastColumn / 2 - 1) - 2] == 1))
				{
					iRand = rand() % 3 + 1;

					switch (iRand)
					{
						case 1:
						{
							while (bNotOut == true)
							{
								if (iLastRow - 2 * iLoopNum >= 2)
								{
									iCoordRow = iLastRow - 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 2:
						{
							while (bNotOut == true)
							{
								if (iLastRow + 2 * iLoopNum <= 20)
								{
									iCoordRow = iLastRow + 2 * iLoopNum;
									iCoordColumn = iLastColumn;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
						case 3:
						{
							while (bNotOut == true)
							{
								if (iLastColumn - 2 * iLoopNum >= 2)
								{
									iCoordColumn = iLastColumn - 2 * iLoopNum;
									iCoordRow = iLastRow;
									if (iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] == 1)
									{
										bNotOut = true;
									}
									else
									{
										bNotOut = false;
									}
								}
								iLoopNum++;
							}
							break;
						}
					}
				}
			}
		}
	}
	else if (bOneHit == true && bFinishHim == true)
	{
		bool bValidCell = false;
		bool bRepeat = true;

		if (cOrientation == 'u')
		{
			if (iLastRow - 2 < 2)
			{
				bRepeat = true;

				iCoordRow = iLastRow + 2;
				iCoordColumn = iLastColumn;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordRow += 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
			else
			{
				iCoordRow = iLastRow - 2;
				iCoordColumn = iLastColumn;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordRow -= 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
		}
		else if (cOrientation == 'd')
		{
			if (iLastRow + 2 > 20)
			{
				bRepeat = true;

				iCoordRow = iLastRow - 2;
				iCoordColumn = iLastColumn;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordRow -= 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
			else
			{
				iCoordRow = iLastRow + 2;
				iCoordColumn = iLastColumn;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordRow += 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
		}
		else if (cOrientation == 'r')
		{
			if (iLastColumn + 2 > 20)
			{
				bRepeat = true;

				iCoordColumn = iLastColumn - 2;
				iCoordRow = iLastRow;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordColumn -= 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
			else
			{
				iCoordColumn = iLastColumn + 2;
				iCoordRow = iLastRow;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordColumn += 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
		}
		else if (cOrientation == 'l')
		{
			if (iLastColumn - 2 < 2)
			{
				bRepeat = true;

				iCoordColumn = iLastColumn + 2;
				iCoordRow = iLastRow;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordColumn += 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
			else
			{
				iCoordColumn = iLastColumn - 2;
				iCoordRow = iLastRow;
				while (bRepeat == true)
				{
					if (iArrMyBoard[iCoordRow][iCoordColumn] == 1)
					{
						iCoordColumn -= 2;
					}
					else
					{
						bRepeat = false;
					}
				}
			}
		}
	}


	char cLetter = (iCoordColumn / 2) + 64;

	cout << sEnemyName << " says: " << cLetter << iCoordRow / 2 << endl;

	bool bNotSunk = false;
	switch (iArrMyBoard[iCoordRow][iCoordColumn]) // Check if it's a hit
	{
		case 6:
		{
			iArrMyBoard[iCoordRow][iCoordColumn] = 1;
			for (int iRow = 0; iRow < 22; iRow++)
			{
				for (int iColumn = 0; iColumn < 22; iColumn++)
				{
					if (iArrMyBoard[iRow][iColumn] == 6)
					{
						bNotSunk = true;
					}
				}
			}
			if (bNotSunk == true)
			{
				cout << "That's a Hit!" << endl;

				if (bOneHit == false)
				{
					bOneHit = true;
				}
				else if (bFinishHim == false)
				{
					bFinishHim = true;
					if (iRandom == 1)
					{
						cOrientation = 'u';
					}
					else if (iRandom == 2)
					{
						cOrientation = 'd';
					}
					else if (iRandom == 3)
					{
						cOrientation = 'r';
					}
					else if (iRandom == 4)
					{
						cOrientation = 'l';
					}
				}

				if (sPrevShip != "Carrier")
				{
					bFinishHim = false;
				}

				iLastRow = iCoordRow;
				iLastColumn = iCoordColumn;
				sPrevShip = "Carrier";

			}
			else
			{
				cout << "Hit and Sunk!" << endl;
				bOneHit = false;
				bFinishHim = false;
			}
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
			break;
		}
		case 7:
		{
			iArrMyBoard[iCoordRow][iCoordColumn] = 1;
			for (int iRow = 0; iRow < 22; iRow++)
			{
				for (int iColumn = 0; iColumn < 22; iColumn++)
				{
					if (iArrMyBoard[iRow][iColumn] == 7)
					{
						bNotSunk = true;
					}
				}
			}
			if (bNotSunk == true)
			{
				cout << "That's a Hit!" << endl;
				if (bOneHit == false)
				{
					bOneHit = true;
				}
				else if (bFinishHim == false)
				{
					bFinishHim = true;
					if (iRandom == 1)
					{
						cOrientation = 'u';
					}
					else if (iRandom == 2)
					{
						cOrientation = 'd';
					}
					else if (iRandom == 3)
					{
						cOrientation = 'r';
					}
					else if (iRandom == 4)
					{
						cOrientation = 'l';
					}
				}

				if (sPrevShip != "Battleship")
				{
					bFinishHim = false;
				}

				iLastRow = iCoordRow;
				iLastColumn = iCoordColumn;
				sPrevShip = "Battleship";
			}
			else
			{
				cout << "Hit and Sunk!" << endl;
				bOneHit = false;
				bFinishHim = false;
			}
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
			break;
			}
		case 8:
		{
			iArrMyBoard[iCoordRow][iCoordColumn] = 1;
			for (int iRow = 0; iRow < 22; iRow++)
			{
				for (int iColumn = 0; iColumn < 22; iColumn++)
				{
					if (iArrMyBoard[iRow][iColumn] == 8)
					{
						bNotSunk = true;
					}
				}
			}
			if (bNotSunk == true)
			{
				cout << "That's a Hit!" << endl;
				if (bOneHit == false)
				{
					bOneHit = true;
				}
				else if (bFinishHim == false)
				{
					bFinishHim = true;
					if (iRandom == 1)
					{
						cOrientation = 'u';
					}
					else if (iRandom == 2)
					{
						cOrientation = 'd';
					}
					else if (iRandom == 3)
					{
						cOrientation = 'r';
					}
					else if (iRandom == 4)
					{
						cOrientation = 'l';
					}
				}

				if (sPrevShip != "Cruiser")
				{
					bFinishHim = false;
				}

				iLastRow = iCoordRow;
				iLastColumn = iCoordColumn;
				sPrevShip = "Cruiser";
			}
			else
			{
				cout << "Hit and Sunk!" << endl;
				bOneHit = false;
				bFinishHim = false;
			}
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
			break;
		}
		case 9:
		{
			iArrMyBoard[iCoordRow][iCoordColumn] = 1;
			for (int iRow = 0; iRow < 22; iRow++)
			{
				for (int iColumn = 0; iColumn < 22; iColumn++)
				{
					if (iArrMyBoard[iRow][iColumn] == 9)
					{
						bNotSunk = true;
					}
				}
			}
			if (bNotSunk == true)
			{
				cout << "That's a Hit!" << endl;
				if (bOneHit == false)
				{
					bOneHit = true;
				}
				else if (bFinishHim == false)
				{
					bFinishHim = true;
					if (iRandom == 1)
					{
						cOrientation = 'u';
					}
					else if (iRandom == 2)
					{
						cOrientation = 'd';
					}
					else if (iRandom == 3)
					{
						cOrientation = 'r';
					}
					else if (iRandom == 4)
					{
						cOrientation = 'l';
					}
				}

				if (sPrevShip != "Submarine")
				{
					bFinishHim = false;
				}

				iLastRow = iCoordRow;
				iLastColumn = iCoordColumn;
				sPrevShip = "Submarine";
			}
			else
			{
				cout << "Hit and Sunk!" << endl;
				bOneHit = false;
				bFinishHim = false;
			}
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
			break;
		}
		case 10:
		{
			iArrMyBoard[iCoordRow][iCoordColumn] = 1;
			for (int iRow = 0; iRow < 22; iRow++)
			{
				for (int iColumn = 0; iColumn < 22; iColumn++)
				{
					if (iArrMyBoard[iRow][iColumn] == 10)
					{
						bNotSunk = true;
					}
				}
			}
			if (bNotSunk == true)
			{
				cout << "That's a Hit!" << endl;
				iLastRow = iCoordRow;
				iLastColumn = iCoordColumn;
				if (bOneHit == false)
				{
					bOneHit = true;
				}
				else if (bFinishHim == false)
				{
					bFinishHim = true;
					if (iRandom == 1)
					{
						cOrientation = 'u';
					}
					else if (iRandom == 2)
					{
						cOrientation = 'd';
					}
					else if (iRandom == 3)
					{
						cOrientation = 'r';
					}
					else if (iRandom == 4)
					{
						cOrientation = 'l';
					}
				}
				if (sPrevShip != "Destroyer")
				{
					bFinishHim = false;
				}

				iLastRow = iCoordRow;
				iLastColumn = iCoordColumn;
				sPrevShip = "Destroyer";
			}
			else
			{
				cout << "Hit and Sunk!" << endl;
				bOneHit = false;
				bFinishHim = false;
			}
			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
			break;
		}
		default:
		{
			cout << sEnemyName << " Missed!" << endl;

			if (cOrientation == 'u')
			{
				cOrientation = 'd';
			}
			else if (cOrientation == 'd')
			{
				cOrientation = 'u';
			}
			else if (cOrientation == 'l')
			{
				cOrientation = 'r';
			}
			else if (cOrientation == 'r')
			{
				cOrientation = 'l';
			}

			cout << "Press enter to continue..." << endl;
			cin.clear();
			cin.sync();
			cin.get();
			break;
		}
	}

	iArrPreviousCoord[iCoordRow / 2 - 1][iCoordColumn / 2 - 1] = 1;
	iTurn++;

	int iHitNum = 0;
	for (int iRow = 0; iRow < 22; iRow++)
	{
		for (int iColumn = 0; iColumn < 22; iColumn++)
		{
			if (iArrMyBoard[iRow][iColumn] == 1)
			{
				iHitNum++;
			}
		}
	}

	if (iHitNum == 17) // Check if Computer won
	{
		bLose = true;
	}
}

/*
victory
Displays victory message to end game
parameters: none
returns: 0
*/
void victory()
{
	refreshBoard();

	cout << " ##    ##  #######  ##     ##    ##      ## #### ##    ## ####  " << endl;
	cout << "  ##  ##  ##     ## ##     ##    ##  ##  ##  ##  ###   ## ####  " << endl;
	cout << "   ####   ##     ## ##     ##    ##  ##  ##  ##  ####  ## ####  " << endl;
	cout << "    ##    ##     ## ##     ##    ##  ##  ##  ##  ## ## ##  ##   " << endl;
	cout << "    ##    ##     ## ##     ##    ##  ##  ##  ##  ##  ####       " << endl;
	cout << "    ##    ##     ## ##     ##    ##  ##  ##  ##  ##   ### ####  " << endl;
	cout << "    ##     #######   #######      ###  ###  #### ##    ## ####  " << endl << endl;

	cout << "Thanks for playing!" << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.sync();
	cin.get();
}


/*
defeat
Displays defeat message to end game
parameters: none
returns: 0
*/
void defeat()
{
	refreshBoard();

	cout << " ##    ##  #######  ##     ##    ##        #######   ######  ######## #### " << endl;
	cout << "  ##  ##  ##     ## ##     ##    ##       ##     ## ##    ## ##       #### " << endl;
	cout << "   ####   ##     ## ##     ##    ##       ##     ## ##       ##       #### " << endl;
	cout << "    ##    ##     ## ##     ##    ##       ##     ##  ######  ######    ##  " << endl;
	cout << "    ##    ##     ## ##     ##    ##       ##     ##       ## ##            " << endl;
	cout << "    ##    ##     ## ##     ##    ##       ##     ## ##    ## ##       #### " << endl;
	cout << "    ##     #######   #######     ########  #######   ######  ######## #### " << endl << endl;

	cout << "Better luck next time!" << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.sync();
	cin.get();
}

/*
playGame
calls the functions that create the interaction in the game
parameters: int iArrMyBoard[22][22], int iArrCPU[22][22], string sUserName, string sEnemyName
returns: 0
*/
void playGame(int iArrMyBoard[22][22], int iArrCPU[22][22], string sUserName, string sEnemyName)
{
	// AI Variables
	bool bOneHit = false;
	bool bFinishHim = false;
	int iArrPreviousCoord[10][10];
	int iTurn = 0, iLastRow, iLastColumn;
	char cOrientation;
	string sPrevShip;

	// Game end conditions
	bool bWin = false, bLose = false;
	while (bWin == false && bLose == false)
	{
		refreshBoard();
		yourTurn();
		refreshBoard();
		drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU);

		giveCoord(iArrCPU, bWin);

		refreshBoard();
		drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU);

		if (bWin == false && bLose == false)
		{
			refreshBoard();
			CPUTurn();
			refreshBoard();
			drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU);

			CPUCoord(iArrMyBoard, sEnemyName, bOneHit, bFinishHim, iArrPreviousCoord, iTurn, iLastRow, iLastColumn, cOrientation, bLose, sPrevShip);

			refreshBoard();
			drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU);
		}
	}

	if (bWin == true)
	{
		victory();
	}
	else if (bLose == true)
	{
		defeat();
	}
}

/*
main
parameters: none
returns: 0
*/
int main()
{
	int iArrMyBoard[22][22], iArrCPU[22][22];
	string sUserName, sEnemyName;
	srand(time(NULL));

	setBoard(iArrMyBoard); // Initialize the default empty board
	setCPUBoard(iArrCPU);	// Intialize the Computer's random board
	helloUser(sUserName, sEnemyName); // Welcome the player
	drawMyBoard(iArrMyBoard, sUserName, sEnemyName, iArrCPU); // Draw the board
	placeShips(sUserName, iArrMyBoard, sEnemyName, iArrCPU); // Let the player place his ships
	playGame(iArrMyBoard, iArrCPU, sUserName, sEnemyName);

	return 0;
}
