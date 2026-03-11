#include "Hugeint.h"
#include<iostream>

void  HugeInteger::adjust(HugeInteger &result){
    for (int i = 0 ;i < 40 ;i++){
        if (result.integer[39-i]>10){
            result.integer[39-i-1]+=result.integer[39-i]/10;
            result.integer[39-i] = result.integer[39-i]%10;
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

HugeInteger  HugeInteger::add(const HugeInteger &other){

    HugeInteger result;
    for(int i = 0;i<40;i++){
        result.integer[i]=integer[i]+other.integer[i];
    }
    adjust(result);

    return result;
}

HugeInteger HugeInteger::add(int other){
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

return add(HugeInteger(other));

}

HugeInteger HugeInteger::add(const char *other){
    return add(HugeInteger(other));
}

HugeInteger HugeInteger::subtract(const HugeInteger &other){
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

HugeInteger HugeInteger::subtract( int other ){
    return subtract(HugeInteger(other));//构造函数的主动调用？
}

HugeInteger HugeInteger::subtract( const char* other){
    return subtract(HugeInteger(other));
}

bool HugeInteger::isEqualTo(HugeInteger & other){

    for(int i = 0 ;i <40 ;i++){
        if (other.integer[39-i] != integer[39-i]){
            return 0;
        }
    }
    return 1;
}

bool HugeInteger::isNotEqualTo(HugeInteger & other){
    return 1-isEqualTo(other);
}

bool HugeInteger::isGreaterThan(HugeInteger & other){
    for(int i = 0; i <40 ; i++){
        if(other.integer[i]== integer[i]) continue;
        else if (other.integer[i] < integer[i]) return 1 ;
        else return 0;
        
    }
    return 0;//两数相等的情况；
}

bool HugeInteger::isLessThan(HugeInteger & other){
    if(1==isEqualTo(other)||1==isGreaterThan(other)) return 0;
    else return 1;
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger& other){
    return 1-isLessThan(other);
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger& other){
    return 1-isGreaterThan(other);
}

bool HugeInteger::isZero(){
    for(int i = 0;i<40 ;i++){
        if(integer[39-i] != 0) return 0;
    }
    return 1;
}

void HugeInteger::input(const char* a){
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