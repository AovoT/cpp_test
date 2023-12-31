//
// Created by zps on 23-10-19.
//

#ifndef VERSION_TEST_BASIC_H
#define VERSION_TEST_BASIC_H

#include <cstdio>

#include <ostream>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;
using MatrixFloat = std::vector<std::vector<float>>;

/**
 * @brief 计算从 head 开始到 99.5 结束的一个有规律数列的和
 *  if (head >= 99.5) return 0;
 * @example
 * >>> calculate(1.5);
 * 要计算数列: 1.5 - 3.5 + 5.5 - 7.5 ... - 99.5
 *
 * @param head 首个数字 1.5
 * @return
 */
float calculate(float head);

/**
 * @brief 计算二维数组每行的和
 *
 * @param arr2D 二维数组
 *
 * @return 二维数组每行的和
 */
std::vector<int> addRows(const Matrix& arr2D);

/**
 * @brief 计算二维数组每列的和
 *
 * @param arr2D 二维数组
 *
 * @return 二维数组每列的和
 */
std::vector<int> addCols(const Matrix& arr2D);

/**
 * @brief 计算二维数组中最大的值 max_val + calculate(max_val)
 *
 * @param arr2D 二维数组
 *
 * @return
 */
float addRet(const Matrix& arr2D);

/**
 * float range = max_pixel - min_pixel; (255 - 0)
 * float new_pixel = (original_pixel - min_pixel) / range
 * @brief 对数字图像进行[0, 1]归一化，将此数字图像的像素值变为 0 到 1，并返回这个数字图像的二维数组
 *
 * @param arr2D 原二维数组
 *
 * @return 归一化后的二维数组
 */
MatrixFloat normalArray2D(const Matrix& arr2D);

/**
 * @brief 三.使用结构体统计三名新生信息：（姓名，年龄，学院)
 *        键盘输入三名新生信息
 * @return 第一名新生和第三名新生的年龄和, 学院相同的人的个数 , 他们的名字
 * @example
 * [in] 张三 18 电气
 *      李四 18 信息
 *      王五 19 材料
 * [out] 37 None
 *
 * @example
 * [in] 张三 18 电气
 *      李四 18 信息
 *      王五 19 信息
 * [out] 37 2 李四 王五
 */
struct StudentInfo {
    std::string name;  // name
    int age;  // age
    std::string college;  // college

    StudentInfo(const std::string& name, const int& age, const std::string& college)
        : name(name),
          age(age),
          college(college)
    {}
};


struct StudentInfoResult {
    int age_total;
    int same_count;
    std::string names;

    StudentInfoResult(const int& _age_total, const int& _same_count, const std::string& _names)
        : age_total(_age_total),
          same_count(_same_count),
          names(_names)
    {}

    friend std::ostream& operator<<(std::ostream& os, const StudentInfoResult& result) {
        os << "[(StudentInfoResult)age_total: " << result.age_total
           << "; same_count: " << result.same_count
           << "; names: " << result.names << "]";
        return os;
    }
};

StudentInfoResult studentStatistics(StudentInfo student_info[], const int& n);

#endif //VERSION_TEST_BASIC_H