#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ISTracker.hpp"

using namespace std;



vector<Content> contents;

ostream& operator<<(ostream& os, const Content& c){
			os << c.name << "\t" <<
								c.organization << "\t" <<
								c.website << "\t" <<
								c.internship << "\t" <<
								c.scholarship << "\t" <<
								c.openDate << "\t" <<
								c.closeDate << "\t" <<
								c.startDate << "\t" <<
								c.result;
			return os;
}


bool saveList(){
	ofstream ofile("InternshipsAndScholarships.txt");
	if(!ofile.is_open()) return false;
	for(auto & c : contents){
		ofile<<c<<endl;
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
		string intern;
		if(!getline(ss, intern, '\t'))return false;
		string schol;
		if(!getline(ss, schol, '\t'))return false;
		string od;
		if(!getline(ss, od, '\t'))return false;
		string cd;
		if(!getline(ss, cd, '\t'))return false;
		string sd;
		if(!getline(ss, sd, '\t'))return false;
		string res;
		if(!getline(ss, res, '\t'))return false;
		Content c= Content(name, org, web, intern, schol, od, cd, sd, res);
		contents.push_back(c);
	}
	return true;
}

bool interfaceExit(){
	return saveList();
}

string CollectString(string msg){
	cout<<msg<<endl;
	string reply;
	getline(cin, reply);
	return reply;
}

void addEntry(){
	string name = CollectString("Entry Name: ");
	string org = CollectString("Entry Organization: ");
	string web = CollectString("Entry Website: ");
	string intern = CollectString("Is Entry an Internship? ");
	string schol = CollectString("Is Entry a Scholarship? ");
	string od = CollectString("Entry Opening Date: ");
	string cd = CollectString("Entry Closing Date: ");
	string sd = CollectString("Entry Starting Date: ");
	string res = CollectString("Entry Current Status: ");
	contents.push_back(Content(name, org, web, intern, schol, od, cd, sd, res));
	
	
}

void viewNext(){
	
}

void viewAll(){
	for(auto it = contents.begin(); it != contents.end(); ++it){
		cout<<*it<<endl;
	}
}

bool interface(){
	while (true) {
		cout << "What would you like to do?" << endl
		     << "- Add Entry" << endl
		     << "- View Next Due" << endl
		     << "- View All" << endl
		     << "- Exit" << endl;

		string command;
		
		getline(cin, command);

		if (command == "Add Entry") {
			addEntry();
		}
		else if (command == "View Next Due") {
			viewNext();
		}
		else if (command == "View All") {
			viewAll();
		}
		else if (command == "Exit") {
			return interfaceExit();
		}
		else {
			cout <<"Command was: " << command << "Please reply with: Add Entry, View Next Due, View All, or Exit" << endl;
		}
	}
}


int main(void){
	loadList();
	interface();
	
}

