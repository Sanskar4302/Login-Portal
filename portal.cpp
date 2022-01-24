#include<iostream>
#include<fstream>
using namespace std;
 void printStrongNess(string& input) {
   int n = input.length();
   
   bool hasLower = false, hasUpper = false;
   bool hasDigit = false, specialChar = false;
   string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
   for (int i = 0; i < n; i++) {
      if (islower(input[i]))
         hasLower = true;
      if (isupper(input[i]))
         hasUpper = true;
      if (isdigit(input[i]))
         hasDigit = true;
      size_t special = input.find_first_not_of(normalChars);
      if (special != string::npos)
         specialChar = true;
   }

   cout << "Strength of password:-";
   if (hasLower && hasUpper && hasDigit &&
      specialChar && (n >= 8))
      cout << "Strong" << endl;
   else if ((hasLower || hasUpper) &&
      specialChar && (n >= 6))
      cout << "Moderate" << endl;
   else
      cout << "Weak" << endl;
}
int main()
{
    string
    command, 
    name, password, 
    inName, inPassword, 
    registerName, registerPassword; 
    while (1)
    {
        cout<<"(register/exit/login)\n"
            <<"Command: ";
        getline(cin, command);
        
        if (command=="exit") 
        {
            return 1;
        }
        if (command=="register")
        {
            ofstream g("registration.txt"); 
            if (!g.is_open()) 
            {
                cout<<"could not open file\n"; 
                return 0;
            }
            cout<<"\n\n\n" 
                <<"New Username: ";
            getline(cin, registerName); 
            cout<<"New Password: ";
            getline(cin, registerPassword); 
            
    printStrongNess(registerPassword);
    
            g<<registerName; 
            g<<'\n'; 
            g<<registerPassword; 
            g.close();
        }
        if (command=="login") 
        {
            
            ifstream f("registration.txt"); 
            if (!f.is_open()) 
            {
                cout<<"could not open file\n"; 
                return 0;
            }
            getline(f, name, '\n'); 
            getline(f, password, '\n'); 
            f.close(); 

            
            while (1)
            {
                
                cout<<"\n\n\n"
                    <<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n" 
                        <<"Welcome, "
                        <<inName;
                    break;
                }
                cout<<"incorrect name or password\n"; 
            }
            
        }
        cout<<"\n\n\n\n\n"; 
    }
    return 1;
}
