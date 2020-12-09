#include <iostream>
#include <cstdlib>

//MAKE C++(NOT C)///
//variant 30
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	//x=int(x); прямое приведение к типу инт если так не сделать то будем работать с символами,
	// ибо char это символьный тип данных
	cout << "Insert a" << endl; // cout = printf, endl = \n
	cin >> a;; // cin = scanf 
	cout << "Insert b" << endl;
	cin >> b;
	cout << "Insert c" << endl;
	cin >> c;
	cout << "Insert d" << endl;
	cin >> d; 
	cout << "Insert e" << endl;
	cin >> e;
	cout << "Insert f" << endl;
	cin >> f;
	int res_asm;
	int answer = (c * 4 + 28 / d - e) / (a * d - c - 1 + f);

	// важен порядок bl может поделить только al (al/bl), cl он уже не поделит и всё сломаеться
	_asm {
		mov ecx, [c];
		imul ecx, 4;
		mov eax, 28;
		cwd;
		idiv[d];
		add eax, ecx;
		sub eax, [e];
		cwd;
		mov ebx, [a];
		imul ebx, [d];
		sub ebx, [c];
		sub ebx, [1];
		add ebx, [f];
		idiv ebx;
		mov res_asm, eax;
	}
	cout << "Answer from Asembler " << short int(res_asm) << endl;
	cout << "Answer from C++ " << short int(answer) << endl;

}