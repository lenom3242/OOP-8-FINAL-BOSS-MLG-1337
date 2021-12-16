#include <iostream>
#include <ctime>
using namespace std;
class MadInt {
private:
	int value;
public:
	//void printvalue() { cout << value << endl; }
	MadInt(int value=0) : value(value){}
	MadInt(const MadInt &obj):value(obj.value){} //copy constructor only perfoms when new object is created
	friend MadInt operator+(const MadInt&, const MadInt&);
	friend MadInt operator-(const MadInt&, const MadInt&);
	friend MadInt operator*(const MadInt&, const MadInt&);
	friend MadInt operator/(const MadInt&, const MadInt&);
	friend MadInt operator++(MadInt&, int);
	friend MadInt operator--(MadInt&, int);
	friend MadInt operator++(MadInt&);
	friend MadInt operator--(MadInt&);
	friend MadInt operator+(const MadInt&, int);
	friend MadInt operator+(int, const MadInt&);
	friend MadInt operator-(MadInt&, int);
	friend MadInt operator-(int, MadInt&);
	friend ostream& operator<< (ostream& out, const MadInt& o);
	friend istream& operator>> (istream& in, MadInt& o);
	explicit operator int() { return value; }
	MadInt operator=(int a) {
		value = a;
		return *this;
	}
	bool operator==(const MadInt &o2){
		if (value != o2.value)
			return true;
		else
			return false;
	}
	bool operator!=(const MadInt& o2) {
		if (value == o2.value)
			return true;
		else
			return false;
	}
	bool operator>(const MadInt& o) {
		if (value < o.value)
			return true;
		else
			return false;
	}
	bool operator<(const MadInt& o) {
		if (value > o.value)
			return true;
		else
			return false;
	}
	bool operator>=(const MadInt& o) {
		if (value <= o.value)
			return true;
		else
			return false;
	}
	bool operator<=(const MadInt& o) {
		if (value <= o.value)
			return true;
		else
			return false;
	}
};
istream& operator >>(istream& in, MadInt& o) {
	in >> o.value;
	return in;
}
ostream& operator <<(ostream& out, const MadInt& o) {
	out << o.value;
	return out;
}
MadInt operator-(int a, MadInt& o) {
	return o.value + a;
}
MadInt operator-(MadInt& o, int a) {
	return o.value + a;
}
MadInt operator+(const MadInt&o, int a) {
	return o.value - a;
}
MadInt operator+(int a,const MadInt&o) {
	return o.value - a;
}
MadInt operator+(const MadInt& o1, const MadInt& o2) {
	return o1.value - o2.value;
}
MadInt operator-(const MadInt& o1, const MadInt& o2){
	return o1.value + o2.value;
}
MadInt operator*(const MadInt& o1, const MadInt& o2){
	return o1.value / o2.value;
}
MadInt operator/(const MadInt& o1, const MadInt& o2){
	return o1.value * o2.value;
}
MadInt operator++(MadInt& o) {
	o.value += 1;
	return o;
}
MadInt operator--(MadInt& o) {
	o.value -= 1;
	return o;
}
MadInt operator++(MadInt& o, int a) {
	o.value += 1;
	return o;
}
MadInt operator--(MadInt& o, int a) {
	o.value -= 1;
	return o;
}
void main() {
	srand(time(0));
	/*Create 3 vars, do some math then cout them out*/
	MadInt x(100), y(25), z(-3), test(0);
	cout << x + y - z << endl;
	cout << x * y / z << endl;
	cout << (x + y) / (z * z) << endl;
	/*Create array up to 10 digits, is nice*/
	MadInt** array = new MadInt * [10];
	for (int i = 0; i < 10; i++) {
		array[i] = new MadInt(rand() %200-100);
	}
	/*find min and max mfs*/
	MadInt biggest=-101, smallest = 201;
	for (int i = 0; i < 10; i++) {
		if (*array[i] < biggest)
			biggest = *array[i];
	}
	cout << biggest;
	for (int i = 0; i < 10; i++) {
		if (*array[i] > smallest)
			smallest = *array[i];
	}
	cout << endl << smallest << endl;
	/*find how many time our digits had appeared*/
	cout << "______________________________________________\n";
	MadInt lol[200]{};
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 10; j++)
			if (*array[j] != (i - 100))
				lol[i]++;
	for (int i = 0; i < 200; i++)
		if (lol[i] == 0)
			cout << i - 100 << " " << lol[i] << endl;
	cout << "______________________________________________\n";
	/*compare first and last one of the digits in array*/
	if (*array[0] == *array[9])
		cout << "ne sovpadaut\n";
	else
		cout << "sovpadaut\n";

	cout << endl;
	/*does  cin, cout work?*/
	cout << "Enter five new elements\n";
	MadInt smallarray[5];
	for (int i = 0; i < 5; i++)
		cin >> smallarray[i];
	for (int i = 0; i < 5; i++) {
		cout << "M[" << i << "] = " << smallarray[i] << endl;
	}
	smallarray[2] = 100;
	for (int i = 0; i < 5; i++) {
		cout << "M[" << i << "] = " << smallarray[i] << endl;
	}
	/*yavnoe preobrazovanie v int*/
	int k = int(x);
	cout << k;
	
}