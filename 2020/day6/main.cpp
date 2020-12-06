#include<iostream>
#include<stdexcept>
#include<string>
#include<map>
#include<fstream>
#include<regex>

int main(int args,char ** argv){

	if(args != 2){
		return 0;
	}
	int c =0;
	std::ifstream file;
	file.open(std::string(argv[1]));
	std::string line;
	std::map<char,int> m;
	int i;
	while(getline(file,line)){
		if(line.length() == 0){
			for (auto && v : m) {
				if(v.second == i){
					c++;
				}
			}
			m.clear();
			i = 0;
			continue;
		}
		i++;
		for (auto && c : line) {
			if(m[c] != 0){
				m[c] = (m[c]+1);
			} else {
				m[c] = 1;
			}
		}
	}
	for (auto && v : m) {
				if(v.second == i){
					c++;
				}
			}
	std::cout << c << std::endl;
	return 0;
}
