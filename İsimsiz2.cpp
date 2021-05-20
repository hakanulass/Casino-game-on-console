#include <iostream>
#include <cmath>

using namespace std;
double bisection (int z)
{
	
	
	double r;
	r=(z)^3 - 5*(z,2) - 2*z-10;
	
	return (r);
}


int main (int argc, char * const argv[]) {
	double fa=0;
	int x=0;
	double fb=0;
	double m=0, product=0;
    double a, b;
	cout << "Fonksiyonun kapali aralik alt degerini giriniz: " << endl; 
	cin >> a;
	cout << "Fonksiyonun kapali aralik ust degerini giriniz:" << endl;
	cin >> b;
loop:
	
	fa= bisection (a);
	fb = bisection (b);
	product = fa * fb; 
	m = (a+b)/2;
	if (product < 0) {
		b=m;
	}
	else {
		a= m;
	}
	x= abs (a-b);
	
	if (x > 0.01) {
		goto loop; 
	}
	else {
		goto loopa;
	}
	
loopa:
	cout << "kok vardir  " << m << endl;
    return 0;
}
