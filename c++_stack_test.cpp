#include<iostream>
using namespace std;
#define MAX 10

class pstack {

private:
	int item[MAX],top;
public:
	pstack(int p) {
		top = p;
	}
	int Gettop();
	bool Push(int data);
	bool Pop(int& data);
	void operator[](int idx);
	void input_stack();
	void print_stack();
};
int pstack::Gettop() {
	return top;
}

bool pstack::Push(int data) {
	int t = Gettop();
	t = t + 1;
	if (t < MAX) {
		item[t] = data;
		top++;
	}
	else {
		return false;
	}
}
bool pstack::Pop(int& data) {
	int t = Gettop();
	if (t < 0) { return false; }
	else {
		item[t] = NULL;
		return true;
	}

 }
void pstack::operator[](int idx) {
	int t = Gettop();
	if (idx > t) {
		cout << "error"; 
	}
	else {
		cout << item[idx] << "\n";
	}
}
void pstack::input_stack() {
	for (int i = 0; i < 5; i++) {
		Push(i + 10);
	}
}
void pstack::print_stack() {
	int t= Gettop();
	for (t; t > -1; t--) {
		cout << "top : " << t << ", data : " << item[t] << "\n";
	}
}
int main() {
	int data;
	pstack p(-1);
	p.input_stack();
	int t = p.Gettop();
	cout << "Input index(top : " << t << ") : ";
	cin >> data;
	p.operator[](data);
	p.print_stack();
}
