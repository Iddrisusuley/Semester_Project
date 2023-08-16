#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void encryptDecrypt(char *input,char *output){
	char key[]={'P','F','L'};
	int keyLength = sizeof(key)/sizeof(*key);
	int i;
	
	for (i=0;i<strlen(input); i++){
		output[i]=input[i] ^ key[i%keyLength];}} 

int main(int argc, char** argv) {
     
	        //VARIABLES
	string username, password, inputedPassword,Username, prgrmPassword="00000";
	char encrypted[100], decrypted[100], choice,option;
	
  
  	while(true){
     	  //WELCOME WINDOW
		cout<<"\n";
		cout<<"1. SAVE CREDENTIALS.\n2. RETRIEVE A SAVED CREDENTIAL.\n3. EXIT PROGRAM.\n";
		cout<<"SELECT 1-3: ";
		cin>>choice;
		cin.ignore();
		
		//OPTIONS
		if(choice=='1'){
			bool available=true;
			ofstream file("passwords.txt", ios::app);
			cout<<"Enter Username: ";
			getline(cin, username);
			cout<<"Enter Password: ";
			getline(cin, password);
			encryptDecrypt(&password[0], encrypted);
			file<<username<<" "<<encrypted<<endl;
			file.close();
			cout<<" "<<endl;
			cout<<"The new username is :"<<username<<endl;
			cout<<"The new password is :"<<password<<endl;
			cout<<"Press 1 to save or 2 to cancel :";
			cin>>option;
			if(option=='1'){cout<<"Account saved.";break;}
			else cout<<"Saving interrupted. Quiting...";break;}
		
		
		else if(choice=='2'){
			ifstream file("passwords.txt");
			bool found=false;
			cout<<"Enter username: ";
			getline(cin, Username);
			while(file>>username>>encrypted){
				encryptDecrypt(encrypted,decrypted);
				if(Username==username){
					found=true;
	cout<<"Enter the password of the program to continue\n";
	getline(cin, inputedPassword);
	if(inputedPassword!=prgrmPassword){
	cout<<"Invalid Password. Quiting...\n";return 0;}
					else cout<<"The password for "<<username<<" is "<<decrypted<<endl;return 0;}}
					file.close();
					if(!found){
				cout<<"Username not available. kindly save the account info. before trying to retrieve it."; return 0;}}
				
		
		
		 else if(choice=='3'){
			cout<<"Thank you for using our program.\nProgram Exiting..."; break;}
			
		//INVALID OPTION
		else cout<<"\nInvalid Input.\nPlease Try Again.\n \n";
		}}

	

	
	

