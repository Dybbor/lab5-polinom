#include "..\Header\Polinom.h"


int main() 
{	
	//Тестовый мейн для полинома

	TPolinom p, q,copy;
	p.InsMonom(InsValueInMonom(-2, 1, 2, 3));
	p.InsMonom(InsValueInMonom(3, 0, 2, 3));
	p.InsMonom(InsValueInMonom(5, 0, 0, 1));
	p.InsMonom(InsValueInMonom(5, 0, 0, 0));
	q.InsMonom(InsValueInMonom(2, 5, 2, 3));
	q.InsMonom(InsValueInMonom(4, 0, 2, 3));
	q.InsMonom(InsValueInMonom(2, 0, 1, 0));
	q.InsMonom(InsValueInMonom(-5, 0, 0, 0));
	copy = p;
	cout << "The first polinom: " << p << endl;
	cout << "The second polinom: " << q << endl;
	p += q;
	cout << "p+q=" << p << endl;
	cout << endl;
	p = copy;
	q.InsMonom(InsValueInMonom(-2, 1, 2, 3));
	cout << "The first polinom: " << p << endl;
	cout << "The second polinom: " << q << endl;
	p -= q;
	cout << "p-q=" << p << endl;


	/*setlocale(LC_ALL, "Russian");
	TPolinom p, q,copy;
	p.InsMonom(InsValueInMonom(-2, 1, 2, 3));
	p.InsMonom(InsValueInMonom(3, 0, 2, 3));
	p.InsMonom(InsValueInMonom(5, 0, 0, 1));
	p.InsMonom(InsValueInMonom(5, 0, 0, 0));
	q.InsMonom(InsValueInMonom(2, 1, 2, 3));
	q.InsMonom(InsValueInMonom(4, 0, 2, 3));
	q.InsMonom(InsValueInMonom(2, 0, 1, 0));
	copy = p;
	cout << "The first polinom: " << p << endl;
	cout << "The second polinom: " << q << endl;
	p -= q;
	cout << "p-q=" << p << endl;
*/
	/*cout << "The first polinom :" << endl;
	cin >> p;
	system("cls");
	cout << "The second polinom :" << endl;
	cin >> q;
	system("cls");
	cout << "The first polinom: " << p << endl;
	cout << "The second polinom: " << q << endl;
	p -= q;
	cout << "p-q=" << p << endl;*/
	system("pause");

}
