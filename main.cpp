/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskPlayAgain();

FBullCowGame BCGame; // instantiate a new game, which we re-use across plays

// the entry point for our application
int main()
{
	do {
		PrintIntro();
		PlayGame();
	} 
	while (AskPlayAgain() == true);
	return 0; //exit application
}


void PrintIntro()
{
	std::cout << "\nWelcome to Bulls and Cows, a fun word game.\n\n";
	std::cout << "____--------_______________________--------____\n";
	std::cout << "MOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!\n";
	std::cout << "----________-----------------------________----\n\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// plays a single game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game 
	// is NOT won and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetValidGuess();

		// submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTries = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTries << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";

		std::getline(std::cin, Guess);

		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (no repeating letters).\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please use all lowercase letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "You won the game, congratulatious!\n";
	}
	else {
		std::cout << "Sorry, you lose!\n";
	}
}

bool AskPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return 	Response[0] == 'y' || Response[0] == 'Y';
}
