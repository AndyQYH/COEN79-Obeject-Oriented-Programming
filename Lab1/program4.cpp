#include<iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    string str; //used to store input string
    int max_size = 1;//used for checking user input
    int guess,count = 0, i = 0; // used for char count, and looping
    vector<int> values; // used to store guessed numbers
    srand(time(0));// used to change random numbers every time

    //prompt user to think of a number
	  cout << "Think of a number between 1 and 20. Press Enter When you are ready: " << endl;
    getline(cin, str);
    cout<< endl;

   //while haven't guess the correct answer
    while(str.compare("Y") != 0)
    {
      //error check for invalid answers
      if(str.length() > max_size)
      {
        cout << "format wrong, please try again (please enter 'Y' or 'N' instead of 'YES' or 'NO')"<<endl;
      }

       guess = (rand() % 20) + 1;

       //get a guess value until it hasn't been guessed before
       while(find(values.begin(), values.end(),guess) != values.end())
       {
          guess = (rand() % 20) + 1;
       }

       //ask the player if it is the correct guess
       cout << "Is the number " << guess << "?"<<endl;
       getline(cin, str);

       //if not add to the guessed list, so next time it won't guess the same value
       values.push_back(guess);
       count++;
       i++;
    }

    //print the number of tries taken to guess it right
    cout<<"I find the number in " << count << " tries." << endl;

     return 0;
}
