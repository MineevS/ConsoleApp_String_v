#include "String_v.h"

#pragma warning(disable : 6386)
#pragma warning(disable : 26451)

String_v::String_v()
{
    this->_data = new char();
    this->_size = 0;
    this->_hash = VT(0);
}

String_v::~String_v()
{

}

String_v::String_v(const String_v& str_v)
{
    this->_size = str_v._size;

    this->_data = new char[this->_size + 1]();//+

    strcpy_s(this->_data, this->_size+1, str_v._data);

    this->_hash = hash();
}

String_v::String_v(const String_v& str_v_1, const String_v& str_v_2)
{
    this->_size = str_v_1._size + str_v_2._size;

    this->_data = new char[this->_size + 1];//+

    strcpy_s(this->_data,  str_v_1._size + 1, str_v_1._data);

    strcat_s(this->_data, this->_size + 1, str_v_2._data);

    this->_hash = hash();
}

String_v::String_v(const char* str)
{
    this->_size = strlen(str);

    this->_data = new char[this->_size + 1];//+

    strcpy_s(this->_data, this->_size + 1, str);

    this->_hash = hash();
}

String_v& String_v::operator=(const String_v& str_v)
{
    return *this;
}

String_v& String_v::operator=(const char* str)
{
    return *this;
}

String_v::String_v(String_v&& str_v) noexcept
{
    this->_size = str_v._size;

    this->_data = new char[this->_size + 1]; //+

    strcpy_s(this->_data, this->_size + 1, str_v._data);

    this->_hash = hash();
}

String_v& String_v::operator=(String_v&& str_v) noexcept
{
    return *this;
}

String_v String_v::operator+(const String_v& str_v)
{
    return String_v(*this, str_v);
}

String_v String_v::operator+(const char* str)
{
    return String_v(*this, String_v(str));
}

String_v& String_v::operator+=(const String_v& str_v)
{
    this->_size += str_v._size;

    strcat_s(this->_data, str_v._size + 1, str_v._data);

    return *this;
}

VT String_v::hash()
{
    return VT();
}

int String_v::getSize() const
{
    return 0;
}

char* String_v::setChar(const char* str)
{
    return nullptr;
}

std::ostream& operator<<(std::ostream& ost, const String_v& str_v)
{
    return ost << str_v._data;
}

std::istream& operator>>(std::istream& ist, const String_v& str_v)
{
    return ist;
}
