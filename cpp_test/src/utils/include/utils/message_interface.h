//
// Created by zps on 23-10-21.
//

#ifndef VERSION_TEST_MESSAGE_INTERFACE_H
#define VERSION_TEST_MESSAGE_INTERFACE_H

#include <string>
#include <vector>

/**
 * @brief 消息结构体
 */
struct Info {
    int fun_code;  // fun_code
    int id;  // id
    std::string mess_1;  // mess
    std::string mess_2;  //

    /**
     * @brief 构造函数
     *
     * @param _fun_code
     * @param _id
     * @param _mess_1
     * @param _mess_2
     */
     Info(const int& _fun_code, const int& _id, const std::string& _mess_1, const std::string& _mess_2)
        : fun_code(_fun_code),
          id(_id),
          mess_1(_mess_1),
          mess_2(_mess_2)
    {}
};

/**
 * @brief 枚举类型的排序方式(升序 和 降序)
 */
enum SortType {
    MIN_TO_MAX,
    MAX_TO_MIN
};

/**
 * @brief 子字符串info
 */
struct SubstringInfo {
    std::string substring;  // (子)字符串
    int length;  // 长度

    /**
     * @brief 默认构造函数
     */
     SubstringInfo() =default;

    /**
     * @brief 构造函数
     *
     * @param _str
     */
     SubstringInfo(const std::string& _str)
        : substring(_str),
          length(static_cast<int>(substring.length()))
    {}

    /**
     * @brief < 运算符重载(根据this->长度)
     *
     * @param other
     * @return
     */
     bool operator<(const SubstringInfo& other) const {
         return this->length < other.length;
     }

    /**
     * @brief > 运算符重载(根据this->长度)
     *
     * @param other
     * @return
     */
     bool operator>(const SubstringInfo& other) const {
         return this->length > other.length;
     }

    /**
     * @brief == 运算符重载(根据this->长度)
     *
     * @param other
     * @return
     */
    bool operator==(const SubstringInfo& other) const {
        return this->substring == other.substring &&
                this->length == other.length;
    }

    /**
     * @brief 返回结构体的字符串形式
     * @example
     *  [out] "[SubstringInfo]: [str: " + 字符 + ", " + "length: " + 长度 + " ]\n";
     *
     * @return 结构体的字符串形式
     */
     std::string toString() const {
        std::string result("[(SubstringInfo): ");
        result += "str: " + this->substring + "; length: " + std::to_string(length) + "]";
        return result;
     }

    /**
     * @brief << 运算符重载(friend function)
     *
     * @param os
     * @param other SubstringInfo对象
     * @return std::ostream对象
     */
     friend std::ostream& operator<<(std::ostream& os, const SubstringInfo& _self) {
        os << _self.toString();
        return os;
     }
};

#endif //VERSION_TEST_MESSAGE_INTERFACE_H
