#include<iostream>
#include"Hugeint.h"
//构造辅助函数帮助打印；
void print(const HugeInteger&,const char*,const HugeInteger&);//函数声明中缺少const，则会报错，因为常量字符串 "abcd" 具有只读的特性;
//使用常量引用传递，加速运行效率

int main(){
    HugeInteger a (7654321);
    HugeInteger b (7891234);
    HugeInteger c = a-(5);
    HugeInteger d = a+(b);

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
        /*a.output();
        cout<<" is equal to ";
        a.output();
        cout<<"\n";
 */
            print(a," is equal to ",a);

    }

    if (a.isNotEqualTo(b)){
      print (a," is not equal to " ,b);
    }

    if (b.isGreaterThan(a)){
      
        print(b, " is greater than ",a);
    }

    HugeInteger e(5);
    if (e.isLessThan(b)){
        print(e," is less than ",b);
        
    }

    if(e.isLessThanOrEqualTo(e)){
        print(e," is less than or equal to ",e);

    }
    
    HugeInteger f;
    if(f.isGreaterThanOrEqualTo(f)){
        print(f," is greater than or equal to ",f);
    }

    HugeInteger n3(321465);
    n3=("0");//0会被理解为空指针，使用‘0’————单个字符，为char类型; 用"0":const char* ; 在input函数中实现hullptr的防护；
    cout<<"n3 contains value ";
    n3.output();
    cout <<std::endl;

    HugeInteger m = a*2;
    m.output();
    cout<<std::endl;

    HugeInteger n = a/2;
    n.output();
    cout <<std::endl;

    HugeInteger o =a%2;
    o.output();

}

void print(const HugeInteger& a,const char* b,const HugeInteger& c) {
    a.output();
    std::cout<<b;
    c.output();
    std::cout<<std::endl;

}