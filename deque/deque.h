#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque {
private:
    T* data;
    int size_;
    int capacity;
    int front;
    int back;

    void reallocate(int new_cap) {
        T* new_data = new T[new_cap];

        for (int i = 0; i < size_; ++i)
            new_data[i] = operator[](i);

        delete[] data;

        data = new_data;
        capacity = new_cap;
        front = 0;
        back = size_;
    }

public:
    Deque()
        : data(0), size_(0), capacity(0), front(0), back(0)
    {}

    Deque(const Deque& other)
        : data(0), size_(other.size_), capacity(other.capacity),
          front(other.front), back(other.back)
    {
        if (capacity > 0) {
            data = new T[capacity];
            for (int i = 0; i < size_; ++i)
                data[(front + i) % capacity] = other[i];
        }
    }

    Deque(Deque&& other) {
        data = other.data;
        size_ = other.size_;
        capacity = other.capacity;
        front = other.front;
        back = other.back;

        other.data = 0;
        other.size_ = 0;
        other.capacity = 0;
        other.front = 0;
        other.back = 0;
    }

    Deque& operator=(const Deque& other) {
        if (this == &other) return *this;

        delete[] data;

        size_ = other.size_;
        capacity = other.capacity;
        front = other.front;
        back = other.back;

        if (capacity > 0) {
            data = new T[capacity];
            for (int i = 0; i < size_; ++i)
                data[(front + i) % capacity] = other[i];
        } else {
            data = 0;
        }

        return *this;
    }

    Deque& operator=(Deque&& other) {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        size_ = other.size_;
        capacity = other.capacity;
        front = other.front;
        back = other.back;

        other.data = 0;
        other.size_ = 0;
        other.capacity = 0;
        other.front = 0;
        other.back = 0;

        return *this;
    }

    ~Deque() {
        delete[] data;
    }

    bool empty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

    T& operator[](int i) {
        return data[(front + i) % capacity];
    }

    const T& operator[](int i) const {
        return data[(front + i) % capacity];
    }

    void push_back(const T& value) {
        if (size_ == capacity) {
            int new_cap = (capacity == 0 ? 4 : capacity * 2);
            reallocate(new_cap);
        }
        data[back] = value;
        back = (back + 1) % capacity;
        size_++;
    }

    void push_front(const T& value) {
        if (size_ == capacity) {
            int new_cap = (capacity == 0 ? 4 : capacity * 2);
            reallocate(new_cap);
        }
        front = (front + capacity - 1) % capacity;
        data[front] = value;
        size_++;
    }

    void pop_back() {
        if (size_ == 0) return;
        back = (back + capacity - 1) % capacity;
        size_--;
    }

    void pop_front() {
        if (size_ == 0) return;
        front = (front + 1) % capacity;
        size_--;
    }
};

#endif
