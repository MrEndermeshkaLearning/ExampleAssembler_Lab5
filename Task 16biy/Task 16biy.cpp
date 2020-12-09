#include <iostream>
#include <cstdlib>

//MAKE C++(NOT C)///
//variant 30
using namespace std;
int main()
{
	short int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	//x=int(x); прямое приведение к типу инт если так не сделать то будем работать с символами,
	// ибо char это символьный тип данных
	cout << "Insert a" << endl; // cout = printf, endl = \n
	cin >> a; a = short int(a); // cin = scanf 
	cout << "Insert b" << endl;
	cin >> b; b = short int(b);
	cout << "Insert c" << endl;
	cin >> c; c = short int(c);
	cout << "Insert d" << endl;
	cin >> d; d = short int(d);
	cout << "Insert e" << endl;
	cin >> e; e = short int(e);
	cout << "Insert f" << endl;
	cin >> f; f = short int(f);
	short int res_asm;
	short int answer = (c * 4 + 28 / d - e) / (a * d - c - 1 + f);

	// важен порядок bl может поделить только al (al/bl), cl он уже не поделит и всё сломаеться
	_asm {
		mov cx, [c];
		imul cx, 4;
		mov ax, 28;
		cwd;	
		idiv [d];
		add ax, cx;
		sub ax, [e];
		cwd;
		mov bx, [a];
		imul bx, [d];
		sub bx, [c];
		sub bx, [1];
		add bx, [f];
		idiv bx;
		mov res_asm, ax;
	}
	cout << "Answer from Asembler " << short int(res_asm) << endl;
	cout << "Answer from C++ " << short int(answer) << endl;

}