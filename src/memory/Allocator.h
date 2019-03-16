#pragma once

#include <cstddef>
#include <cstdint>

class Allocator {
public:
    void* _pointerType{};
    size_t _sizeType{};
    ptrdiff_t _differenceType{};

    explicit Allocator(const char* name = "Allocator") : _name(name) {}

    void* allocate(size_t byteSize, size_t alignment, int32_t flags = 0);
    void deallocate(void* ptr, size_t byteSize, size_t alignment);
    void* resize(void* ptr, size_t newSize);
    void* maxSize() const;
    void* allocatedSize() const;

private:
    const char* _name;
};
