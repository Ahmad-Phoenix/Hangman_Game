// (18) // HangMan Game on February 02/24/2024 | 02/25/2024

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <iomanip>
using namespace std;

enum enContactUserChose
{
	enAnimals = 1,
	enBody,
	enComputer,
	enGarden,
	enProgrammingLanguages
};

enum enNumbersOfWrongQuess
{
	eFirstWrongQuess = 1,
	eSecondWrongQuess,
	eThirdWrongQuess,
	eFourthWrongQuess,
};

struct stQuizzData
{
	vector <string> vAnimals = {
	"Dog",
	"Cat",
	"Elephant",
	"Lion",
	"Tiger",
	"Giraffe",
	"Monkey",
	"Horse",
	"Bear",
	"Wolf",
	"Fox",
	"Kangaroo",
	"Panda",
	"Zebra",
	"Rabbit",
	"Squirrel",
	"Deer",
	"Dolphin",
	"Whale",
	"Shark"
	};
	vector <string> vBodyParts = {
	"Head",
	"Neck",
	"Shoulder",
	"Arm",
	"Elbow",
	"Forearm",
	"Wrist",
	"Hand",
	"Finger",
	"Thumb",
	"Chest",
	"Back",
	"Waist",
	"Hip",
	"Leg",
	"Thigh",
	"Knee",
	"Calf",
	"Ankle",
	"Foot",
	"Toe"
	};
	vector <string> vComputerParts = {
	"CPU",
	"GPU",
	"RAM",
	"Motherboard",
	"Hard Drive",
	"SSD",
	"Power Supply",
	"Case",
	"Fan",
	"Heat Sink",
	"Cooling System",
	"Monitor",
	"Keyboard",
	"Mouse",
	"Speaker",
	"Microphone",
	"Webcam",
	"Ethernet Cable",
	"WiFi Adapter",
	"Graphics Card"
	};
	vector <string> vGardenItems = {
	"Flower",
	"Tree",
	"Shrub",
	"Grass",
	"Vegetable Patch",
	"Herb",
	"Fruit Tree",
	"Garden Gnome",
	"Watering Can",
	"Garden Hose",
	"Patio Furniture",
	"Bird Feeder",
	"Bird Bath",
	"Garden Bench",
	"Fountain",
	"Pergola",
	"Arbor",
	"Garden Lantern",
	"Plant Pot",
	"Trellis"
	};
	vector <string> vProgrammingLanguages = {
		"C",
		"C++",
		"Java",
		"Python",
		"JavaScript",
		"Ruby",
		"Swift",
		"Go",
		"R",
		"SQL",
		"PHP",
		"HTML",
		"CSS",
		"TypeScript",
		"Kotlin",
		"Scala",
		"Perl",
		"Assembly",
		"Lua",
		"MATLAB"
	};
};

struct stGameData
{
	string DashQuizz = "";
	string QuizzFullWord = "";
	char UserInput;
	short WrongGuessCount = 0;
	bool WinnerStatus = false;
	bool RightAnswer = false;
	bool RestGameSettings = false;
	enContactUserChose ContactUserChose;
};

struct stFullData
{
	stQuizzData QuizzData;
	stGameData GameData;
	enContactUserChose ContactUserChose;
};

enContactUserChose ReadContactChose()
{
	short UserInput = 0;

	do
	{
		cout << "| Enter a number ? : ";
		cin >> UserInput;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max());
			cout << "\n\ninvalid Input Try Again, 1 To 5: \n\n";
			continue;
		}

	} while (UserInput < 1 || UserInput > 5);

	return (enContactUserChose)UserInput;
}

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

string PrintHangBase()
{
	string StartBuild = "";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t_|_";

	return StartBuild;
}

string PrintHangRoof()
{
	string StartBuild = "";

	StartBuild += "\t\t  _____\n";
	StartBuild += "\t\t |/\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t_|_";

	return StartBuild;
}

string PrintHangRope()
{
	string StartBuild = "";

	StartBuild += "\t\t  _____\n";
	StartBuild += "\t\t |/   :\n";
	StartBuild += "\t\t |    :\n";
	StartBuild += "\t\t |    :\n";
	StartBuild += "\t\t |    O\n";
	StartBuild += "\t\t |   \\|/\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t_|_";

	return StartBuild;
}

string PrintFullHangMan()
{
	string StartBuild = "";

	StartBuild += "\t\t  _____\n";
	StartBuild += "\t\t |/   :\n";
	StartBuild += "\t\t |    :\n";
	StartBuild += "\t\t |    :\n";
	StartBuild += "\t\t |    O\n";
	StartBuild += "\t\t |   \\|/\n";
	StartBuild += "\t\t |    |\n";
	StartBuild += "\t\t |   / \\ \n";
	StartBuild += "\t\t |\n";
	StartBuild += "\t\t_|_";

	return StartBuild;
}

void RestScreen()
{
	system("cls");
	system("color 0F");
}

void StartBuildHangRope(enNumbersOfWrongQuess FailQuess)
{
	RestScreen();
	switch (FailQuess)
	{
	case enNumbersOfWrongQuess::eFirstWrongQuess:
		cout << PrintHangBase();
		break;
	case enNumbersOfWrongQuess::eSecondWrongQuess:
		cout << PrintHangRoof();
		break;
	case enNumbersOfWrongQuess::eThirdWrongQuess:
		cout << PrintHangRope();
		break;
	case enNumbersOfWrongQuess::eFourthWrongQuess:
		cout << PrintFullHangMan();
		break;
	}
}

char ReadUserInput()
{
	char UserInput;
	string UserInputLength = "";


	cout << "Please Enter one char: ";
	cin >> UserInput;

	return UserInput;
}

void RemoveElementFromVector(vector <char>& vToUpdate, short Index, char ElementToRemove)
{
	vToUpdate.at(Index) -= ElementToRemove;
}

string Repeat(char Digit, short RepeatTimes)
{
	string Ele = "";
	for (short i = 1; i <= RepeatTimes; i++)
	{
		Ele += Digit;
	}
	return Ele;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color E0");
	else
		system("color 4F");
}

string GenerateRandomQuizz(vector <string>& vInput)
{
	short vLength = vInput.size();
	return vInput[RandomNumber(0, vLength - 1)];
}

void FillVectorWithConsonants(vector <char>& vToUpdate)
{
	cout << "\n";

	vector <char> vConsonants =
	{ 'B', 'C', 'D', 'F', 'G', 'H',
	'J', 'K', 'L', 'M', 'N', 'P',
	'Q', 'R', 'S', 'T' ,'V', 'W',
	'X', 'Y' ,'Z', };

	vToUpdate.clear();

	for (char& Cons : vConsonants)
		vToUpdate.push_back(Cons);
}

void ConsonantsOnly(char CharToRemove = ' ', bool Rest = false)
{
	cout << "\n";

	static vector <char> vConsonants =
	{ 'B', 'C', 'D', 'F', 'G', 'H',
	'J', 'K', 'L', 'M', 'N', 'P',
	'Q', 'R', 'S', 'T' ,'V', 'W',
	'X', 'Y' ,'Z', };

	if (Rest)
		return FillVectorWithConsonants(vConsonants);

	short Cols = 0;
	for (short Words = 0; Words < vConsonants.size(); Words++)
	{
		Cols++;
		if (CharToRemove == vConsonants[Words])
			RemoveElementFromVector(vConsonants, Words, vConsonants[Words]);

		cout << "[" << vConsonants[Words] << "] ";

		if (Cols == 3)
		{
			cout << "\n";
			Cols = 0;
		}
	}
}

string AnonymizeIdentity(string Text, char TransTo)
{
	string TransTextTo = "";

	for (int i = 0; i < Text.length(); i++)
		TransTextTo += TransTo;

	return TransTextTo;
}

void ShowUserContentSelection()
{
	string ColsWalls = Repeat('-', 32);

	cout << '|' << ColsWalls << '|' << endl;
	cout << "|        Select Content          | \n";
	cout << '|' << ColsWalls << '|' << endl;
	cout << "| [1]: => Animals                | \n";
	cout << "| [2]: => Body                   |\n";
	cout << "| [3]: => Computer               |\n";
	cout << "| [4]: => garden                 |\n";
	cout << "| [5]: => Programming languages  |\n";
	cout << '|' << ColsWalls << '|' << endl;
}

string GetUserContentSelection(stFullData& FullData)
{

	ShowUserContentSelection();

	FullData.ContactUserChose = ReadContactChose();

	RestScreen();

	switch (FullData.ContactUserChose)
	{
	case enContactUserChose::enAnimals:

		return GenerateRandomQuizz(FullData.QuizzData.vAnimals);

	case enContactUserChose::enBody:

		return GenerateRandomQuizz(FullData.QuizzData.vBodyParts);

	case enContactUserChose::enComputer:

		return GenerateRandomQuizz(FullData.QuizzData.vComputerParts);

	case enContactUserChose::enGarden:

		return GenerateRandomQuizz(FullData.QuizzData.vGardenItems);

	case enContactUserChose::enProgrammingLanguages:

		return GenerateRandomQuizz(FullData.QuizzData.vProgrammingLanguages);

	}
}

stFullData GetFullQuizzWord()
{
	stFullData FullData;

	string RandomQuizz = GetUserContentSelection(FullData);
	string DashQuizz = AnonymizeIdentity(RandomQuizz, '-');

	char Vowels = RandomQuizz[0];

	for (int i = 0; i < RandomQuizz.length(); i++)
	{
		Vowels = RandomQuizz[i];
		if (Vowels == 'A' || Vowels == 'E' || Vowels == 'I' || Vowels == 'O' || Vowels == 'U')
			DashQuizz[i] = RandomQuizz[i];
	}
	FullData.GameData.RestGameSettings = true;
	FullData.GameData.QuizzFullWord = RandomQuizz;
	FullData.GameData.DashQuizz = DashQuizz;

	return FullData;
}

string UpdateUserInputQuizz(stFullData& FullData)
{
	char UserInput = FullData.GameData.UserInput;

	for (int i = 0; i < FullData.GameData.QuizzFullWord.length(); i++)
		if (tolower(UserInput) == FullData.GameData.QuizzFullWord[i])
			FullData.GameData.DashQuizz[i] = tolower(UserInput);
		else if (toupper(UserInput) == FullData.GameData.QuizzFullWord[i])
			FullData.GameData.DashQuizz[i] = toupper(UserInput);


	return FullData.GameData.DashQuizz;
}

bool IsContainsInput(char UserInput, string Check)
{
	for (int i = 0; i < Check.length(); i++)
		if (tolower(UserInput) == tolower(Check[i]))
			return true;

	return false;
}

void HandleGuessCorrectness(stFullData& FullData)
{
	FullData.GameData.RightAnswer = (IsContainsInput(FullData.GameData.UserInput, FullData.GameData.DashQuizz));
	bool UserInputVsDashQuizz = FullData.GameData.RightAnswer;

	if (UserInputVsDashQuizz)
	{
		FullData.GameData.WrongGuessCount++;
		StartBuildHangRope((enNumbersOfWrongQuess)FullData.GameData.WrongGuessCount);
		SetScreenColor(false);
	}


	FullData.GameData.RightAnswer = (!IsContainsInput(FullData.GameData.UserInput, FullData.GameData.QuizzFullWord));
	UserInputVsDashQuizz = FullData.GameData.RightAnswer;

	if (UserInputVsDashQuizz)
	{
		FullData.GameData.WrongGuessCount++;
		StartBuildHangRope((enNumbersOfWrongQuess)FullData.GameData.WrongGuessCount);
		SetScreenColor(false);
	}
	else
	{
		system("cls");
		SetScreenColor(!UserInputVsDashQuizz);
		FullData.GameData.DashQuizz = UpdateUserInputQuizz(FullData);
	}
}

bool DetermineWinnerStatus(string FirstText, string SecondsText)
{
	return (FirstText == SecondsText);
}

string GetWinOrLoseResult(stFullData FullData)
{
	cout << endl;

	string WinnerStatus = "\nYou Won the game :-) it's was: " + FullData.GameData.QuizzFullWord;
	string LosingStatus = "\nYou Lose The Game :-( it's was: " + FullData.GameData.QuizzFullWord;

	return (FullData.GameData.WinnerStatus) ? WinnerStatus : LosingStatus;
}

void PrintQuizzWord(stFullData& FullData)
{

	cout << Repeat('-', 35) << endl;

	// Rest Game Char Table
	FullData.GameData.RestGameSettings = false;
	do
	{
		ConsonantsOnly(toupper(FullData.GameData.UserInput), FullData.GameData.RestGameSettings);

		cout << "\n\nThe Quizz Word :" << FullData.GameData.DashQuizz;

		cout << endl << endl;

		FullData.GameData.UserInput = ReadUserInput();

		HandleGuessCorrectness(FullData);

		FullData.GameData.WinnerStatus = DetermineWinnerStatus(FullData.GameData.DashQuizz, FullData.GameData.QuizzFullWord);

		// If Player Full Quizz The Word Player Won! 
		if (FullData.GameData.WinnerStatus)
			return;

		cout << endl << Repeat('-', 35) << endl;
	} while (FullData.GameData.WrongGuessCount < 4);
}

void SetupGame()
{
	stFullData FullData = GetFullQuizzWord();

	ConsonantsOnly(toupper(FullData.GameData.UserInput), FullData.GameData.RestGameSettings);

	PrintQuizzWord(FullData);

	SetScreenColor(FullData.GameData.WinnerStatus);

	cout << GetWinOrLoseResult(FullData);
}

void StartGame()
{
	char PlayAgain = 'n';

	do
	{
		RestScreen();
		SetupGame();

		system("color 0F");
		printf("\n\n\t\tDo want to play again? Y/N: ");
		cin >> PlayAgain;

	} while (toupper(PlayAgain) == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
