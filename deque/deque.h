#ifndef DEQUE_H
#define DEQUE_H


#include <cstddef>
#include <utility>
#include <stdexcept>
#include <new>

template <typename T>
class Deque {
private:
    T* data_;
    size_t size_;
    size_t capacity_;
    size_t front_;
    size_t back_;

    void reallocate(size_t new_cap) {
        T* new_data = static_cast<T*>(operator new[](new_cap * sizeof(T)));
        for (size_t i = 0; i < size_; ++i)
            new (new_data + i) T(std::move((*this)[i]));
        for (size_t i = 0; i < size_; ++i)
            (*this)[i].~T();
        operator delete[](data_);
        data_ = new_data;
        capacity_ = new_cap;
        front_ = 0;
        back_ = size_;
    }

public:
    Deque()
        : data_(nullptr), size_(0), capacity_(0), front_(0), back_(0) {}

    explicit Deque(size_t n, const T& value = T())
        : data_(static_cast<T*>(operator new[](n * sizeof(T)))),
          size_(n), capacity_(n), front_(0), back_(n)
    {
        for (size_t i = 0; i < n; ++i)
            new (data_ + i) T(value);
    }

    Deque(const Deque& other)
        : data_(static_cast<T*>(operator new[](other.capacity_ * sizeof(T)))),
          size_(other.size_), capacity_(other.capacity_),
          front_(other.front_), back_(other.back_)
    {
        for (size_t i = 0; i < other.capacity_; ++i) {
            size_t idx = i;
            if (idx >= other.front_ && idx < other.back_) {
                new (data_ + idx) T(other.data_[idx]);
            }
        }
    }

    Deque(Deque&& other) noexcept
        : data_(other.data_), size_(other.size_),
          capacity_(other.capacity_), front_(other.front_), back_(other.back_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        other.front_ = 0;
        other.back_ = 0;
    }

    Deque& operator=(const Deque& other) {
        if (this == &other) return *this;
        Deque tmp(other);
        swap(tmp);
        return *this;
    }

    Deque& operator=(Deque&& other) noexcept {
        if (this == &other) return *this;
        clear();
        operator delete[](data_);
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        front_ = other.front_;
        back_ = other.back_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        other.front_ = 0;
        other.back_ = 0;
        return *this;
    }

    ~Deque() {
        clear();
        operator delete[](data_);
    }

    void clear() {
        for (size_t i = 0; i < size_; ++i)
            (*this)[i].~T();
        size_ = 0;
        front_ = 0;
        back_ = 0;
    }

    void swap(Deque& other) noexcept {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(front_, other.front_);
        std::swap(back_, other.back_);
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    T& operator[](size_t idx) {
        return data_[(front_ + idx) % capacity_];
    }

    const T& operator[](size_t idx) const {
        return data_[(front_ + idx) % capacity_];
    }

    void push_back(const T& value) {
        if (size_ == capacity_)
            reallocate(capacity_ == 0 ? 4 : capacity_ * 2);
        new (data_ + back_) T(value);
        back_ = (back_ + 1) % capacity_;
        ++size_;
    }

    void push_front(const T& value) {
        if (size_ == capacity_)
            reallocate(capacity_ == 0 ? 4 : capacity_ * 2);
        front_ = (front_ + capacity_ - 1) % capacity_;
        new (data_ + front_) T(value);
        ++size_;
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("pop_back from empty deque");
        back_ = (back_ + capacity_ - 1) % capacity_;
        data_[back_].~T();
        --size_;
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("pop_front from empty deque");
        data_[front_].~T();
        front_ = (front_ + 1) % capacity_;
        --size_;
    }
};

#endif

