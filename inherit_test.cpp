/* testing inheritance*/
#include <iostream>
using namespace std;

class A { 
	public:
	void Hello(){cout << "Hello" << endl;}
};
class B : virtual public A {};
class C : virtual public A {};
class D : virtual public B, virtual public C {};
class E : virtual public B, virtual public C {};
class F : public D, public E {};

int main() {
D d;
d.Hello(); //works

F f;
f.Hello(); //works

return 0;
}
