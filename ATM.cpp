
#include<fstream>
#include <conio.h>
#include <iostream>
#include<string>
#include<cstring>
#include<vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include<limits>

using namespace std; 


struct user {
    string username;
    float balance;
    int password;
};


void showmenu() { 
    cout<<":::::::::::::::::::::::::::::::::::::"<<endl;  
  cout << " -------------------------------------------------------------------------" << endl;
  cout << "|\t\tWelcome to KINYAB ATM SERVICE                            |"  << endl;
  cout << " -------------------------------------------------------------------------" << endl;
    cout<<" 1. ADMIN "<<endl; 
    cout<<" 2. USER "<<endl; 
    cout<<" 3. INFO "<<endl; 
    cout<<" 4. EXIT" << endl;
    cout<<":::::::::::::::::::::::::::::::::::::"<<endl;
} 
void showadminmenu() {

     cout<<":::::::::::::::::::::::::::::::::::::"<<endl;
      cout << "Welcome to Admin menu"<< endl;
                       cout << "1. ADD USERS"<<endl;
                       cout << "2. DELETE USERS"<<endl;
                       cout << "3. VIEW ALL  USERS"<<endl;
                       cout << "4. EXIT" << endl;

     cout<<":::::::::::::::::::::::::::::::::::::"<<endl;

}
void showusermenu(string name) {
     cout<<":::::::::::::::::::::::::::::::::::::"<<endl;
      cout << "Welcome " << name << ", Here is your menu"<< endl;
                       cout << "1. DEPOSIT"<<endl;
                       cout << "2. WITHDRAW"<<endl;
                       cout << "3. FUND TRANSFER"<<endl;
                       cout << "4. VIEW ACCOUNT" << endl;
                       cout << "5. EXIT" << endl;
   cout<<":::::::::::::::::::::::::::::::::::::"<<endl;

}
void showInfo() {
    cout << "DEVELOPERS OF THE CONSOLE APP" << endl;
    cout << "KINFEMICHAEL TARIKU - UGR/5573/14"<< endl;
    cout << "YABSIRA ZEWDIE - UGR/XXXX/14" << endl;
    cout << "YABSIRA ZEWDIE - UGR/XXXX/14" << endl;
}
// check user exist or not
bool checkUser(string name) {
    ifstream file;
    bool isExist = false;
    file.open("admin_test.txt");
    vector<string> users(100);
    // string users[3];
    
    string user;
    int i = 0;
    while(!file.eof()){
        while(getline(file  , user)){
            std::string token = user.substr(0, user.find(" "));
            if(token == name){
                isExist = true;


            }
          
        }


    }
    return isExist;
}
// custome function for taking a speciffic part of the string
 std::string SubString(const std::string& string, int beginIndex, int endIndex) {
        int size = (int)string.size();
        if (beginIndex < 0 || beginIndex > size - 1) 
            return "-1"; // Index out of bounds
        if (endIndex < 0 || endIndex > size - 1)
            return "-1"; // Index out of bounds
        if (beginIndex > endIndex)
            return "-1"; // Begin index should not be bigger that end.

        std::string substr;
        for (int i = 0; i < size; i++) 
            if (i >= beginIndex && i <= endIndex)
                substr += (char)string[i];
        return substr;
    }

vector<string> fetchUsersVector() {
    ifstream file;
    file.open("users.txt");
    vector<string> users(100);
    // string users[3];
    string user;
    int i = 0;
    while(!file.eof()){
        while(getline(file  , user)){
            users[i] = user;
            i+=1;
          
        }


    }
    return users;
}
bool isFound(string username_login , string password_login) {
    ifstream file;
    string str;
    bool isExist=false;
    string single_user;
    // string loggedIn = "uman";
    // string password_login = "1212";
     file.open("admin_test.txt");
 
    string user;
      while(!file.eof()){
        while(getline(file  , str)){
            int pos1 = str.find(" ");
            string name = SubString(str , 0 , pos1-1);
            string left_over = SubString(str , pos1+1 , str.size()-1);
          
            string password = SubString(left_over , 0 ,  left_over.find(" ")-1);
            if(username_login.compare(name) == 0 && password.compare(password_login) == 0 ){
               isExist = true;
            }
            // std::cout << s << std::endl;

            
          
        }


    }
    return isExist;
} 
int createUser() {

    // simulating like API request and check the status code
    string username;
    ofstream file;
    int password;
    ofstream file_admin , users;
    users.open("users.txt" , ios::out | ios::app);
    float initialBalance;
    cout << "Enter a username: ";
    cin >> username;
    cout << "give " << username << " a password: ";
    cin >> password;
    cout << "Enter an initial deposit for user " << username << ": ";
    cin >> initialBalance;
    file.open("admin_test.txt" , ios::out|ios::app);
    file_admin.open("admin_cred.txt" , ios::out|ios::app);
    if(!file_admin) {
        cout << "Unable to create a user! , Please try again later"<< endl;
        return 0;
    }
    user u1;
    u1.username = username;
    u1.password = password;
    u1.balance = initialBalance;
    // for secuirty purpose we can define to be coded as binary
    file_admin.write((char *)&u1 , sizeof(u1));

    file  << "\n" << username << " ";
    file  << password << " ";
    file << initialBalance << " ";
    users << username << "\n";
    file.close();
    
    file_admin.close();
    //
    return 1;
    

}

void  viewallusers() {
    ifstream file_admin;
    ifstream file;
    user u1;

    cout << "ACCOUT CREDENTIAL INFORMATION" << endl;

     ifstream in;
        ofstream out;
        string balance;
        string name;
        string password;
        string toreplaceBalance;
        string toreplaceName;
        string toreplacePassword;
        float balances ;
        in.open("admin_test.txt" , ios::app);
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "\t\tAll Registered Account" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "ACCOUNT USERNAME  " << "\t" << "PASSWORD" << "\t\t"<< "CASH" <<  endl;
        cout << "----------------        ---------               ------" << endl;
        while(in>>name>>password>>balance)
        {
             
               cout << name  <<  "\t\t\t" << password << "\t\t\t" << "$" <<  balance <<  endl;


        }

        in.close();

}

int  deleteUser() {




        ifstream in ;
        ofstream out;
        string balance;
        string name;
        string password;
        string acceptedName;
        string toreplaceBalance;
        string toreplaceName;
        string toreplacePassword;
        float balances ;
        cout << "Enter your username : ";
        cin >> acceptedName;

        int deleted = 1;
        in.open("admin_test.txt" , ios::app);
        out.open("tempo.txt");
        while(in>>name>>password>>balance)
        {
          
            if(acceptedName.compare(name) == 0 ){
                deleted = 0;
                
               
                continue;

                }
               


            
            out << name << " " << password << " " <<  balance << "\n";
        




        }
      
    
        out.close();
        in.close();
        remove("admin_test.txt");
        rename("tempo.txt" , "admin_test.txt");

    // user u1;
    // fstream original, temp;
    // string name;
    // cout << "Enter the username: ";
    // cin >> name ;
    // string selected;
	// original.open("admin_test.txt", ios::in);
    // temp.open("temp.txt" , ios::out);
    // vector<string> avaUsers = fetchUsersVector();
    // bool isExist = false;

  
    // for(int i=0; i<avaUsers.size(); i++){
    //     if(avaUsers[i] == name){
    //         cout << avaUsers[i] << endl;
    //         isExist = true;
            


    //     }
    // }
    // string datas;
    
    // if(isExist) {
    //     while(!original.eof()){

    //     while(getline(original  , datas)){
    //         std::string token = datas.substr(0, datas.find(" "));
    //         if(token != name){
    //           temp << "\n" << datas ;

    //         }
           
          
    //     }


    // }



    // }else {
    //     cout << "User Not Found " << endl;
    //     return 1;
    // }
	
    // temp.close();
    // original.close();

    
    // remove("admin_test.txt");

    // rename("temp.txt", "admin_test.txt");
    return deleted;


}

int updateWithdraw(string username_login , string password_login , float withdraw ){
    ifstream in;
        ofstream out;
        string balance;
        string name;
        string password;
        string toreplaceBalance;
        string toreplaceName;
        string toreplacePassword;
        float balances ;
        in.open("admin_test.txt" , ios::app);
        out.open("tempo.txt");
        while(in>>name>>password>>balance)
        {
          
            if(username_login.compare(name) == 0 && password_login.compare(password) == 0 ){
                toreplaceBalance = balance;
                if(stof(toreplaceBalance) < withdraw){
                    return 0;
                    break;
                }
                else{
                balances = std::stof(toreplaceBalance) - withdraw;
                toreplaceName = name;
                toreplacePassword = password;
                continue;

                }
               


            }
            out << name << " " << password << " " <<  balance << "\n";
        




        }
        out<<toreplaceName << " " << toreplacePassword << " " << balances << "\n";
    
        out.close();
        in.close();
        remove("admin_test.txt");
        rename("tempo.txt" , "admin_test.txt");
    return 1;

}
int updateDeposite(string username_login , string password_login , float deposit){
        ifstream in;
        ofstream out;
        string balance;
        string name;
        string password;
        string toreplaceBalance;
        string toreplaceName;
        string toreplacePassword;
        float balances ;
        in.open("admin_test.txt" , ios::app);
        out.open("tempo.txt");
        while(in>>name>>password>>balance)
        {
           
            if(username_login.compare(name) == 0 && password_login.compare(password) == 0 ){
                toreplaceBalance = balance;
                balances = std::stof(toreplaceBalance) + deposit;
                toreplaceName = name;
                toreplacePassword = password;
                continue;


            }
            out << name << " " << password << " " <<  balance << "\n";

        }
        out<<toreplaceName << " " << toreplacePassword << " " << balances << "\n";
    
        out.close();
        in.close();
        remove("admin_test.txt");
        rename("tempo.txt" , "admin_test.txt");
    return 1;
}
bool isRecieverExist(string to_whom){
    bool isExist = false;
    vector<string> availableUsers = fetchUsersVector();
    for(int i=0; i<availableUsers.size(); i++){
        if(availableUsers[i] == to_whom){
            isExist = true;
        }
    }
    return isExist;
}
int updateDepositeReceiver(string to_whom , float transfer){
     ifstream in;
        ofstream out;
        string balance;
        string name;
        string password;
        string toreplaceBalance;
        string toreplaceName;
        string toreplacePassword;
        float balances ;
        in.open("admin_test.txt" , ios::app);
        
        // out.open("admin_j.txt");
        out.open("tempo.txt");
        while(in>>name>>password>>balance)
        {
           
            if(to_whom.compare(name) == 0 ){
                toreplaceBalance = balance;
                balances = std::stof(toreplaceBalance) + transfer;
                toreplaceName = name;
                toreplacePassword = password;
                continue;


            }
            out << name << " " << password << " " <<  balance << "\n";
        




        }
        out<<toreplaceName << " " << toreplacePassword << " " << balances << "\n";
    
        out.close();
        in.close();
        remove("admin_test.txt");
        rename("tempo.txt" , "admin_test.txt");
    return 1;

}
void displayAccount(string username_login , string password_login ){
    ifstream in;
        ofstream out;
        string balance;
        string name;
        string password;
        string toreplaceBalance;
        string toreplaceName;
        string toreplacePassword;
        float balances ;
        in.open("admin_test.txt" , ios::app);
        cout << " -------------------------------------------------------------------------" << endl;
        cout << "|\t\tWelcome " << username_login << " to you personal account profile              |" << endl;
        cout << " -------------------------------------------------------------------------" << endl;
        while(in>>name>>password>>balance)
        {
             if(username_login.compare(name) == 0 && password_login.compare(password) == 0 ){
                 cout << " (+) ACCOUNT USERNAME: " << name << endl;
                 cout << " (+) PASSWORD: " << password << endl;
                 cout << " (+) CASH: $" << balance << endl;

             }
           
          



        }

        in.close();
        

}
int main() {    

    
    int option; 

    double balance=0; 
    // double deposit,withdraw; 
    const char* adminusername = "admin";
    string inputadmin("admin");
    int res = -1;
    // string  inputadmin ;
    int password;
    int returned ;
    int choiceAdmin;
    string to_whom;
    string username_login;
    int userChoice;
    string password_login;
    float deposit , withdraw , transfer;

   

    
    do{ 

    menus: 
        showmenu(); 
        cout<<"Enter your options: ";

        cin>>option; 
        switch(option) {   

            case 1:
            cout << "Enter your admin username: ";
            cin >> inputadmin;
            adminpagererun:
               
                
                 cout << endl;
                

	             res = inputadmin.compare(adminusername);
                cout << "Enter admin password: ";

		        cin >> password;
                if(cin.fail()){
                    cout << "You have enetered incorrect input. Please try to enter only an integer!" << endl;
                    cin.clear();   
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
                    goto adminpagererun;
                 }

              

                if(password == 1234 && res == 0){
                    admin:
                    showadminmenu();
                    cout << "Select one: ";
                    cin >> choiceAdmin;
                    switch(choiceAdmin){
                        case 1:
                         system("cls");
                       returned = createUser();
                        if(returned == 1){
                            cout << "-------------------------------------" << endl;
                            cout << "Account have successfully created" << endl;
                            cout << "-------------------------------------" << endl;
                        }else {
                            cout << "Please try to create an account again.!" << endl;
                        }
                         goto admin;
                        //  break;
                        break;
                    
                        case 2:
                         system("cls");
                        returned = deleteUser();
                        if(returned == 0){
                            cout << "-------------------------------------" << endl;
                            cout << "Account have successfully deleted" << endl;
                            cout << "-------------------------------------" << endl;

                        }else {
                            cout << "Account has not been successfully deleted" << endl;

                        }
                        
                        goto adnin;
                         break;
                        case 3:
                        system("cls");
                         viewallusers();
                         goto admin;
                        case 4:
                         system("cls");

                    
                         cout << "Thanks Admin for using our services!" << endl;
                         goto menus;
                         break;
                        default:
                          cout << "Try out from the numbered option given below!"<< endl;
                          goto admin;
                          break;
                          








                    }

                     



                }else {
                    cout << "Please eneter the correct admin password " << endl;
                    cin.get();
                    goto adminpagererun;
                }

                goto menus;
                break;

            case 2: 
            
             
              cout << "Enter the username: ";
              cin >> username_login;
              cout << "Enter the passsword: ";
              cin >> password_login;
              if(isFound(username_login , password_login)){

                  user: 
                  showusermenu(username_login);
                  cout << "Select your choice: " ;
                  cin >> userChoice;
                  switch(userChoice){
                    case 1:
                     system("cls");
                     cout << "How much money you want to deposit: $ ";

                     cin >> deposit;
                     returned = updateDeposite(username_login , password_login , deposit); 
                     if(returned == 1){
                         cout << " (+) You have funded " << deposit << " $" << " to your account , " << username_login << endl;
                     }else {
                         cout << " (!) Funding to your account is not processed" << endl;
                     }
                   
                    goto user;
                     case 2:
                      system("cls");
                     cout << "Enter the amount of money you want to withdraw: ";
                     cin >> withdraw;
                     returned =  updateWithdraw(username_login , password_login , withdraw);
                     if(returned == 1) {
                         cout << " (-) You have successfully withdraw " << " $" << withdraw << endl;
                     }else {
                         cout << " (!) You dont have enough fund to cash out " << endl;
                     }
                      
                     goto user;
                     case 3:
                      system("cls");
                     cout << "Enter the username that you want to transfer a fund: " ;
                     cin >> to_whom;
                     
                     if(isRecieverExist(to_whom)){
                         cout << "Enter the amount you want to transfer to " << to_whom << ": " ;
                         cin >> transfer;

                        returned =  updateWithdraw(username_login , password_login , transfer);
                        if(returned == 1){
                            returned =  updateDepositeReceiver(to_whom  , transfer);
                            if(returned == 1){
                                cout << " (-) You have successfully transferred" << " $" << transfer << " to " << to_whom << endl;
                            }else {
                                cout << " (!) The Transfer has failed" << endl;
                            }
                            
                        }else {
                            cout << " (!) You dont have enough fund to transfer to  " << to_whom << endl;
                        }
                        // updateTransfer();
                         
                     }else {
                         cout << " (!) No such user to transfer the funds" << endl;
                     }
                    
                     goto user;
                     case 4:
                  
                       displayAccount(username_login , password_login);
                       
                     goto user;
                     case 5:
                     break;
                     goto menus;

                  }
              }else {
                  cout << " (!) Such account does not exist" << endl;
              }


            case 3:
                system("cls");
                showInfo();
                goto menus;
                break;
            case 4:
                cout << " (*) Thanks for banking with us" << endl;
                break;
                exit(0);
            default:
              cout << " (!) Please try to choose the number from 1 - 4 " << endl;
              goto menus;
            //   break;
            
        } 
        
    }while(option!=4);
   
    return 0; 
}