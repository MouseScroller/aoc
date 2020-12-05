#include<iostream>
#include <stdexcept>
#include <string>
#include<map>
#include<fstream>
#include <sstream>
#include<regex>
#include <vector>

int main(int args,char ** argv){

	if(args != 2){
		return 0;
	}
	std::map<std::string,std::string> m;
	std::ifstream file;
	file.open(std::string(argv[1]));
	std::string line;
	std::vector<int> seat_id;
	int r,c;
	while(getline(file,line)){
		r=0;
		c=0;
		if(line[0] == 'B'){
			r+=64;
		}
		if(line[1] == 'B'){
			r+=32;
		}
		if(line[2] == 'B'){
			r+=16;
		}
		if(line[3] == 'B'){
			r+=8;
		}
		if(line[4] == 'B'){
			r+=4;
		}
		if(line[5] == 'B'){
			r+=2;
		}
		if(line[6] == 'B'){
			r+=1;
		}
		if(line[7] == 'R'){
			c+=4;
		}
		if(line[8] == 'R'){
			c+=2;
		}
		if(line[9] == 'R'){
			c+=1;
		}
		//std::cout << "r" << r << " c" << c << " id" << r*8+c << std::endl;
		seat_id.push_back(r*8+c);
	}
	auto it = max_element(std::begin(seat_id), std::end(seat_id));
	std::cout << "max "<< *it  <<std::endl;
	int t;
	for(auto && i : seat_id){
		t = 0;
		for (auto && j : seat_id) {
			if((i +1) == j){
				t+=10;
				break;
			}
		}
		for (auto && j : seat_id) {
			if((i +2) == j){
				t++;
				break;
			}
		}
		if(t == 1){
			std::cout << (i+1) << std::endl;
		}
	}
};
