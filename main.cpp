#include <iostream>
#include <map>
#include <vector>

void addUnits(std::vector<std::map<std::string, double>>& units){
    // add units of distance
    units[0].insert(std::pair<std::string, double>("mm", 1));
    units[0].insert(std::pair<std::string, double>("cm", 10));
    units[0].insert(std::pair<std::string, double>("i", 25.4));
    units[0].insert(std::pair<std::string, double>("dm", 100));
    units[0].insert(std::pair<std::string, double>("f", 304.8));
    units[0].insert(std::pair<std::string, double>("y", 914.4));
    units[0].insert(std::pair<std::string, double>("m", 1000));
    units[0].insert(std::pair<std::string, double>("Dm", 10000));
    units[0].insert(std::pair<std::string, double>("Hm", 100000));
    units[0].insert(std::pair<std::string, double>("Km", 1000000));
    units[0].insert(std::pair<std::string, double>("M", 1609344));

    // add units of time
    units[1].insert(std::pair<std::string, double>("s", 1));
    units[1].insert(std::pair<std::string, double>("m", 60));
    units[1].insert(std::pair<std::string, double>("h", 3600));
    units[1].insert(std::pair<std::string, double>("d", 3600 * 24));
    units[1].insert(std::pair<std::string, double>("w", 3600 * 24 * 7));
    units[1].insert(std::pair<std::string, double>("y", 3600 * 24 * 365.25));

    // add units of temperature
    units[2].insert(std::pair<std::string, double>("K", 1));
    units[2].insert(std::pair<std::string, double>("C", 2));
    units[2].insert(std::pair<std::string, double>("F", 3));
}

void getValueUnit(std::pair<double, std::string>& valueUnit){
    std::cout << "Available distance units: mm (millimeters), cm (centimeters), i (inches), dm (decimeters), f (feet), y (yard), m (meters), Dm (decameters), Hm (hectometers), Km (kilometers), M (mile)\n";
    std::cout << "Available time units: s (seconds), m (minutes), h (hours), d (days), w (weeks), y (years)\n";
    std::cout << "Available temperature units: K (kelvin), C (celsius), F (fahrenheit)\n\n";
    std::cout << "Enter the amount: ";
    std::cin >> valueUnit.first;
    std::cout << "Enter the unit: ";
    std::cin >> valueUnit.second;
}

void getUnitTo(std::string& unit){
    std::cout << "Enter the unit to convert to: ";
    std::cin >> unit;
}

uint8_t checkUnits(const std::pair<double, std::string>& from, const std::pair<double, const std::string>& to, const std::vector<std::map<std::string, double>>& units){
    uint8_t i;
    for(i = 0;i < units.size();i++){
        if(units[i].find(from.second) != units[i].end() && units[i].find(to.second) != units[i].end()){
            return i;
        }
    }
    return 3;
}

void convert(const std::pair<double, std::string>& from, std::pair<double, std::string>& to, const std::map<std::string, double>& units){
    to.first = from.first * units.find(from.second)->second / units.find(to.second)->second;
}

void convertTemperature(const std::pair<double, std::string>& from, std::pair<double, std::string>& to){
    if(from.second == "K" && to.second == "C"){
        to.first = from.first - 273.15;
    }else if(from.second == "K" && to.second == "F"){
        to.first = (from.first - 273.15) * 1.8 + 32;
    }else if(from.second == "C" && to.second == "K"){
        to.first = from.first + 273.15;
    }else if(from.second == "C" && to.second == "F"){
        to.first = from.first * 1.8 + 32;
    }else if(from.second == "F" && to.second == "K"){
        to.first = (from.first - 32) / 1.8 + 273.15;
    }else if(from.second == "F" && to.second == "C"){
        to.first = (from.first - 32) / 1.8;
    }else{
        to.first = from.first;
    }
}

void printResult(const std::pair<double, std::string>& from, std::pair<double, std::string>& to){
    std::cout << from.first << " " << from.second << " <=> " << to.first << " " << to.second << "\n";
}

int main(){
    std::pair<double, std::string> from, to;
    std::map<std::string, double> distanceUnits;
    std::map<std::string, double> timeUnits;
    std::map<std::string, double> temperatureUnits;
    std::vector<std::map<std::string, double>> units = {distanceUnits, timeUnits, temperatureUnits};
    while(1){
        addUnits(units);
        getValueUnit(from);
        getUnitTo(to.second);
        switch(checkUnits(from, to, units)){
            case 0:
                convert(from, to, units[0]);
                printResult(from, to);
                break;
            case 1:
                convert(from, to, units[1]);
                printResult(from, to);
                break;
            case 2:
                convertTemperature(from, to);
                printResult(from, to);
                break;
            default:
                std::cout << "Invalid units: '" << from.second << "' => '" << to.second << "'\n";
        }
        std::cin.clear();
        std::cin.get();
        std::cout << "\n\n\n\n";
    }
}
