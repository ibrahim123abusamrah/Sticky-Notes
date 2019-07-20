#include <iostream>
#include <String>
#include<vector>
#include <fstream>
using namespace std;
vector<string> all_user_firstNAme, all_user_secndNAme;// all user in project

void openfile_contain_all_user(){
    ifstream read_file_that_contain_allUSER;
    read_file_that_contain_allUSER.open("C:/Users/Just work/Documents/GitHub/Sticky-Notes/all_user.txt");
    string fstName,secName;
    while (!read_file_that_contain_allUSER.eof())
    {


        read_file_that_contain_allUSER >>fstName;
        all_user_firstNAme.push_back(fstName);
        read_file_that_contain_allUSER >> secName;
        all_user_secndNAme.push_back(secName);
    }

}
void print_allUser(){
    for (int i = 0; i < all_user_firstNAme.size(); i++)
        cout<<all_user_firstNAme[i] <<" "<<all_user_secndNAme[i] ;


}
bool isUserexist(string First_Name ,string Last_Name){
    bool is_user_exist = false;


    for (int i = 0; i < all_user.size(); i++) {
        if ((all_user[i][i] == First_Name) && (all_user[i][i + 1] == Last_Name)) {
            is_user_exist = true;
        } else {
            {is_user_exist = false;
/* ***********************************************
 * Add new note: (Negative Case)

                cout << endl
                     << " Oh! Sorry the user name was not found, please check the name again and if this is your\n"
                     << " first time here, please go ahead and create a new user from the main menu ...\n"
                     << " <Click Enter to return to main menu>\n";
                 cin>>;

*/
            }

        }
    }
	return is_user_exist;

    }
void addNote_ifUserexsit(){



}
void addNote_ifUserNOTexsit(){

     if()


}
int main() {
    openfile_contain_all_user();
    print_allUser();
    /*  int choice;

      cout << endl
           << "Welcome to the brand new ï¿½Sticky Notesï¿½!.\n"
           << "Here is the list of operation this program offers:.\n"
           << " 1 - Add new user.\n"
           << " 2 - Add new note.\n"
           << " 2 - View notes for a specific user.\n"
           << " 4 - Exit.\n"
           << " Enter your choice and press return: ";
      cin >> choice;

      switch (choice) {
          case 1: {
  //code to Add new user
              cout << endl
                   << "Welcome aboard new user!.\n"
                   << "Please let me know your first name:.\n";
              string first_name, last_name, file_name;
              cin >> first_name;
              cout << endl
                   << "Great " << first_name << " , now please enter your last name:";
              cin >> last_name;
              cout << endl
                   << " Done!.\n"
                   << " Nice to meet you .\n" << first_name << " " << last_name
                   << " .\n<Click Enter to return to main menu>.\n";
              //  <<<<<<< HEAD

              string filename = first_name + " " + last_name;
              cout << filename;

              ofstream myfile;
              myfile.open(filename + ".txt");
              myfile << "Writing this to a file.\n";
              myfile << "000" << filename;
              myfile.close();

              cout << "Enter user name";

  /*
          }
              //  >>>>>>> 56ff2095387f9f2018d5e2b36d599f4e641aa94e

              break;

          case 2:
              //code to Add new note (Positive Case )

          {
              string First_Name, Last_Name;
              cout << " Let’s add a new note ... \n"
                   << "Please enter your full name first: <Enter First Name> <Enter Last Name> \n";
              cin >> First_Name >> Last_Name;


              cout << endl;


          }
              break;

      }*/
    return 0;

}

/* **********************
 * view all user’s notes: (Positive Case)


{
cout << endl
<< "Retrieve your notes? Absolutely! \n"
<< "Please let know your full name first: <Enter first name> <Enter last Name>.\n";
cin>> First_Name ;
cin>> last Name;

bool t = isUserexist(string First_Name ,string Last_Name);
  if (t==true){
     cout<<"Found it!\n"
         <<"Here are your stored notes:\n"
         <<"-------------\n";
string line;
int s = 0;
ifstream myfile(filename + ".txt");
if (myfile.

is_open()

)
{

while (
getline (myfile, line
))
{
if (line=="***")
{
s++;
if(s==3)
cout<<"------------------------"}
else
cout << line << '\n';
}
myfile.

close();

}
}
  else
{}



}*/