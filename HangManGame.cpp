// Hangman Game

#include<iostream>
#include <ctime>
#include <string>
#include<cstdlib>


using namespace std;

const int MAX_BAD_GUESS = 7;
const string WORD_LIST[] = {"Aatrox","Ahri","Akali","Alistar","Amumu","Anivia","Annie","Ashe","AurelionSol","Azir","Bard","Blitzcrank","Brand","Braum","Caitlyn","Camille","Cassiopeia","ChoGath","Corki","Darius","Diana","DrMundo","Draven","Ekko","Elise","Evelynn","Ezreal","Fiddlesticks","Fiora","Fizz","Galio","Gangplank","Garen","Gnar","Gragas","Graves","Hecarim","Heimerdinger","Illaoi","Irelia","Ivern","Janna","Jarvan","IV","Jax","Jayce","Jhin","Jinx","Kalista","Karma","Karthus","Kassadin","Katarina","Kayle","Kennen","KhaZix","Kindred","Kled","KogMaw","LeBlanc","LeeSin","Leona","Lissandra","Lucian","Lulu","Lux","Malphite","Malzahar","Maokai","Master","Yi","MissFortune","Mordekaiser","Morgana","Nami","Nasus","Nautilus","Nidalee","Nocturne","Nunu","Olaf","Orianna","Pantheon","Poppy","Quinn","Rammus","RekSai","Renekton","Rengar","Riven","Rumble","Ryze","Sejuani","Shaco","Shen","Shyvana","Singed","Sion","Sivir","Skarner","Sona","Soraka","Swain","Syndra","TahmKench","Taliyah","Talon","Taric","Teemo","Thresh","Tristana","Trundle","Tryndamere","TwistedFate","Twitch","Udyr","Urgot","Varus","Vayne","Veigar","VelKoz","Vi","Viktor","Vladimir","Volibear","Warwick","Wukong","Xerath","XinZhao","Yasuo","Yorick","Zac","Zed","Ziggs","Zilean","Zyra"};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof( string);
const string draw[] = {
	"   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n",

};

string chooseWord()
{
	int randomInt = rand() % WORD_COUNT;
	string a = WORD_LIST[randomInt];
	for ( int i = 0;i < a.length();i++)
		if(a[i] <91 && a[i] >64)
			a[i] = a[i] + 32;
	return a;
}

void render(string guessedWord, int badGuessCount,string wrongWord)
{
	cout << draw[badGuessCount] << endl;
	cout << "The word you need to find out: " << guessedWord << endl;
	cout << "The bad guess you did: " << badGuessCount << endl;
	cout << "Your bad word: " << wrongWord << endl;
}

char readAGuess()
{
	char guess;
	cout << "Input a character: ";
	cin >> guess;
	return guess;
}

bool contain(string word, char guess)
{
	return word.find_first_of(guess) != string :: npos;
}

string update(string guessedWord, string word, char guess)
{
	int i;
	int len = word.length();
	for (i=0;i<len;i++)
		if (guess == word[i])
			guessedWord[i] = guess;
	return guessedWord;
}

int main()
{
	srand(time(NULL));
	string word = chooseWord();
	string guessedWord = string(word.length(),'-');
	int badGuessCount = 0;
	string wrongWord = "";
	do {
		for (int k = 0;k<30;k++)
			cout << endl;
		render(guessedWord,badGuessCount,wrongWord);
		char guess = readAGuess();
		if (contain(word,guess))
			guessedWord = update(guessedWord,word,guess);
		else {
			badGuessCount ++;
			wrongWord += guess;
		}
	} while (badGuessCount < MAX_BAD_GUESS && word != guessedWord);
	
	if (badGuessCount == MAX_BAD_GUESS){
		for (int k = 0;k<30;k++)
			cout << endl;
		cout << draw[MAX_BAD_GUESS] << "You lost, game over!!" << endl;
	} else cout << "You win, so excited!!"<<endl;
	cout << "The hiden word is " << word;
	return 0;
}
