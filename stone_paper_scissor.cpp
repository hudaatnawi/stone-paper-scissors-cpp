// stone_paper_scissor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;
enum enWinner
{Player1 = 1 , Computer = 2 , Draw = 3

};
enum enChoice
{Rock = 1, Paper = 2 , Scissor = 3

};
struct stRoundInfo
{
	short roundNumber = 0;
	enChoice player1Choice;
	enChoice computerChoice;
	enWinner roundWinner;
	string roundWinnerName = "";

};
struct stGameInfo
{
	short numberOfRounds = 0;
	short player1WinTimes = 0;
	short computerWinTimes = 0;
	short drawTimes = 0;
	enWinner winner;
	string gameWinnerName = "";
	

};
short randomNumber(short from, short to) {
	short randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
enChoice player1Choice() {
	short choice;
	cout << "What is your choice Rock[1] , Paper[2] , Scissor[3]? ";
	cin >> choice;
	return (enChoice)choice;
}
enChoice getComputerChoice() {
	return (enChoice)randomNumber(1, 3);
}
enWinner whoWonTheRound(stRoundInfo roundInfo) {
	if (roundInfo.player1Choice == roundInfo.computerChoice)
		return enWinner::Draw;
	switch(roundInfo.player1Choice) {
	case Rock: return(roundInfo.computerChoice == Paper) ? enWinner::Computer : enWinner::Player1;
	case Paper: return(roundInfo.computerChoice == Scissor) ? enWinner::Computer : enWinner::Player1;
	case Scissor: return (roundInfo.computerChoice == Rock )? enWinner::Computer : enWinner::Player1;
	}
}
enWinner whoWonTheGame(short player1WinTimes, short computerWinTimes) {
	if (player1WinTimes > computerWinTimes)
		return Player1;
	else if (computerWinTimes > player1WinTimes)
		return Computer;
	else return Draw;
}
string winnerName(enWinner winner) {
	string arrWinnerName[3] = { "Player1" , "Computer" , "Draw" };
	return arrWinnerName[winner - 1];
}
string choice(enChoice choice) {
	string arrChoice[3] = { "Rock", "Paper" , "Scissor" };
	return arrChoice[choice - 1];
}
void printRoundInfo(stRoundInfo roundInfo) {
	cout << "--------------Round [" << roundInfo.roundNumber << "]--------------\n";
	cout << "Player1 Choice: " << choice(roundInfo.player1Choice) << endl;
	cout << "Computer Choice: " << choice(roundInfo.computerChoice) << endl;
	cout << "Round Winner: " << winnerName(roundInfo.roundWinner) << endl;
	cout << "---------------------------------------------------------------------------\n";

}

short howManyRoundsToPlay() {
	short numOfRounds = 3;
	do
	{
		cout << "How many rounds do you want to play from 1 to 10? ";
		cin >> numOfRounds;

	} while (numOfRounds < 1 || numOfRounds > 10);
	return numOfRounds;
}
stGameInfo playGame(short howManyRounds) {
	stRoundInfo roundInfo;
	short player1WinTimes = 0, computerWinTimes = 0, drawTimes = 0;
	for (short roundNumber = 1; roundNumber <= howManyRounds; roundNumber++)
	{
		cout << "------------------------Round [" << roundNumber << "] begins------------------------ \n";
		roundInfo.roundNumber = roundNumber;
		roundInfo.player1Choice = player1Choice();
		roundInfo.computerChoice = getComputerChoice();
		roundInfo.roundWinner = whoWonTheRound(roundInfo);
		roundInfo.roundWinnerName = winnerName(roundInfo.roundWinner);
		if (roundInfo.roundWinner == Player1)
			player1WinTimes++;
		else if (roundInfo.roundWinner == Computer)
			computerWinTimes++;
		else drawTimes++;
		printRoundInfo(roundInfo);
		
	}
	
	return{ howManyRounds,player1WinTimes,computerWinTimes,drawTimes, whoWonTheGame(player1WinTimes, computerWinTimes),winnerName(whoWonTheGame(player1WinTimes,computerWinTimes)) };
}
void printGameInfo(stGameInfo gameInfo) {
	cout <<"Number of rounds:" << gameInfo.numberOfRounds << endl;
	cout << "Game Winner: " << winnerName(gameInfo.winner) << endl<<endl;
}
void startGame() {
	char playAgain = 'y';
	do
	{
		system("cls");
		stGameInfo gameInfo = playGame(howManyRoundsToPlay());
		cout << "-----------------------G A M E  O V E R-----------------------\n";
		printGameInfo(gameInfo);
		cout << "Do you want to play again? [Y/N] ";
		cin >> playAgain;
	} while (playAgain == 'y' || playAgain == 'Y');
}
int main()
{
	srand((unsigned)time(NULL));
	startGame();
	
    
}


