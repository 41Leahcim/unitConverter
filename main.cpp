#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

double mod(double a, double b) {
	return a - (int)(a / b) * b;
}

void convert(vector<string> Tunits, vector<double> units) {
	float choice[3];
	cout << "You have choosen to convert units of distance.\nWhich unit do you want to convert?\n\t";
	for (int i = 0; i < Tunits.size(); i++) {
		cout << i << ") " + Tunits[i] + "\n\t";
	}
	cin >> choice[0];
	choice[0] = mod(choice[0],units.size());
	cout << "How much of that unit do you wan to convert? ";
	cin >> choice[1];
	cout << "Which unit do you want to convert it to? ";
	cin >> choice[2];
	choice[2] = mod(choice[2],Tunits.size());
	cout << choice[1] << Tunits[choice[0]] + " is equal to " << choice[1] * units[choice[0]] / units[choice[2]] << Tunits[choice[2]] + "\n\n";
}

int main()
{
	cout << "Program can only convert integers and results will also be integers.\n";
	//units of distance
	vector<double> Dunits{ 0.001,0.01,0.0254,0.1,0.3048,0.9144,1,10,100,1000,1609.344 };
	vector<string> TDunits{ "milimeters","centimeters","inches","decimeters","feet","yards","meters","decameters","hectometers","kilometers","miles" };
	
	//units of volume
	vector<double> Vunits{0.001,0.00492892,0.00591939,0.01,0.0147868,0.0177582,0.1,1,3.7854,4.54609,10};
	vector<string> TVunits{"millilitres","teaspoons(US)","teaspoons(imperial)","centilitres","tablespoons(US)","tablespoons(imperial)","decilitres","litres",
		"gallon(US)","gallons(imperial)","decalitres"};
	//units of time
	vector<double> Tunits{1/3600,1/60,1,24,24*365.25};
	for (int i = 4; i < 7; i++) Tunits.push_back(Tunits[i] * 10);
	vector<string> TTunits{"seconds","minutes","hours","days","years","decades","centuries","millennia"};
	
	//units of speed
	vector<double> Sunits{1, 1.09728 ,1.609344 ,1.852001 ,3.6};
	vector<string> TSunits{"km per hour","feet per second","miles per hour","knot","meters per second"};
	int choice;
	do {
		cout << "What do you want to convert?\n\t1) units of distance\n\t2) units of volume\n\t3) units of time\n\t4) units of speed\n\t0) nothing\n\t";
		cin >> choice;
		choice %= 5;
		cout << "\n\n";
		switch (choice) {
		case 0:
			cout << "You have choosen to stop the program. It will close when you enter a value.\n";
			cin >> choice;
			return 0;
		case 1:
			convert(TDunits, Dunits);
			break;
		case 2:
			convert(TVunits, Vunits);
			break;
		case 3:
			convert(TTunits, Tunits);
			break;
		case 4:
			convert(TSunits, Sunits);
			break;
		default:
			cout << "Something went wrong.\nMail the maker of this program at \"michael-scholten@hotmail.nl\" with the error file attached.\n";
			ofstream f("errorFile.txt");
			f << "Error message: " << choice;
			f.close();
			cin >> choice;
			return 1;
		}
	} while (1);
}