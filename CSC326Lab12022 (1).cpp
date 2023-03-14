#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Bag {

public:

    //variable to keep track of number of items
    int num;
    //an array of items
    string array_titles[10];

    Bag() {
        ifstream f("books.txt"); // replace books.txt with the file name
        for (int i = 0; i < 10; ++i)
            getline(f, array_titles[i]);
        /*
        array_titles[0] = "Death Note";
        array_titles[1] = "Boruto: Naruto Next Generation";
        array_titles[2] = "Future Diary";
        array_titles[3] = "Naruto: The Last Movie";
        array_titles[4] = "Death Parade";
        array_titles[5] = "Naruto Shippoden";
        array_titles[6] = "Death Match";
        array_titles[7] = "The Day Naruto Became Hokage";
        array_titles[8] = "Angels of death";
        array_titles[9] = "Naruto";
        */
    }

    //method named displayAll is display the list of items
    void displayAll()
    {
        for (int i = 0; i < 10; i++)
        {

            cout << array_titles[i] << endl;
        }
    }

    //search method to check for values that match in the list
    void search(string check)
    {
        if (check.length() >= 3)
        {
            for (int i = 0; i < 10; i++)
            {

                if (array_titles[i].find(check) != string::npos)
                {

                    cout << array_titles[i] << endl;
                }

            }
        }
        else
        {
            cout << "Item length is too short" << endl;
        }


    }


};


int main()
{

    string check;
    Bag list;

    char ans;
    while (1)

    {
        cout << "------------------------------" << endl;
        cout << endl;
        cout << "| Search: |" << endl;
        cout << endl;
        cout << "------------------------------" << endl;
        cout << endl;

        list.displayAll();
        cout << endl;

        getline(cin, check);

        cout << endl;
        list.search(check);

        cout << "Do you want to continue this search? (If yes keep searching, if no then type in 'N')" << endl;

        cin >> ans;

        if (ans == 'N')

            break;

    }

    return 0;
}