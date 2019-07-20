#include <iostream>
#include <String>
#include<vector>
#include <fstream>
#include <ctime>

using namespace std;
vector<string> all_user_firstNAme, all_user_secndNAme;// all user in project

void adduser_to_file_contain_all_user(string First_Name ,string Last_Name){
    ofstream write_file_that_contain_allUSER;
    write_file_that_contain_allUSER.open("C:/Users/Just work/Documents/GitHub/Sticky-Notes/all_user.txt", ios::app);
    write_file_that_contain_allUSER<<First_Name<<endl;
    write_file_that_contain_allUSER<<Last_Name<<endl;
    write_file_that_contain_allUSER.close();

}
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
    read_file_that_contain_allUSER.close();
    all_user_firstNAme.pop_back();
    all_user_secndNAme.pop_back();
}
void print_allUser(){
    for (int i = 0; i < all_user_firstNAme.size(); i++)
    cout<<all_user_firstNAme[i] <<" "<<all_user_secndNAme[i]<<endl ;


}
bool isUserexist(string First_Name ,string Last_Name){
    bool is_user_exist = false;


    for (int i = 0; i < all_user_firstNAme.size(); i++) {
        if ((all_user_firstNAme[i] == First_Name) && (all_user_secndNAme[i]== Last_Name)) {
            is_user_exist = true;
        } else {
            is_user_exist = false;
        }
    }
    return is_user_exist;

}
void addNote_ifUserexsit(){



}
void addNote_ifUserNOTexsit(){



}
int main() {

    openfile_contain_all_user();    print_allUser();
    int choice;
cout<<all_user_firstNAme.size();
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
            adduser_to_file_contain_all_user(first_name,last_name);
            string filename = first_name + " " + last_name;
            cout << filename;

            ofstream myfile;
            myfile.open("C:\\\\Users\\\\Just work\\\\Documents\\\\GitHub\\\\Sticky-Notes\\\\untitled\\\\cmake-build-debug\\"+filename + ".txt");
            myfile.close();




        }
            //  >>>>>>> 56ff2095387f9f2018d5e2b36d599f4e641aa94e

            break;

        case 2:
            //code to Add new note (Positive Case )

        {
            ofstream write_note_tofileUser;
           // ifstream readNote_tofileUser;
            string First_Name, Last_Name;
            cout << " Let’s add a new note ... \n"
                 << "Please enter your full name first: <Enter First Name> <Enter Last Name> \n";
            cin >> First_Name >> Last_Name;


            bool is_user_exist = false;


            for (int i = 0; i < all_user_firstNAme.size(); i++) {
                if ((all_user_firstNAme[i] == First_Name) && (all_user_secndNAme[i]== Last_Name)) {
                    is_user_exist = true;
                } else {
                    is_user_exist = false;
                }
            }
            if(is_user_exist)
            {
                string userNote;
             cout<<"\nYour record is found, I’m now opening your file ….";
                //readNote_tofileUser.open("C:\\Users\\Just work\\Documents\\GitHub\\Sticky-Notes\\untitled\\cmake-build-debug\\"+First_Name+" "+Last_Name+".txt");
                write_note_tofileUser.open("C:\\Users\\Just work\\Documents\\GitHub\\Sticky-Notes\\untitled\\cmake-build-debug\\"+First_Name+" "+Last_Name+".txt", ios::app);

               cout<<"\nReady!"
               <<"\nPlease enter your note:\n";
            //cin>>userNote;
            char ch;
            cin.get(ch);
              getline(cin,userNote);
                // current date/time based on current system
                time_t now = time(0);

                // convert now to string form
                char* dt = ctime(&now);
                cout<< dt;
            cout<<"Your note has b1een well received, 1 second while saving it ….\n";
            write_note_tofileUser<<userNote<<"\n***\n"<<dt<<"***\n";

            }


        }
            break;

    }
    return 0;

}
