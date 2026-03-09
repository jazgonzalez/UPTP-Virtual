#include <iostream>
#include <fstream>
//#include <sstream>
#include <string>
using namespace std;

void Register();
void Login();
int thisPreson(string);


int main (){
    int choice;
    
    cout << "\t\tMAIN MENU\n\n";
    cout << "\t1. REGISTER\n";
    cout << "\t2. LOGIN\n";
    cout << "\t3. EXIT\n";
    cout << "Select a choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            Register();
            break;
            
        case 2:
            Login();
            break;
            
        case 3:
            return 0;
            break;
            
        default:
            cout << "You must choose one!\n";
            main();
            break;
    }
    
}


void Register(){
    string userName, userPass;
    
    cout << "\tREGISTER\n\n";
    cout << "Create your username: ";
    cin >> userName;
    
    cout << "Create your password: ";
    cin >> userPass;
    
    fstream myFile("C:\\Users\\Jazlaptop\\Documents\\3RD SEMESTER\\project\\test.txt", ios::app);    //Open file foe writing (app --> appendice and out --> write) out is for beggin and app is to continue to write
    if (myFile.is_open()) {
        myFile << userName << " " << userPass << endl;  //write the name and password
        myFile.close();
    }
    else{
        cout << "Error at writing in the file\n";
    }
    
    cout << "Hello " << userName << " You registered succesfuly!\n\n";
    //main();
    thisPreson(userName);
    
    
}

void Login(){
    string user, pass, uN, uP;
    int count = 0;
    
    cout << "\tLOGIN\n\n";
    cout << "Enter your username: ";
    cin >> user;
    
    cout << "Enter your password: ";
    cin >> pass;
    
    ifstream myFile("C:\\Users\\Jazlaptop\\Documents\\3RD SEMESTER\\project\\test.txt"); // Open file for reading
        if (myFile.is_open()) {
            while (myFile >> uN >> uP) { // Read each pair of username and password from the file
                if (uN == user && uP == pass) { // Check if username and password match
                    cout << "You are logged in\n";
                    count = 1;
                    break; // Exit the loop once logged in
                }
            }
            myFile.close();
        } else {
            cout << "Error opening file\n";
            return;
        }
    
    if (count == 1) {
        cout << "Hello " << user << "!. You logged suscesfully!\n\n";
        cin.get();
        //main();
        thisPreson(user);
    }
    else{
        cout << "\tPlease check again your username or pasword\n\n";
        Login();
    }
    system("cls");
}

int thisPreson(string name){
    int cho;
    
    cout << "\tAre you Professor or Student?\n";
    cout << "\t1. Professor\n";
    cout << "\t2. Student\n";
    cout << "\t3. EXIT\n";
    cout << "Select your choice: ";
    cin >> cho;
    
    switch (cho) {
        case 1:
            cout << "Hello Professor " << name <<"!" << endl;
            break;
            
        case 2:
            cout << "Hey " << name << "!" << endl;
            break;
            
        case 3:
            return 0;
            break;
            
        default:
            cout << "Choose again among choises\n";
            thisPreson(name);
            break;
    }

    return main();
}
