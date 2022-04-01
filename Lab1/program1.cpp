#include<iostream>
#include<string>

using namespace std;

int main()
{
    //variable decalarations
    char c1;
    int i;
    int alp=0, space=0,other=0;

    //string variable to store each user input character
    string str1;

    //prompt the suer to enter a string and record the value in str1
	  cout << "Please Enter a string: ";
    getline(cin, str1);
    cout<<endl;

    //count characters of alphabets and not alphabets and spaces
    for(i = 0; str1[i] != '\0'; i++)
    {
          c1= str1[i];
		      if (isalpha(c1))
		      {
		            alp++;
		      }
		      else if (isspace(c1))
          {
                space++;
          }
          else
          {
                other++;;
          }
    }

    //print the number of alphabets and non aplhabets in the string
    cout<<" The number of alphabets are: "<<alp<<endl;
    cout<<" The number of spaces are: "<<space<<endl;
    cout<<" The number of other characters are: "<<other<<endl<<endl;

    return 0;
}
