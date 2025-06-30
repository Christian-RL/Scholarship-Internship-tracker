#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Content{
		string name;
		string organization;
		string website;
		bool internship;
		bool scholarship;
		string openDate;
		string closeDate;
		string startDate;
	public:
		Content(string n, string o, string w, bool i, bool s, string oD, string cD, string sD) : name(n), organization(o), website(w), internship(i), scholarship(s), openDate(oD), closeDate(cD), startDate(sD){}
		
		string getName(){return name;}
		string getOrganization(){return organization;}
		string getWebsite(){return website;}
		bool isInternship(){return internship;}
		bool isScholarship(){return scholarship;}
		string getoD(){return openDate;}
		string getcD(){return closeDate;}
		string getsD(){return startDate;}
		
		string toString(){
			string intV;
			string scholV;
			if(internship) intV = "Yes";
			else intV = "";
			if(scholarship) scholV = "Yes";
			else scholV = "";
			
			string toReturn = name + "\t" + 
								organization + "\t" +
								website + "\t" +
								intV + "\t" +
								scholV + "\t" +
								openDate + "\t" +
								closeDate + "\t" +
								startDate;
			return toReturn;
		}
};

vector<Content> contents;


bool saveList(){
	ofstream ofile("InternshipsAndScholarships.txt");
	if(!ofile.is_open()) return false;
	for(auto & c : contents){
		ofile<<c.toString()<<endl;
	}
	return true;
}


bool loadList(){
	ifstream infile("InternshipsAndScholarships.txt");
	if(!infile.is_open()) return false;
	string line;
	while(getline(infile, line)){
		istringstream ss(line);
		string name;
		if(!getline(ss, name, '\t'))return false;
		string org;
		if(!getline(ss, org, '\t'))return false;
		string web;
		if(!getline(ss, web, '\t'))return false;
		bool in;
		string intern;
		if(!getline(ss, intern, '\t'))return false;
		if(intern == "Yes") in = true;
		else in = false;
		bool s;
		string schol;
		if(!getline(ss, schol, '\t'))return false;
		if(schol == "Yes") s = true;
		else s = false;
		string od;
		if(!getline(ss, od, '\t'))return false;
		string cd;
		if(!getline(ss, cd, '\t'))return false;
		string sd;
		if(!getline(ss, sd, '\t'))return false;
		Content c= Content(name, org, web, in, s, od, cd, sd);
		contents.push_back(c);
	}
	return true;
}

bool interfaceExit(){
	return saveList();
}

void addEntry(){
	
}

void viewNext(){
	
}

void viewAll(){
	
}

bool interface(){
	cout<<"What would you like to do?"<<
		"- Add Entry"<<
		"- View Next Due"<<
		"- View All"<<
		"- Exit"<<endl;
		
	string command;
	cin>>command;
	bool invalid = true;
	while(invalid){
		if(command == "Add Entry"){
			 addEntry();
			 invalid = false;
		 }
		else if(command == "View Next Due"){
			 viewNext();
			 invalid = false;
		 }
		else if(command == "View all"){
			 viewAll();
			 invalid = false;
		 }
		else if(command == "Exit"){
			return interfaceExit();
		}
		 else{
			 cout<<"Please reply with: Add Entry, View Next Due, View All, or Exit"<<endl;
		 }		
	}
	return interface();
}


int main(void){
	if(!loadList()) exit(1);
	if(!interface()) exit(2);
	
}
