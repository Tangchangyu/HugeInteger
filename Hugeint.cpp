#include "Hugeint.h"
#include<iostream>

void  HugeInteger::adjust(){
    for (int i = 39;i > 0 ;i--){
        if (integer[i]>=10){
            integer[i-1]+=integer[i]/10;
            integer[i] =integer[i]%10;
        }
    }//实现进位矫正
}

HugeInteger::HugeInteger(int i){
    int a = i%10;
    for(int n = 0;n<40;n++){
        integer[39-n]=a;
        i = i/10;
        a = i%10;

        if (0==a&&0==i) break;
    }//注意循环体内的变量遮蔽——变量i的复用
}

HugeInteger::HugeInteger(const char* a ){

    for (int i = 0; i < 40; i++) integer[i] = 0;

    if (a == nullptr) return;

    const char* end = a;//常量指针———指向常量的指针；

    while(*end !='\0')
    {
        end++;
    }
    end--;
    for(int i = 0;i < 40 && end >= a;i++){
        integer[39-i]=*end-'0';//此处为0 ，并非\0 
        end--;
    }


}//求长度，反向赋值；

HugeInteger  HugeInteger::operator+(const HugeInteger &other)const{

    HugeInteger result;
    for(int i = 0;i<40;i++){
        result.integer[i]=integer[i]+other.integer[i];
    }
    result.adjust();

    return result;
}

HugeInteger HugeInteger::operator+(const int& other)const{
/*
    //逻辑一：尝试other求每位位数，使用标记数n；
    int a = other%10;
    HugeInteger result;
    for(int i = 0;i < 40; i ++ ){
        result.integer[39-i]=integer[39-i]+a;
        other = other/10;
        a = other%10;
    }

    adjust(result);
    return result;
*/
//更优的解法——委托调用，利用构造函数的重载和已经编写的add函数实现；

return *this+(HugeInteger(other));

}

HugeInteger HugeInteger::operator+(const char *other)const{
    return *this+(HugeInteger(other));
}

HugeInteger HugeInteger::operator-(const HugeInteger &other)const{
    HugeInteger result;

    for(int i = 0;i < 40 ;i ++){
        result.integer[i]=integer[i] - other.integer[i];
    }

    for(int i = 0 ; i <40 ;i++){
        if(result.integer[39-i]<0){
            result.integer[39-i-1]--;
            result.integer[39-i] +=10;
        }
    }

    return result;
}

HugeInteger HugeInteger::operator-(const int& other )const{
    return operator-(HugeInteger(other));//构造函数的主动调用？
}

HugeInteger HugeInteger::operator-( const char* other)const{
    return operator-(HugeInteger(other));
}

bool HugeInteger::isEqualTo(const HugeInteger & other)const{

    for(int i = 0 ;i <40 ;i++){
        if (other.integer[39-i] != integer[39-i]){
            return 0;
        }
    }
    return 1;
}

bool HugeInteger::isNotEqualTo(const HugeInteger & other)const{
    return 1-isEqualTo(other);
}

bool HugeInteger::isGreaterThan(const HugeInteger & other)const{
    for(int i = 0; i <40 ; i++){
        if(other.integer[i]== integer[i]) continue;
        else if (other.integer[i] < integer[i]) return 1 ;
        else return 0;
        
    }
    return 0;//两数相等的情况；
}

bool HugeInteger::isLessThan(const HugeInteger & other)const{
    if(1==isEqualTo(other)||1==isGreaterThan(other)) return 0;
    else return 1;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other)const{
    return 1-isLessThan(other);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other)const{
    return 1-isGreaterThan(other);
}

bool HugeInteger::isZero()const{
    for(int i = 0;i<40 ;i++){
        if(integer[39-i] != 0) return 0;
    }
    return 1;
}

void HugeInteger::operator =(const char* a){
    HugeInteger n (a);
    for (int i = 0; i <40 ;i++){
        integer[i]=n.integer[i];
    }

}

void HugeInteger::output()const{
    int index = 0;

    for(int i = 0; i <40 ;i ++){
        if (integer[i]==0){
            index++;
        }
        else break;
    }

    if (index==40){
        std::cout<<0;
    }
    else{
        for(int i =index;i<40;i++){
            std::cout<<integer[i];
        }
    }
}//pay attention to a lot of "0";

HugeInteger HugeInteger::operator*(const HugeInteger& other)const{
    HugeInteger result;
    for (int i = 0; i <40 ;i ++){
        if (other.integer[39-i]==0) continue;
        for(int j =0;j < 40; j++){
            int product = integer[39-j]* other.integer[39-i];
            
            int object = i + j;
            if (object<40){
                result.integer[39-object] +=product;
            }
        }

    }


    result.adjust();
    return result;
}//初次构想，使用循环和pow函数实现累加；————否定：pow函数返回的是double，处理极大数时可能会丢失精度；
//注意竖式乘法的逻辑——并非逐位数相乘；

HugeInteger HugeInteger::operator*(const int& other)const{
    return(*this * HugeInteger(other));//this是指向当前对象的指针，需要使用*解引用；
}

HugeInteger HugeInteger::operator*(const char* other)const{
    return operator*(HugeInteger(other));
}

HugeInteger HugeInteger::operator/(const HugeInteger& other)const{
    HugeInteger zero(0);//显式构造，防止返回0产生额外性能开销/歧义

    if (other.isZero()) {
        std::cout<<"Error: Division by 0" <<std::endl;
        return zero;
    }

    if (isLessThan(other)){
        return zero;
    }

    HugeInteger quotient;
    HugeInteger remainder;

    for(int i = 0; i < 40; i++){

        remainder = remainder*10;
        remainder = remainder +(integer[i]);

        int count = 0;
        while(remainder.isGreaterThanOrEqualTo(other)){
            remainder=remainder- (other);
            count++;

        };
        quotient.integer[i] =count;
    }

    return quotient;

}

HugeInteger HugeInteger::operator/(const int& other)const{
    return *this/HugeInteger(other);
}

HugeInteger HugeInteger::operator/(const char* other)const{
    return operator/(HugeInteger(other));
}

HugeInteger HugeInteger::operator%(const HugeInteger& other)const{
    if (isLessThan(other)){
        return *this;
    }

    if (isEqualTo(other)) return HugeInteger(0);//这种提前返回（Early Return）的习惯在编写高性能代码时非常重要

    HugeInteger quotient =*this/other;
    HugeInteger remainder = *this - quotient*other;
    return remainder;
}

HugeInteger HugeInteger::operator%(const int& other) const{
    return operator%(HugeInteger(other));
}

HugeInteger HugeInteger::operator%(const char* other) const{
    return operator%(HugeInteger(other));
}
