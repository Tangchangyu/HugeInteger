#ifndef HUGEINTEGER_H 
#define HUGEINTEGER_H
class HugeInteger 
{ 
public: 
HugeInteger( int = 0 ); // conversion/default constructor 
HugeInteger( const char * ); // conversion constructor 
// addition operator; HugeInteger + HugeInteger 
HugeInteger operator +( const HugeInteger & )const; 
// addition operator; HugeInteger + int 
HugeInteger operator+(const int &)const; 
// addition operator; 
// HugeInteger + string that represents large integer value 
HugeInteger operator+( const char * )const; 
// subtraction operator; HugeInteger - HugeInteger 
HugeInteger operator-( const HugeInteger & )const; 
// subtraction operator; HugeInteger - int 
HugeInteger operator-(const int& )const; 
// subtraction operator; 
// HugeInteger - string that represents large integer value 
HugeInteger operator-( const char * )const; 
bool isEqualTo(const HugeInteger & )const; // is equal to 
bool isNotEqualTo(const HugeInteger & )const; // not equal to 
bool isGreaterThan(const HugeInteger & )const; // greater than 
bool isLessThan(const HugeInteger & )const; // less than 
bool isGreaterThanOrEqualTo(const HugeInteger & )const; // greater than 
// or equal to 
bool isLessThanOrEqualTo(const HugeInteger & )const; // less than or equal 
bool isZero()const; // is zero 
void operator=( const char * ); // input 
void output() const; // output 

HugeInteger operator*(const HugeInteger&) const;
HugeInteger operator*(const int& )const;
HugeInteger operator*(const char* ) const;

HugeInteger operator/(const HugeInteger&) const;
HugeInteger operator/(const int&) const;
HugeInteger operator/(const char *) const;

HugeInteger operator%(const HugeInteger&) const;
HugeInteger operator%(const int &) const;
HugeInteger operator%(const char*) const;

private: 
int integer[ 40 ]={0}; // 40 element array //此处可以使用常量static const int capacity = 40 ,方便数据修改；

void adjust();
}; // end class HugeInteger 


//新增函数multiply，divide，modulus；
#endif