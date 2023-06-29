#include<iostream>
#include<bits/stdc++.h>
using namespace std;

namespace login{
    class login{
        private:
            map<string,string> emp;
            map<string ,string> manager;
            map<string, string> Hr;
            int role;
            string username;
            string password;
        public:
            void signup(){
                if (emp.empty() && manager.empty() && Hr.empty()) {
            
                ifstream file("login.txt");
                string uname, pwd;
                int role;

                if (!file) {
                    cout << "Error opening file: login.txt" << endl;
                    return;
                }

                while (file >> role >> uname >> pwd) {
                    switch (role) {
                        case 1:
                            emp.insert({uname, pwd});
                            break;
                        case 2:
                            manager.insert({uname, pwd});
                            break;
                        case 3:
                            Hr.insert({uname, pwd});
                            break;
                        default:
                            cout << "Invalid role" << endl;
                            break;
                        }
                    }

                file.close();
                }

                cout << "Enter username: " << endl;
                cin >> username;
                cout << "Enter password: " << endl;
                cin >> password;
                cout << "Enter role: " << endl;
                cout << "1. Employee" << endl;
                cout << "2. Manager" << endl;
                cout << "3. HR" << endl;
                cin >> role;

                ofstream outfile("login.txt", ios::app);
                if (outfile) {
                    outfile << role << " " << username << " " << password << endl;
                    outfile.close();
                } else {
                    cout << "Error opening file: login.txt" << endl;
                }
                switch(role){
                    case 1:
                        emp.insert(pair<string,string>(username,password));
                        break;
                    case 2:
                        manager.insert(pair<string,string>(username,password));
                        break;
                    case 3:
                        Hr.insert(pair<string,string>(username,password));
                        break;
                    default:
                        cout<<"Invalid role"<<endl;
                        break;
                }

                
            }
            void log(){


                ifstream file("login.txt");
                string uname, pwd;
                int role;

                if (!file) {
                    cout << "Error opening file: login.txt" << endl;
                    return;
                }

                while (file >> role >> uname >> pwd) {
                    switch (role) {
                        case 1:
                            emp.insert({uname, pwd});
                            break;
                        case 2:
                            manager.insert({uname, pwd});
                            break;
                        case 3:
                            Hr.insert({uname, pwd});
                            break;
                        default:
                            cout << "Invalid role" << endl;
                            break;
                        }
                    }

                file.close();


                cout<<"Enter username: "<<endl;
                cin>>username;
                cout<<"Enter password: "<<endl;
                cin>>password;              
                if(emp.find(username) != emp.end()){
                    if(emp[username] == password){
                        cout<<"Login successful "<<username<<endl;
                    }
                }
                else if(manager.find(username) != manager.end()){
                    if(manager[username] == password){
                        cout<<"Login successful "<<username<<endl;
                    }
                }
                else if(Hr.find(username) != Hr.end()){
                    if(Hr[username] == password){
                        cout<<"Login successful "<<username<<endl;
                    }
                }
                else{
                    cout<<"Invalid username or password"<<endl;
                }
            }
    };
}

int main(){



    login::login l;
    while(true){
        cout<<"1. Login"<<endl;
        cout<<"2. Signup"<<endl;
        cout<<"3. Exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                l.log();
                break;
            case 2:
                l.signup();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }

   
    return 0;

}


