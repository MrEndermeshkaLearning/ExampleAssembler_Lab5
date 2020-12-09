#include <iostream>
#include <cstdlib>

//MAKE C++(NOT C)///
//variant 30
using namespace std;
int main()
{
	unsigned char a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	//x=int(x); прямое приведение к типу инт если так не сделать то будем работать с символами,
	// ибо char это символьный тип данных
	cout << "Insert a" << endl; // cout = printf, endl = \n
	cin >> a; a = int(a); // cin = scanf 
	cout << "Insert b" << endl;
	cin >> b; b = int(b);
	cout << "Insert c" << endl;
	cin >> c; c = int(c);
	cout << "Insert d" << endl;
	cin >> d; d = int(d);
	cout << "Insert e" << endl;
	cin >> e; e = int(e);
	cout << "Insert f" << endl;
	cin >> f; f = int(f);
	signed char res_asm;;
	signed char answer = (c * 4 + 28 / d - e) / (a * d - c - 1 + f);
	// важен порядок bl может поделить только al (al/bl), cl он уже не поделит и всё сломаеться
	// signed char (8 bit) может не влезьть и быть не одинково, но дальше должно совпадать(16,32 bit);
	// ещё могут быть просто 0, если вышли за тип данных
	_asm {
		mov cl, [c];
		imul cl, 4;
		mov al, 28;
		cbw;
		idiv[d];
		add al, cl;
		sub al, [e];
		cbw;
		mov bl, [a];
		imul bl, [d];
		sub bl, [c];
		sub bl, [1];
		add bl, [f];
		idiv bl;
		mov res_asm, al;
	}
	cout << "Answer from Asembler " << int(res_asm) << endl;
	cout << "Answer from C++ " << int(answer) << endl;

}