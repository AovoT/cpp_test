//
// Created by zps on 23-10-21.
//

#ifndef VERSION_TEST_MESSAGE_INTERFACE_H
#define VERSION_TEST_MESSAGE_INTERFACE_H

/**
 * @brief 消息结构体
 */
struct Info {
    // fun_code
    // id
    // mess_1
    // mess_2

    /**
     * @brief 构造函数
     *
     * @param _code
     * @param _id
     * @param _mess_1
     * @param _mess_2
     */
};

/**
 * @brief 枚举类型的排序方式(升序 和 降序)
 */
enum SortType {

};

/**
 * @brief 子字符串info
 */
struct SubstringInfo {
    // (子)字符串
    // 长度

    /**
     * @brief 默认构造函数
     */

    /**
     * @brief 构造函数
     *
     * @param _str
     */


    /**
     * @brief < 运算符重载(根据this->长度)
     *
     * @param other
     * @return
     */

    /**
     * @brief > 运算符重载(根据this->长度)
     *
     * @param other
     * @return
     */

    /**
     * @brief == 运算符重载(根据this->长度)
     *
     * @param other
     * @return
     */

    /**
     * @brief 返回结构体的字符串形式
     * @example
     *  [out] "[SubstringInfo]: [str: " + 字符 + ", " + "length: " + 长度 + " ]\n";
     *
     * @return 结构体的字符串形式
     */

    /**
     * @brief << 运算符重载(friend function)
     *
     * @param os
     * @param other SubstringInfo对象
     * @return std::ostream对象
     */
};

#endif //VERSION_TEST_MESSAGE_INTERFACE_H
