#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	bool fOpen = false;			
	bool fClose = false;			
	bool fFunMult = false;
	bool oneString = false;			
	string sIn;					
	string result;					
	string resultMultiline = "";		
	size_t pos;			
	size_t posOp, posCl, posFun;		
	int k = 0, n = 0, i = 0;		
	ifstream f_in("test.txt");		
	ofstream f_out("test.txt", fstream::app);	
	if (!f_in)					
		cout << "Error!";

	f_out << '\n';				
	while (f_in) {				
		getline(f_in, sIn);		
		if (fFunMult == false) {		
			posOp = sIn.find("/**");	
			if (posOp != std::string::npos) {
				fOpen = true;	
				posCl = sIn.find("*/");	
				if (posCl != std::string::npos) {
					fClose = true;	
					oneString = true;	
				}
				else
					oneString = false;	
			}

			if (oneString == true) {		
				posFun = sIn.find("\\func");	
				if (posFun != std::string::npos) {
					k += 1;			
					result = sIn.substr(posFun + 6, posCl - (posFun + 6));	
												
					f_out << k << ". " << result << endl;			
					i = 0;
				}
				oneString = false;	
			}

			else if (fFunMult == false) {		
				posFun = sIn.find("\\func");	
				if (posFun != std::string::npos) {
					fFunMult = true;
				}
			}
		}
		if (fFunMult == true) {			
			posCl = sIn.find("*/");			
			if (posCl != std::string::npos) {	
				k += 1;				
				f_out << k << ". " << resultMultiline << endl;	
				i = 0;
				fFunMult = false;		
				fClose = true;			
				fOpen = false;			
				resultMultiline = "";  		
			}
			else {
				if (i == 0) {			
								
					resultMultiline = resultMultiline + sIn.substr(posFun + 6, posCl - (posFun + 6)) + '\n';
					i++;		
				}
				else
					resultMultiline = resultMultiline + sIn;
			}
		}
	}
	f_in.close();
	return 0;
}

