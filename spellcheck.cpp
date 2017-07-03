#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void dictionary_processing(string word)
{
    ifstream data_store;
    string line[21882];//an array set to how many lines are in the dictionary
    int match = 0;
    data_store.open("dict.txt");

    if (!data_store)
    {
        cout << "File not found"<<endl;
        exit(0);
    }
    while (!data_store.eof() && word != "exit")
    {
        for (int counter = 0; counter < 21882; counter++)
        {
            getline(data_store, line[counter]);
            if (line[counter] == word && match != 1)
            {
                match = 1;
                cout <<word<< " is spelled correctly.\n";
            }
            else if (word != line[counter] && counter == 21881 && match != 1)
            {
                cout <<word<< " is not spelled correctly.\n";
                return;
            }
        }
    }
    data_store.close();

}
int main ()
{
    string user_input;
    do
    {
        cout << "Enter word to spellcheck (or exit to end)\n";
        getline(cin, user_input);
        dictionary_processing(user_input);
        for (int outer = 0; outer < user_input.length(); outer++)
        {
            tolower(user_input[outer]);
        }
    }
    while (user_input != "exit");
    cout << "Ending program...\n";
    return 0;
}
