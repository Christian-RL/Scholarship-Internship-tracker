#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Content{
		string name;
		string organization;
		string website;
		string internship;
		string scholarship;
		string openDate;
		string closeDate;
		string startDate;
		string result;
	public:
		Content(string n, string o, string w, string i, string s, string oD, string cD, string sD, string res) : name(n), organization(o), website(w), internship(i), scholarship(s), openDate(oD), closeDate(cD), startDate(sD), result(res){}
		
		string getName(){return name;}
		string getOrganization(){return organization;}
		string getWebsite(){return website;}
		string isInternship(){return internship;}
		string isScholarship(){return scholarship;}
		string getoD(){return openDate;}
		string getcD(){return closeDate;}
		string getsD(){return startDate;}
		string getRes(){return result;}
		friend ostream& operator<<(ostream& os, const Content& c);
		
		string display(){
			ostringstream oss;
			oss << "Name: " << name << endl <<
					"Organization: " << organization << endl <<
					"Website: " << website << endl <<
					"Is an Internship: " << internship << endl <<
					"Is a Scholarship: " << scholarship << endl <<
					"Application Open Date: " << openDate << endl <<
					"Application Close Date: " << closeDate << endl <<
					"Effective Start Date: " << startDate << endl <<
					"Current Result of Application: " << result << endl << endl;
			return oss.str();
					
		}
		
		
};


