#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

int main(int i,char ** v){
	if(i != 2){
		return 0;
	}
	int a,b;
	char c;
	char * d;
	FILE * f = std::fopen(v[1],"r");
	int h = 0,g = 0;
	while(true){
		if(fscanf(f,"%i-%i %c: %s",&a,&b,&c,d) != 4){
			break;
		}
		int u = std::count(d, d + strlen(d), c);
		if(u >= a && u <= b){
			h++;
		}
		if( ((d[a-1] == c) || (d[b-1] == c)) && d[a-1] != d[b-1]){
			g++;
		}
	}
	std::cout << h << "|" << g << std::endl;
};
