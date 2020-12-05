#include<iostream>
#include<string>
#include<fstream>

int main(int args,char ** argv){
	if(args != 2){
		return 0;
	}
	std::ifstream file;
	file.open(std::string(argv[1]));
	std::string line;
	int d = 1;
	int r = 1;
	int cd = 1;
	int cr = 0;
	int l = 1;
	int c = 0;
	while(true){

	file.clear();
	file.seekg(0, std::ios::beg);

	getline(file,line);

	//std::cout << line << std::endl;
	cr+=r;
		while(true){

			if(d == 2){
				getline(file,line);
				if(line.length() == 0){
					break;
				}
				//std::cout << line << std::endl;
			}

			getline(file,line);

			if(line.length() == 0){
				break;
			}

			int p = cr % line.length();
			if(line[p] == '#'){
				c++;
				line[p] = 'X';
			} else {
				line[p] = '0';
			}

			//std::cout << line << std::endl;
			cr+=r;

		}
	std::cout << "down" << d << " rigth" << r << " | " << c << std::endl;
	c = 0;
	cr= 0;
	r++;
	r++;
	if(d == 2){
		break;
	}

	if(r == 9){
		d=2;
		r = 1;
	}
	}

}
