#pragma once

#include <cstdint>

enum class ComponentStatus : int8_t {
	Free = 0, Used = 1
};

// GlobalHandle breakdown
//
//   0000 0000 0000 0000 0000 0000 0000 0000
//   |       | |         LocalIndex        |
//       ^                   ^
//  SystemIndex          LocalIndex
//  2^8 Systems        2^24 Components

static const uint32_t k_systemIndex = 0xFF000000;
static const uint32_t k_localIndex  = 0x00FFFFFF;

using GlobalHandle = uint32_t;
using SystemIndex = GlobalHandle;
using LocalIndex = GlobalHandle;

SystemIndex systemIndex(const GlobalHandle globalHandle) const {
    return globalHandle & k_systemIndex;
}

LocalIndex localIndex(const GlobalHandle globalHandle) const {
    return globalHandle & k_localIndex;
}