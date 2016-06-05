#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(){
	ifstream fin; int k = 0;
	char a[20]; string str;
	cout << "name of file: "; cin >> a;
	fin.open(a);
	while (!fin.eof()){
		getline(fin, str); 
		if (str == "/**"){
			while (str != "*/"){
				getline(fin, str);
				if (str != "*/") { 
					if (str.find("\\func") != -1){ 
						k++;
						cout << k <<". "<< str.substr(str.find("\\func") + 6) << endl; }
				}
			}
		}
		if (str.find("/**")!=-1){
			if (str.find("\\func")!=-1){
				k++;
				cout<< k <<". "<< str.substr(str.find("\\func") + 6,str.length()-str.find("\\func")-9)<<endl;
			}
		}
	}
	fin.close();
	getch();
	return 0;
}


