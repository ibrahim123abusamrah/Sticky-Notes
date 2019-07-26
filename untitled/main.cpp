#include <iostream>
#include <String>
#include<vector>
#include <fstream>
#include <ctime>

using namespace std;


vector<string> all_user_firstNAme, all_user_secndNAme;// all user in project
void adduser_to_file_contain_all_user(string First_Name ,string Last_Name){
// this function open file that contain all user and add new user to them
    ofstream write_file_that_contain_allUSER;
    write_file_that_contain_allUSER.open("C:/Users/Just work/Documents/GitHub/Sticky-Notes/all_user.txt", ios::app);
    write_file_that_contain_allUSER<<First_Name<<endl;
    write_file_that_contain_allUSER<<Last_Name<<endl;
    write_file_that_contain_allUSER.close();

}
void openfile_contain_all_user(){
// this function open file that contain all user and put them in two vector (all_user_firstNAme,all_user_secndNAme) that declarate in global area
    ifstream read_file_that_contain_allUSER;
    read_file_that_contain_allUSER.open("C:/Users/Just work/Documents/GitHub/Sticky-Notes/all_user.txt");
    string fstName,secName;
    while (!read_file_that_contain_allUSER.eof())//end of file
    {

        read_file_that_contain_allUSER >>fstName;
        all_user_firstNAme.push_back(fstName);
        read_file_that_contain_allUSER >> secName;
        all_user_secndNAme.push_back(secName);
    }
    read_file_that_contain_allUSER.close();
    all_user_firstNAme.pop_back();
    all_user_secndNAme.pop_back();
}
void print_allUser(){
// print all user that use thiis program
    for (int i = 0; i < all_user_firstNAme.size(); i++)
        cout<<all_user_firstNAme[i] <<" "<<all_user_secndNAme[i]<<endl ;


}
bool isUserexist(string First_Name ,string Last_Name){
// check if the user exist between file or not if exist return true or false
    bool is_user_exist = false;


    for (int i = 0; i < all_user_firstNAme.size(); i++) {
        if ((all_user_firstNAme[i] == First_Name) && (all_user_secndNAme[i]== Last_Name)) { //compare what function passes -> first name and secand name with two vector firstname and secand name
            is_user_exist = true;
        } else {
            is_user_exist = false;
        }
    }
    return is_user_exist;

}

int main() {

    openfile_contain_all_user();
//print_allUser(); // for test
    int choice;
//cout << all_user_firstNAme.size();//for test

    cout << endl;

// main menu
    cout << "Welcome to the brand new ï¿½Sticky Notesï¿½!.\n"
         << "Here is the list of operation this program offers:.\n"
         << " 1 - Add new user.\n"
         << " 2 - Add new note.\n"
         << " 2 - View notes for a specific user.\n"
         << " 4 - Exit.\n"
         << " Enter your choice and press return: ";

    while(cin >> choice){
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
                adduser_to_file_contain_all_user(first_name, last_name); // function that add user into file .txt contain all user
                string filename = first_name + " " + last_name;
                cout << filename;

                //creat new file user
                ofstream myfile;
                myfile.open(
                        "C:\\\\Users\\\\Just work\\\\Documents\\\\GitHub\\\\Sticky-Notes\\\\untitled\\\\cmake-build-debug\\" +
                        filename + ".txt");
                myfile.close();


            }
                //  >>>>>>> 56ff2095387f9f2018d5e2b36d599f4e641aa94e

                break;

            case 2:
                //code to Add new note (Positive Case )

            {

                ofstream write_note_tofileUser;
                // open stream to write note for user
                // ifstream readNote_tofileUser;
                string First_Name, Last_Name;
                cout << " Let’s add a new note ... \n"
                     << "Please enter your full name first: <Enter First Name> <Enter Last Name> \n";
                cin >> First_Name >> Last_Name;


                bool is_user_exist = false;

// check if user exist or not
                for (int i = 0; i < all_user_firstNAme.size(); i++) {
                    if ((all_user_firstNAme[i] == First_Name) && (all_user_secndNAme[i] == Last_Name)) {
                        is_user_exist = true;
                        break;
                    } else {
                        is_user_exist = false;
                    }
                }
                if (is_user_exist) {
                    string userNote;
                    cout << "\nYour record is found, I’m now opening your file ….";
                    //readNote_tofileUser.open("C:\\Users\\Just work\\Documents\\GitHub\\Sticky-Notes\\untitled\\cmake-build-debug\\"+First_Name+" "+Last_Name+".txt");
                    write_note_tofileUser.open(
                            "C:\\Users\\Just work\\Documents\\GitHub\\Sticky-Notes\\untitled\\cmake-build-debug\\" +
                            First_Name + " " + Last_Name + ".txt", ios::app);

                    cout << "\nReady!"
                         << "\nPlease enter your note:\n";
                    //cin>>userNote;
                    char ch;
                    cin.get(ch);// i do this because ignore cleck enter
                    getline(cin, userNote);
                    // current date/time based on current system
                    time_t now = time(0);

                    tm *ltm = localtime(&now);

                    // print various components of tm structure.

                    int Year = 1900 + ltm->tm_year;
                    int Month = 1 + ltm->tm_mon;
                    int Day = ltm->tm_mday;


                    int hour = 1 + ltm->tm_hour;
                    int mint = 1 + ltm->tm_min;
                    cout << "Your note has b1een well received, 1 second while saving it ….\n";
                    if (mint < 10) {
                        write_note_tofileUser << Month << "/" << Day << "/" << Year << " " << hour << ":" << "0" << mint
                                              << ":" << "\n***\n" << userNote << "\n***\n";

                    } else {

                        write_note_tofileUser << Month << "/" << Day << "/" << Year << " " << hour << ":" << mint << ":"
                                              << "\n***\n" << userNote << "\n***\n";
                    }


                } else {

                    cout << endl
                         << " Oh! Sorry the user name was not found, please check the name again and if this is your\n"
                         << " first time here, please go ahead and create a new user from the main menu ...\n"
                         << " <Click Enter to return to main menu>\n";
                }
            }
                break;
            case 3: {
                //this code view all note user
                string First_Name, Last_Name;
                cout << endl
                     << "Retrieve your notes? Absolutely! \n"
                     << "Please let know your full name first: <Enter first name> <Enter last Name>.\n";
                cin >> First_Name;
                cin >> Last_Name;
                bool t = isUserexist(First_Name, Last_Name);
                if (t == true) {

                    //view all user’s notes: (Positive Case)

                    cout << "Found it!\n"
                         << "Here are your stored notes:\n"
                         << "-------------\n";
                    string line;
                    int s = 0;
                    string filename = First_Name + " " + Last_Name;
                    ifstream myfile(
                            "C:\\\\Users\\\\Just work\\\\Documents\\\\GitHub\\\\Sticky-Notes\\\\untitled\\\\cmake-build-debug\\" +
                            filename + ".txt");
                    int counter = 0;
                    if (myfile.is_open()) {
                        while (!myfile.eof()) {
                            getline(myfile, line);

                            if (line == "***") {
                                counter++;
                                if (counter == 2) {
                                    cout << "-------------------------------\n";
                                    counter = 0;

                                }
                                continue;
                            } else
                                cout << line << '\n';
                        }
                        myfile.
                                close();
                    }
                } else {
                    // view all user’s notes: (Negative Case)
                    cout << "\nUmm, can’t find any saved notes for you.\n"
                         << "<Click Enter to return to main menu>";

                }


            }
                break;
            case 4:
            {
                return 1;
            }


        }
        system("pause");

        cout << "Welcome to the brand new ï¿½Sticky Notesï¿½!.\n"
             << "Here is the list of operation this program offers:.\n"
             << " 1 - Add new user.\n"
             << " 2 - Add new note.\n"
             << " 2 - View notes for a specific user.\n"
             << " 4 - Exit.\n"
             << " Enter your choice and press return: ";
    }

    return 0;


}