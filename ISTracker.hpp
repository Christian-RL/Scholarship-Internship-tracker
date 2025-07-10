#include <string>

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
