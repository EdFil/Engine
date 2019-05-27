#pragma once

#include <cstdint>

enum class ComponentStatus : int8_t {
	Free = 0, Used = 1
};

using GlobalHandle = uint32_t;
using LocalHandle = uint16_t;