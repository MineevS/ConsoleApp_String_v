#pragma once

#include <istream>

using VT = int;

class String_v
{
private:
	char* _data;
	int _size;
	VT _hash;

public:
	String_v();
	~String_v();

	String_v(const String_v& str_v);
	String_v(const char* str);
	String_v(const String_v& str_v_1, const String_v& str_v_2);

	String_v& operator=(const String_v& str_v);
	String_v& operator=(const char* str);

	String_v(String_v&& str_v) noexcept;
	
	String_v& operator=(String_v&& str_v) noexcept;

	String_v operator+(const String_v& str_v);
	String_v operator+(const char* str);

	String_v& operator+=(const String_v& str_v);

	friend std::ostream& operator<<(std::ostream& ost, const String_v& str_v);
	friend std::istream& operator>>(std::istream& ist, const String_v& str_v);

	VT hash();

	int getSize() const;
	char* setChar(const char* str);
	
};

