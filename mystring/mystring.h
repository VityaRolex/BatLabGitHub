#define _CRT_SECURE_NO_WARNINGS
#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>

class String
{
private:
	char* str;
	size_t length;
public:
	const size_t npos = static_cast<size_t>(-1);
	String();
	String(const char*);
	String(const String&);
	~String();
	String& operator=(const String&);
	
	String& append(const char* );
	String& append(const String&);
	size_t sizeT() const;
	const char* c_str() const;
	String substr(size_t);
	String substr(size_t, size_t);
	char* getStr() const;
	int32_t getLength() const;
	void setStr(String);
	void setLength(int32_t);
	String erase(size_t);
	String erase(size_t, size_t);
	size_t find(String) const;
	String insert(size_t, String);
	size_t find_first_of(String);
	size_t find_last_of(String);


	friend std::ostream& operator<<(std::ostream&, const String& );
	friend String operator+(const String&, const String&);
	bool operator==(const String) const; 
	String& operator+=(const String&);
	String& operator+=(const char*);
	bool operator!=(const String) const;
	bool operator<(const String)const;
	bool operator>(const String&) const;
	bool operator<=(const String&) const;
	bool operator>=(const String&) const;
	String& operator=(const String&);
	String& operator=(const char*);

};

#endif HEADER
