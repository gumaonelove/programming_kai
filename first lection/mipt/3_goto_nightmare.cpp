#include <iostream>;

int euclid_gcd(int a, int b) 
{
loop_begin:
    if (a == b) goto loop_end;
    if (!(a>b)) goto else_action;
    a -= b;
    goto after_if;
else_action:
    b -= a;
after_if:
    goto loop_begin;
loop_end:
    return a;
}


int main() 
{
    using namespace std;
    int x, y;

    cout << "Enter integer. x = ";
    cin >> x;
    cout << "Enter integer. y = ";
    cin >> y;
    cout << "GSD(x, y) = " << euclid_gcd(x, y) << endl;
    return 0;
}