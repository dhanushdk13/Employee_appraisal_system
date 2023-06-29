#include<iostream>
#include<bits/stdc++.h>
using namespace std;

namespace appraisal{
    class login{
        private:
            map<string,string> emp;
            map<string ,string> manager;
            map<string, string> Hr;
    
            int role;
            string username;
            string password;
        public:
            string cur_user;
            int cur_role;
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
                        cur_user = username;
                        cur_role = 1;
                    }
                }
                else if(manager.find(username) != manager.end()){
                    if(manager[username] == password){
                        cout<<"Login successful "<<username<<endl;
                        cur_user = username;
                        cur_role = 2;
                    }
                }
                else if(Hr.find(username) != Hr.end()){
                    if(Hr[username] == password){
                        cout<<"Login successful "<<username<<endl;
                        cur_user = username;
                        cur_role = 3;
                    }
                }
                else{
                    cout<<"Invalid username or password"<<endl;
                }
            }
    };


    class employee{
        private:
            login lo;
            int rating1;
            int rating2;
            int rating3;
            int rating4;
        public:
            void give_rating(login& lo){
                string user = lo.cur_user;

                cout<<"Enter rating for task1: "<<endl;
                cin>>rating1;
                cout<<"Enter rating for task2: "<<endl;
                cin>>rating2;
                cout<<"Enter rating for task3: "<<endl;
                cin>>rating3;
                cout<<"Enter rating for task4: "<<endl;
                cin>>rating4;

                write_ratings_to_file(user);
            }

            void write_ratings_to_file(string& user) {
                ofstream file("emp_rating.txt",ios::app);  

                if (file.is_open()) {
                    file << user << " "<< rating1 << " " << rating2 << " " << rating3 << " " << rating4 << endl;

                    cout << "Ratings written to file successfully." << endl;

                    file.close();  
                }
                else {
                    cout << "Unable to open the file." << endl;
                }
            }


    };
}

int main(){

    appraisal::login l;



    while(true){
        cout<<"Enter choice: "<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Signup"<<endl;
        cout<<"3. Exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                l.log();
                if(l.cur_role == 1){
                    appraisal::employee e;
                    e.give_rating(l);
                }
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

   //
    /*else if(cur_role == 2){
        //appraisal::manager m;
    }
    else if(cur_role == 3){
        //appraisal::hr h;
    }
    else{
        cout<<"Invalid role"<<endl;
    }*/



   
    return 0;

}


