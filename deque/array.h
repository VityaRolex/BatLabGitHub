#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
private:
    size_t size;
    size_t capacity;
    T* first;
public:
    Array(const int Size = 100):capacity(Size), size(0), first(new T[size]){}
    Array(const Array& other):capacity(other.capacity), first(new T[capacity])
    {
        size = 0;
        while(size != other.size)
        {
            first[size] = other.first[size];
            ++size;
        }
    }
    Array(Array&& other):capacity(other.capacity), size(other.size)
    {
        first = other.first;
        other.first = nullptr;
    }
    ~Array()
    {
        delete first;
        first = nullptr;
    }
    Array& operator =(const Array& other):capacity(other.capacity),size(0)
    {
        delete first;
        first = new T[capacity]
        while(size != other.size)
        {
            first[size] = other.first[size];
            ++size;
        }
    }
    T operator[](size_t pos)
    {
        if (pos >= size)
        {
            throw std::runtime_error("");
        }
        return first[pos];
    }
    void pushBack(const T& val)
    {
        if(size == capacity)
        {
            T* newFirst = new T[2*capacity];
            for(int i{}; i < size; ++i)
            {
                newFirst[i] = first[i];
            }
            newFirst[size] = val;
            delete first;
            first = newFirst;
            capacity *= 2;
        }
        else
        {
            first[size] = val;
        }
        ++size;
    }
    void pushFront(const T& val)
    {
        if(size == capacity)
        {
            T* newFirst = new T[2*capacity];
            newFirst[0] = val;
            for(int i{}; i < size; ++i)
            {
                newFirst[i + 1] = first[i];
            }
            delete first;
            first = newFirst;
            capacity *= 2;
        }
        else
        {
            for(int i = size; i > 0; --i)
            {
                first[i] = first[i-1];
            }
            first[0] = val;
        }
        ++size;
    }
};


#endif