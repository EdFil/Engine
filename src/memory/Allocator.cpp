//
// Created by edgar on 2/6/19.
//

#include "Allocator.h"

void *Allocator::allocate(size_t byteSize, size_t alignment, int32_t flags) {
    return nullptr;
}

void Allocator::deallocate(void *ptr, size_t byteSize, size_t alignment) {

}

void *Allocator::resize(void *ptr, size_t newSize) {
    return nullptr;
}

void *Allocator::maxSize() const {
    return nullptr;
}

void *Allocator::allocatedSize() const {
    return nullptr;
}