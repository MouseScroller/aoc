#include <cstdio>
#include <iostream>
#include <vector>

int main(int a,char ** v){
	std::cout << a << "|" << v[1] << std::endl;
	if(a != 2){
		return 0;
	}
	std::vector<int> l;
	int r;
	FILE * f = std::fopen(v[1],"r");
	while(true){

		if(fscanf(f,"%i",&r) != 1){
			break;
		}
		l.push_back(r);
		for (int & e : l) {
			if(e + r == 2020){
				std::cout << e << " | " << r << " * " << e * r << std::endl;
			}
			for (int & g : l) {
				if(r + g + e == 2020){
					std::cout << e << " | " << r << " | " << g << " * " << e * r * g << std::endl;
				}
			}
		}
	}
};
