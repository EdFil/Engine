#pragma once

#include <cmath>
#include <cassert>
#include <cinttypes>

class Vector3 {
public:
    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
    Vector3(float value) : x(value), y(value), z(value) { }
    Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

    float operator[] (uint32_t i) const {
        assert(i < 3);
        return *(&x + i);
    }


    Vector3& operator= (float rhs) {
        x = y = z = rhs;
        return *this;
    }

    bool operator== (const Vector3& rhs) const {
        return (x == rhs.x && y == rhs.y && z == rhs.z);
    }

    bool operator!= (const Vector3& rhs) const {
        return (x != rhs.x || y != rhs.y || z != rhs.z);
    }

    Vector3 operator+ (const Vector3& rhs) const {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Vector3 operator- (const Vector3& rhs) const {
        return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    Vector3 operator* (float rhs) const {
        return Vector3(x * rhs, y * rhs, z * rhs);
    }

    Vector3 operator* (const Vector3& rhs) const {
        return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
    }

    Vector3 operator/ (float val) const {
        assert(val != 0.0);

        float fInv = 1.0f / val;
        return Vector3(x * fInv, y * fInv, z * fInv);
    }

    Vector3 operator/ (const Vector3& rhs) const {
        return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
    }

    const Vector3& operator+ () const {
        return *this;
    }

    Vector3 operator- () const {
        return Vector3(-x, -y, -z);
    }

    friend Vector3 operator* (float lhs, const Vector3& rhs) {
        return Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
    }

    friend Vector3 operator/ (float lhs, const Vector3& rhs) {
        return Vector3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
    }

    friend Vector3 operator+ (const Vector3& lhs, float rhs) {
        return Vector3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
    }

    friend Vector3 operator+ (float lhs, const Vector3& rhs) {
        return Vector3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
    }

    friend Vector3 operator- (const Vector3& lhs, float rhs) {
        return Vector3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
    }

    friend Vector3 operator- (float lhs, const Vector3& rhs) {
        return Vector3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
    }

    Vector3& operator+= (const Vector3& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return *this;
    }

    Vector3& operator+= (float rhs) {
        x += rhs;
        y += rhs;
        z += rhs;

        return *this;
    }

    Vector3& operator-= (const Vector3& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return *this;
    }

    Vector3& operator-= (float rhs) {
        x -= rhs;
        y -= rhs;
        z -= rhs;

        return *this;
    }

    Vector3& operator*= (float rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;

        return *this;
    }

    Vector3& operator*= (const Vector3& rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;

        return *this;
    }

    Vector3& operator/= (float rhs) {
        assert(rhs != 0.0f);

        float inv = 1.0f / rhs;

        x *= inv;
        y *= inv;
        z *= inv;

        return *this;
    }

    Vector3& operator/= (const Vector3& rhs) {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;

        return *this;
    }

};