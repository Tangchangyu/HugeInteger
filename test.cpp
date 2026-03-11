#include<iostream>
#include"Hugeint.h"



int main(){
    HugeInteger a (7654321);
    HugeInteger b (7891234);
    HugeInteger c = a.subtract(5);
    HugeInteger d = a.add(b);

    using std::cout;
    a.output();
    cout<<" + ";
    b.output();
    cout<<" = ";
    d.output();
    cout<<"\n";

    a.output();
    cout<<" - 5";
    cout<<" = ";
    c.output();
    cout<<"\n";

    if (a.isEqualTo(a)){
        a.output();
        cout<<" is equal to ";
        a.output();
        cout<<"\n";
 
    }

    if (a.isNotEqualTo(b)){
        a.output();
        cout<<" is not equal to ";
        b.output();
        cout<<"\n";
    }

    if (b.isGreaterThan(a)){
        b.output();
        cout<<" is greater than ";
        a.output();
        cout<<"\n";
    }

    HugeInteger e(5);
    if (e.isLessThan(b)){
        e.output();
        cout<<" is less than ";
        b.output();
        cout<<"\n";
    }

    if(e.isLessThanOrEqualTo(e)){
        e.output();
        cout<<" is less than or equal to ";
        e.output();
        cout<<"\n";
    }
    
    HugeInteger f;
    if(f.isGreaterThanOrEqualTo(f)){
        f.output();
        cout<<" is greater than or equal to ";
        f.output();
        cout<<"\n";
    }

    HugeInteger n3(321465);
    n3.input(0);
    cout<<"n3 contains value ";
    n3.output();

}