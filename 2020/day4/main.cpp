#include<iostream>
#include <stdexcept>
#include <string>
#include<map>
#include<fstream>
#include <sstream>
#include<regex>

int main(int args,char ** argv){

	if(args != 2){
		return 0;
	}
	int c =0;
	std::map<std::string,std::string> m;
	std::ifstream file;
	file.open(std::string(argv[1]));
	std::string line;
	auto pos = 0,pos2=0;
	while(getline(file,line)){
		if(line.length() == 0){
			if(m["byr"]!="" && std::stoi(m["byr"]) >= 1920 && std::stoi(m["byr"]) <= 2002 && m["iyr"]!="" && std::stoi(m["iyr"]) >= 2010 && std::stoi(m["iyr"]) <= 2020 && m["eyr"]!="" && std::stoi(m["eyr"]) >= 2020 && std::stoi(m["eyr"]) <=2030 && std::regex_match(m["hgt"],std::regex("^(1([5-8][0-9]|9[0-3])cm|(59|7[0-6]|6[0-9])in)$")) && std::regex_match(m["hcl"],std::regex("^#[0-9a-f]{6}$")) && std::regex_match(m["ecl"],std::regex("^(amb|blu|brn|gry|grn|hzl|oth)$")) && std::regex_match(m["pid"],std::regex("^[0-9]{9}$"))){
				c++;
			}
			m["byr"]="";m["iyr"]="";m["eyr"]="";m["hgt"]="";m["hcl"]="";m["ecl"]="";m["pid"]="";m["cid"]="";
			continue;
		}
		while( (pos=line.find(" ")) != std::string::npos){
			std::string a = line.substr(0,pos);
			if( (pos2=a.find(":")) != std::string::npos){
				m[a.substr(0,pos2)] = a.substr(pos2+1,std::string::npos-1);
				a = a.substr(pos2,std::string::npos);
			}
			line = line.substr(pos+1,std::string::npos);
		}
		std::string a = line.substr(0,pos);
			if( (pos2=a.find(":")) != std::string::npos){
				m[a.substr(0,pos2)] = a.substr(pos2+1,std::string::npos-1);
				a = a.substr(pos2,std::string::npos);
			}
	}
	if(m["byr"]!="" && std::stoi(m["byr"]) >= 1920 && std::stoi(m["byr"]) <= 2002 && m["iyr"]!="" && std::stoi(m["iyr"]) >= 2010 && std::stoi(m["iyr"]) <= 2020 && m["eyr"]!=""  &&std::stoi(m["eyr"]) >= 2020 && std::stoi(m["eyr"]) <=2030 && std::regex_match(m["hgt"],std::regex("^(1([5-8][0-9]|9[0-3])cm|(59|7[0-6]|6[0-9])in)$")) && std::regex_match(m["hcl"],std::regex("^#[0-9a-f]{6}$")) && std::regex_match(m["ecl"],std::regex("^(amb|blu|brn|gry|grn|hzl|oth)$")) && std::regex_match(m["pid"],std::regex("^[0-9]{9}$"))){
		c++;
	}
	std::cout << c << std::endl;




};
