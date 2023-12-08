//
// Created by zps on 23-10-21.
//

#ifndef VERSION_TEST_CLASS_TEST_H
#define VERSION_TEST_CLASS_TEST_H

#include <cstring>

#include <iostream>

template <typename T>
class Point {
public:
    /**
     * @brief 默认构造、有参构造、移动构造
     */
    Point() =default;

    Point(const T& _x, const T& _y, const T& _z)
            : x(_x), y(_y), z(_z)
    {
        std::cout << "有参构造函数\n";
    }

    Point(const Point& other) {
        std::cout << "复制构造函数\n";
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Point(Point&& other) noexcept
    {
        std::cout << "移动构造函数\n";
        x = other.x;
        y = other.y;
        z = other.z;
    }

    /**
     * @brief 重载 + - 运算符
     */
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y, z + other.z);
    }

    friend Point operator+(T val, const Point& other) {
        return Point(other.x + val, other.y + val, other.z + val);
    }

    friend Point operator+(const Point& other, T val) {
        return Point(other.x + val, other.y + val, other.z + val);
    }

    Point operator-(const Point& other) {
        return Point(x - other.x, y - other.y, z - other.z);
    }

    friend Point operator-(T val, const Point& other) {
        return Point(other.x - val, other.y - val, other.z - val);
    }

    friend Point operator-(const Point& other, T val) {
        return Point(other.x - val, other.y - val, other.z - val);
    }

    /**
     * @brief 重载 << 运算符
     * out example: [(Point)(x, y, z)]
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "[(Point)(" << point.x << ", " << point.y << " , " << point.z << ")]";
        return os;
    }
private:
    T x{}, y{}, z{};
};


/**
 * @brief 要求 COUNT 成员变量能够实现每创建(销毁)一个实例时 COUNT++(COUNT--)
 */
class Tracker {
public:
    enum class TrackerType {
        DYNAMIC,
        STATIC
    };
    /**
     * @brief 默认构造、有参构造、复制构造、移动构造、析构函数(此处要求的每个构造、析构函数，在调用时都要求输出对应函数名)
     */
     Tracker();

     Tracker(const int& target_id, const char* target_name, const Point<double>& point, const TrackerType& tracker_type);

     Tracker(const Tracker& other);

     Tracker(Tracker&& other);

     ~Tracker();

    /**
     * @brief 重载 << 运算符，实现输出
     * out example: [(Tracker)->COUNT: _; target_id: _; target_name: _; target_content_point: _; tracker_type: _;]
     */
    friend std::ostream& operator<<(std::ostream& os, const Tracker& tracker);

private:
    static int COUNT;  // m_Count;

    int m_target_id{};
    char* m_target_name;
    Point<double> m_target_content_point;
    TrackerType m_tracker_type = TrackerType::DYNAMIC;
};

#endif //VERSION_TEST_CLASS_TEST_H
