#include <iostream>
#include <string>
using namespace std;

void pryam_obh(int n, int*p, int koren){
	for (int i = 0; i < n; i++){
		if (p[i] == koren){
			cout << i << " ";
			pryam_obh(n, p, i); 
		} 
	}
}

void obr_obh(int n,int *p, int koren){
	for (int i = 0; i < n; i++){
		if (p[i] == koren){
			obr_obh(n, p, i);
			cout << i << " ";
		}
	}
}

void sim_obh(int n, int *p, int koren) {
	int first_children_i = -2;
	for (int i = 0; i < n; i++) {
		if (p[i] == koren) {
			sim_obh(n, p, i);
			first_children_i = i;
			break;
		}
	}
	if (koren != -1) cout << koren << " ";
	if (first_children_i != -1) {
		for (int i = first_children_i + 1; i < n; i++) {
			if (p[i] == koren) {
				sim_obh(n,p,i);
			}
		}
	}
}

void main(){
	int n, *p=0; string s;
	cout << "n=";  cin >> n;
	cin.get();
	cout << "vvedite massiv\n";  getline(cin, s); 
	p = new int[n];
	for (int i = 0; i < n; i++){
		p[i] = atoi(s.substr(0, s.find(" ", 0)).c_str());
		s.erase(0, s.find(" ", 0) + 1);
	}
	pryam_obh(n, p, -1); cout << endl;
	obr_obh(n, p, -1); cout << endl;
	sim_obh(n, p, -1); cout << endl;
	system("pause");
}

