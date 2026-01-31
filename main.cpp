#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

vector<string> showing;
vector<string> hangmanpics = {
    "  +---+\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========",

    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========",

    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "=========",

    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|   |\n"
    "      |\n"
    "      |\n"
    "=========",

    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    "      |\n"
    "      |\n"
    "=========",

    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " /    |\n"
    "      |\n"
    "=========",

    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " / \\  |\n"
    "      |\n"
    "========="
};


vector<string>  list_of_words={
"abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom", "azure", "bagpipes", "bandwagon","banjo",
"bayou",
"beekeeper",
"blitz",
"blizzard",
"boggle",
"bookworm",
"boxcar",
"buffalo",
"buffoon",
"caliph",
"cobweb",
"crypt",
"daiquiri",
"fjord",
"fluffy",
"jovial",
"jukebox",
"kiosk",
"microwave",
"psyche",
"puppy",
"puzzling",
"quartz",
"rhythm",
"subway",
"swivel",
"syndrome",
"transcript",
"transgress",
"uptown",
"vixen",
"voodoo",
"vortex",
"walkway",
"waltz",
"witchcraft",
"wizard",
"woozy",
"wristwatch",
"xylophone",
"yachtsman",
"yoked",
"yummy",
"zephyr",
"zigzag",
"zigzagging",
"zilch",
"zipper",
"zodiac",
"zombie",
};
random_device rd;
mt19937 gen(rd());
int length1 = list_of_words.size();
int lives=6, num2=0;
bool checking=true;
char guess;
string random_word;

int main()
{
    uniform_int_distribution<> dis(0, length1 - 1);
    int random_number = dis(gen);
    random_word = list_of_words[random_number];
    int length2=random_word.length();
    for(short i=0; i<length2; i++){
        showing.push_back("_");
    }
    cout << "Welcome to Hangman" << endl;
    string joined = "";
    for(const string& s : showing) {
        joined += s;
    }
    cout<<joined<<endl;
    while(lives>0 && checking){
        int num=0;
        num2=0;
        cout<<"Guess a letter: ";
        cin>>guess;
        if(cin.fail()) {
            cout << "Guess a letter, not anything else!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if(!isalpha(guess)) {
            cout << "Please enter a letter!" << endl;
            continue;
        }
        guess=tolower(guess);

        for(short i=0; i<length2; i++){
            if(random_word[i]==guess){
                showing[i]=string(1, guess);
                num++;
            }
        }
        if (num>0){
            cout<<"You have guessed correctly!"<<endl;
            for (short i=0; i<length2; i++){
                if(showing[i]=="_"){
                    num2++;
                }
            }
            if(num2==0){
                checking=false;
                continue;
            }
        }
        else{
            lives--;
            cout<<"Wrong!Your remaining lives: "<<lives<<endl;
        }
        cout<<hangmanpics[6-lives]<<endl;
        string joined2 = "";
        for(const string& s : showing) {
        joined2 += s;
    }
        cout<<joined2<<endl;

    }
    if (lives>0){
        cout<<"You win!Your word is "<<random_word;
    }else{
        cout<<"You lose!Your word was "<<random_word;
    }
    return 0;
}
