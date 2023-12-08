/**
 * @projectName Project
 * @file utils.cpp
 * @brief 
 * 
 * @author yx 
 * @date 2023-09-19 22:01
 */

#include <utils/message_interface.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

#ifndef SPECIALTEST_TEST_UTILS_H
#define SPECIALTEST_TEST_UTILS_H

/**
 * @brief 向 filename 文件中写入 mess
 * @fun_code 0  -->  用于实现最后一个函数 selectFunction()
 *
 * @param filename[in]
 * @param mess[in]
 */
void writeToFile(const std::string& filename, const std::string& mess);

/**
 * @brief 返回 std::vector的字符串形式(模板函数实现)
 * @example
 *  >>> std::vector<int> vec{0, 1, 2};
 *  "[1, 2, 3]"
 *  >>> std::vector<std::string> vec{"Asf", "asdf", "aaa"};
 *  "["Asf", "asdf", "aaa"]"
 *
 * @tparam T[in] int || float || double || std::string || SubstringInfo(可单独给出重载版本)
 * @param v[in]
 * @return 向量(一维)的字符串形式
 */
template <typename T>
std::string toString(const std::vector<T>& vec) {
    std::string result("[");
    for (int i = 0; i < vec.size(); ++i) {
        result += std::to_string(vec[i]);
        if (i != vec.size() - 1)
            result += ", ";
    }
    result += "]";
    return result;
}

template <>
std::string toString(const std::vector<std::string>& vec);

template <>
std::string toString(const std::vector<SubstringInfo>& vec);

template <typename T>
std::string toString(const std::vector<std::vector<T>>& matrix) {
    std::string result("[\n");
    for (int i = 0; i < matrix.size(); ++i) {
        result += "\t" + toString(matrix[i]);
        if (i != matrix.size() - 1)
            result += ",\n";
    }
    result += "\n]";
    return result;
}

/**
 * @brief 对输入的字符串 str 以 c 进行分割
 * @example
 *  >>> splitString("/usr/local/include", "/");
 *  ["", "usr", "local", "include"]
 *  @fun_code 2
 *
 * @param str[in] 输入字符串
 * @param c[in] 以 c 进行分割
 * @param substring[out] 分割后的结果 数组/向量
 */
void splitString(const std::string& str, const char& c, std::vector<std::string>* substring);

void splitString(const std::string& str, const std::string& c, std::vector<std::string>* substring);

/**
 * @brief 对输入的字符串向量按字符串长度降序/升序
 * @fun_code 3
 *
 * @param str_vec[in] 字符串向量
 * @param type[in] 排序方式
 * @return 排序结果
 */
 void sortString(const std::vector<SubstringInfo>& vec, const SortType& sort_type);

/**
* @brief 寻找最长不含重复的子字符(选做)
* @example
*  >>> findLongestSubstring("abcabcbb");
*  ["abc" 3, "bca" 3, "cab" 3]
*
*  >>> findLongestSubstring("pwwkew");
*  ["wke" 3]
*  @fun_code 5
*
* @param str[in] 输入的字符串
* @return 寻找结果
*/
std::vector<SubstringInfo> findLongestSubstring(const std::string& str);

/**
 * @brief 通过 info.fun_code 进行方法选择(fun_code 不为以上指定fun_code(或 id != 0)时, 打印提示信息并退出程序 \n
 * 不接受 id != 0 的 info, 具体给每个方法的测试输入自己给就行, 函数的输入由 info.mess 给出
 * (对于 sortString() 函数,vec可以给出由 , 作为分隔符传递(如: "asfg,asgq,aspgfino")再通过splitString分割, type 可以由 0 代表升序, 1 代表降序) \n
 * 函数的输出结果 和 info写入 一个文件规定如下(具体示例看data/splitString.txt): \n
 *  filename(文件名): data/函数名.txt \n
 *  content(文件内容): \n
 *      info: \n
 *          fun_code: ${info.fun_code} \n
 *          id: ${info.id} \n
 *          mess: ${info.mess} \n
 *      result: \n
 *          函数返回值的结果(输出尽量美观、清晰) \n
 *
 * @param info
 */
 void selectFunction(const Info& info);

#endif //SPECIALTEST_TEST_UTILS_H


