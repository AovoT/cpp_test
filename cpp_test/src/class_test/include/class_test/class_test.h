//
// Created by zps on 23-10-21.
//

#ifndef VERSION_TEST_CLASS_TEST_H
#define VERSION_TEST_CLASS_TEST_H

template <typename T>
class Point {
public:
    /**
     * @brief 默认构造、有参构造、移动构造
     */

    /**
     * @brief 重载 + - 运算符
     */

    /**
     * @brief 重载 << 运算符
     * out example: [(Point)(x, y, z)]
     */

private:
    T x, y, z;
};

/**
 * @brief 要求 COUNT 成员变量能够实现每创建(销毁)一个实例时 COUNT++(COUNT--)
 */
class Tracker {
    enum class TrackerType {
        DYNAMIC,
        STATIC
    };
public:
    /**
     * @brief 默认构造、有参构造、复制构造、移动构造、析构函数(此处要求的每个构造、析构函数，在调用时都要求输出对应函数名)
     */

    /**
     * @brief 重载 << 运算符，实现输出
     * out example: [(Tracker)->COUNT: _; target_id: _; target_name: _; target_center_point: _; tracker_type: _;]
     */

private:
    static const int COUNT;

    int m_target_id;
    char* m_target_name;
    Point<double> m_target_center_point;
    TrackerType m_tracker_type = TrackerType::DYNAMIC;
};

#endif //VERSION_TEST_CLASS_TEST_H
