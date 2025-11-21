#include "mystring.h"

String::String()
{
    this->length = 1;
    this->str = new char[1];
    this->str[0] = '\0';
}


String::String(const char* s)
{
    this->length = std::strlen(s);
    this->str = new char[length + 1];
    std::strcpy(this->str, s);
}


String::String(const String& s)
{
    this->length = s.length;
    this->str = new char[length + 1];
    std::strcpy(this->str, s.str);
}


String::~String()
{
    delete [] str;
    str = nullptr;
}


String& String::operator=(const String& st1)
{
    if (this != &st1)
    {
        delete[] this->str;
        this->length = st1.length;
        this->str = new char[length + 1];
        std::strcpy(this->str, st1.str);
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const String& st)
{
    os << st.str;
    return os;
}


String operator+(const String& st1, const String& st2)
{
    String result;                         
    delete[] result.str;
    result.length = st1.length + st2.length;
    result.str = new char[result.length + 1];

    std::strcpy(result.str, std::strcat(st1.str, st2.str));

    return result;
}


String& String::operator+=(const String& str)
{
    return this->append(str);
}


String& String::operator+=(const char* s)
{
    return this->append(s);
}


const char* String::c_str() const 
{
    return this->str;
}


size_t String::sizeT() const
{
    return this->length;
}


String& String::append(const char* s)
{
    size_t sLen = std::strlen(s);
    if (sLen == 0)
    {
        return *this;
    }

    size_t newLength = static_cast<size_t>(this->length) + sLen;
    char* newStr = new char[newLength + 1];


    for (size_t i = 0; i < static_cast<size_t>(this->length); ++i) 
    {
        newStr[i] = this->str[i];
    }
    for (size_t i = 0; i < sLen; ++i)
    {
        newStr[this->length + i] = s[i];
    }

    newStr[newLength] = '\0';
    delete[] this->str;

    this->str = newStr;
    this->length = static_cast<int32_t>(newLength);

    return *this;
}


String& String::append(const String& st)
{
    this->append(st.str);
    return *this;
}


String String::substr(size_t start)
{
    String result;
    delete[] result.str;
    result.length = length - start + 1;
    result.str = new char[result.length];
    int32_t j{};
    for (int32_t i{ start }; i < result.length; ++i, ++j)
    {
        result.str[j] = this->str[i];
    }
    return result;
}


String String::substr(size_t start, size_t dlina)
{
    if ((start > this->length) || (this->length - start < dlina))
    {
        return String(this->str); 
    }
    String result;
    delete[] result.str;
    result.length = this->length - start + 1;
    result.str = new char[result.length];
    for (size_t i{}; i < dlina; ++i)
    {
        result.str[i] = this->str[start + i];
    }
    result.str[dlina] = '\0';
    return result;
}


char* String::getStr() const
{
    return this->str;
}


int32_t String::getLength() const
{
    return this->length;
}


void String::setStr(String newStr)
{
    delete[] this->str;
    this->length = newStr.length;
    this->str = new char[length + 1];
    std::strcpy(this->str, newStr.str);
}


void String::setLength(int32_t newLength)
{
    this->length = newLength;
}


String String::erase(size_t start)
{
    if (start > length)
    { 
        return String(this->str);
    }
    char* result = new char [start]; 
    for (int32_t i{}; i < start; ++i)
    {
        result[i] = this->str[i];
    }
    result[start] = '\0';
    return String(result);
}


String String::erase(size_t start, size_t count)
{
    if (start >= this->length || count == 0)
    {
        return String(this->str);
    }
    if (start + count > this->length)
    {
        count = this->length - start;
    }
    size_t newLength = this->length - count;
    char* newStr = new char[newLength + 1];


    for (size_t i{}; i < start; ++i)
    {
        newStr[i] = this->str[i];
    }
    for (size_t i{ start + count }; i < this->length; ++i)
    {
        newStr[i - count] = str[i];
    }

    newStr[newLength] = '\0';

    String result(newStr);
    delete[] newStr;
    return result;
}


bool String::operator==(const String s1) const
{
    if (this->length != s1.length) 
    {
        return false;
    }
    return std::strcmp(str, s1.str) == 0;
}


bool String::operator!=(const String s1) const
{
    return !(*this == s1);
}


bool String::operator<(const String rhs) const
{
    return std::strcmp(this->str,rhs.str);
}


bool String::operator>(const String& rhs) const
{
    return rhs < *this;
}

bool String::operator<=(const String& rhs) const
{
    return !(rhs < *this);
}

bool String::operator>=(const String& rhs) const
{
    return !(*this < rhs);
}


size_t String::find(String s1) const
{
    if (this->length < s1.length)
    {
        return npos;
    }
    for (size_t i{}; i <= this->length - s1.length; ++i)
    {
        if (std::strncmp(this->str + i, s1.str, s1.length) == 0)
        {
            return i;
        }
    }
    return npos;
}


String String::insert(size_t start, String st)
{
    if (start > static_cast<size_t>(this->length))
    {
        return *this;
    }

    size_t resultLength = this->length + st.length;
    char* newStr = new char[resultLength + 1];


    for (size_t i{}; i < start; ++i)
    {
        newStr[i] = this->str[i];
    }

    for (size_t i{}; i < static_cast<size_t>(st.length); ++i)
    {
        newStr[start + i] = st.str[i];
    }


    for (size_t i{ start }; i < static_cast<size_t>(this->length); ++i)
    {
        newStr[st.length + i] = this->str[i];
    }

    newStr[resultLength] = '\0';

    String result(newStr);
    delete[] newStr;
    return result;
}


size_t String::find_first_of(String s1)
{
    for (size_t i{}; i < static_cast<size_t>(this->length); ++i)
    {
        for (size_t j{}; j < static_cast<size_t>(s1.length); ++j)
        {
            if (this->str[i] == s1.str[j])
            {
                return i;
            }
        }
    }
    return npos;
}


size_t String::find_last_of(String s1)
{
    for (int32_t i{ this->length - 1 }; i >= 0; --i)
    {
        for (size_t j{}; j < static_cast<size_t>(s1.length); ++j)
        {
            if (this->str[i] == s1.str[j])
            {
                return static_cast<size_t>(i);
            }
        }
    }
    return npos;
}


String& String::operator=(const char* str) 
{
    if (str == nullptr) 
    {
        throw std::invalid_argument("No string to copy");
    }
    int new_size = std::strlen(str);

    if (this->length > new_size)
    {
        this->length = new_size;
        std::strcpy(this->str, str);
    }
    else {
        delete[] this->str;
        this->length = new_size;
        this->str = new char[this->length+1];
        std::strcpy(this->str, str);
    }
    return *this;
}