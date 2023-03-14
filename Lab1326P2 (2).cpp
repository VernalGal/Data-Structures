#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
using namespace std;

class List {

public:

    //variable to keep track of number of items
    int num;
    //an array of items
    vector<string> array_titles;
    List() {
        array_titles.resize(10);
        ifstream f("bookks.txt"); // replace books.txt with the file name
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


    void append(string title)
    {
        array_titles.push_back(title);

    }






    void displayAll()
    {
        for (int i = 0; i < array_titles.size(); i++)
{

            cout << array_titles[i] << endl;
}
    }

    //search method to check for values that match in the list
    void search(string check)
    {
        
       
            for (int i = 0; i < 10; i++)
            {

                if (array_titles[i].find(check) != string::npos)
                {

                    cout << array_titles[i] << endl;
                }

            }
        
        /*else
        {
            cout << "Item length is too short" << endl;
        }
        */

    }


};


int main()
{
    char ch;
    string check = "";
    List list;
    char m;
    char a = 'm';

    while (a != 'N')
    {
        list.displayAll();

        cout << endl;

        cout << "------------------------------" << endl;
        cout << endl;
        cout << "Enter a title: ";


        int count = 0;
        ch = getchar();
        string check = string(1, ch);
        while (ch != '\n') {
            count++;
            if (count >= 3)
            {
                list.search(check);
                {
                    // check if item is in list already, assuming it is not... 
                    cout << "Do you want to add the title to the list? ()" << endl;
                    cin >> a;
                    if (a == 'Y')
                    {
                        list.append(check);
                        list.displayAll() ;
                    }
                }
            }
            ch = getchar();
            check += ch;
        }
        if (_kbhit())
        {
            ch = _getch();
            getline(cin, check);
            cout << "| Search: " << check;
            if (int(ch) == 8) {
                // backspace
                list.search(check);

                check.erase(check.size() - 1, 1);
            }


            if (int(ch) == 10) { // new line
                {
                    if (check.length() >= 3)
                    {
                        // check if item is in list already, assuming it is not...
                        cout << "Do you want to add the title to the list? ()" << endl;
                        cin >> a;
                        if (a == 'Y')
                        {
                            list.append(check);
                        }
                    }

                }
            }
            else
            {
                check += ch;
            }


            cout << " Type N to exit" << endl;
            cin >> a;
        }
        return 0;
    }
}

    //char ans;

    /*while(1)

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
cin>>ans;

    if(ans=='N')
break;

    }
    */
    

