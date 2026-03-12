#ifndef HUGEINTEGER_H 
#define HUGEINTEGER_H
class HugeInteger 
{ 
public: 
HugeInteger( int = 0 ); // conversion/default constructor 
HugeInteger( const char * ); // conversion constructor 
// addition operator; HugeInteger + HugeInteger 
HugeInteger add( const HugeInteger & ); 
// addition operator; HugeInteger + int 
HugeInteger add( int ); 
// addition operator; 
// HugeInteger + string that represents large integer value 
HugeInteger add( const char * ); 
// subtraction operator; HugeInteger - HugeInteger 
HugeInteger subtract( const HugeInteger & ); 
// subtraction operator; HugeInteger - int 
HugeInteger subtract( int ); 
// subtraction operator; 
// HugeInteger - string that represents large integer value 
HugeInteger subtract( const char * ); 
bool isEqualTo( HugeInteger & ); // is equal to 
bool isNotEqualTo( HugeInteger & ); // not equal to 
bool isGreaterThan(HugeInteger & ); // greater than 
bool isLessThan( HugeInteger & ); // less than 
bool isGreaterThanOrEqualTo( HugeInteger & ); // greater than 
// or equal to 
bool isLessThanOrEqualTo( HugeInteger & ); // less than or equal 
bool isZero(); // is zero 
void input( const char * ); // input 
void output() const; // output 

HugeInteger operator*(const HugeInteger&) const;
HugeInteger operator*(const int& )const;

HugeInteger operator/(const HugeInteger&) const;
HugeInteger operator/(const int&) const;

private: 
int integer[ 40 ]={0}; // 40 element array //此处可以使用常量static const int capacity = 40 ,方便数据修改；

void adjust();
}; // end class HugeInteger 


//新增函数multiply，divide，modulus；
#endif