/**
 * @brief 做顺题序
 */

#include <iostream>

#include <basic/basic.h>
#include <utils/utils.h>
#include <class_test/class_test.h>

std::string toString(const std::vector<std::string>& vec) {
    std::string result("[");
    for (int i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i != vec.size() - 1)
            result += ", ";
    }
    result += "]";
    return result;
}

std::string toString(const SubstringInfo& substring_info) {
    return substring_info.toString();
}

int main() {
    printf("------------------calculate()函数测试----------------------\n");
    auto a = calculate(3.5);
    std::cout << "calculate(): " << a << std::endl;

    printf("------------------矩阵相关测试----------------------\n");
    // test_arr2d
    Matrix test_arr2D {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    std::cout << "test_arr2d: " << toString(test_arr2D) << std::endl;
    // addRows
    std::vector<int> add_rows_result = addRows(test_arr2D);
    std::cout << "add_rows_result: " << toString(add_rows_result) << std::endl;
    // addCols
    auto add_cols_result = addCols(test_arr2D);
    std::cout << "add_cols_result: " << toString(add_cols_result) << std::endl;
    // addRet
    auto add_ret_result = addRet(test_arr2D);
    std::cout << "add_ret_result: "<< add_ret_result << std::endl;
    // normalArray2D
    auto normal_result = normalArray2D(test_arr2D);
    std::cout << "normal_result: " << toString(normal_result) << std::endl;

    printf("------------------结构体测试----------------------\n");
    // studentStatistics()
    StudentInfo test_student_info[10] {
            {"1", 19, "电气"},
            {"2", 19, "吹奏部"},
            {"3", 20, "电气"},
            {"4", 21, "美术"},
            {"5", 22, "纺织"},
            {"6", 21, "弓道"},
            {"7", 22, "美术"},
            {"8", 19, "吹奏部"},
            {"9", 22, "美术"},
            {"10", 21, "纺织"}
    };
    auto statistics_result = studentStatistics(test_student_info, 10);
    std::cout << statistics_result << std::endl;
    printf("------------------类测试----------------------\n");
    Point<int> point(1, 2, 3);
    std::cout << point << std::endl;
    std::cout << point + 1 << std::endl;
    Point<int> point_1(5, 6, 8);
    std::cout << point + point_1 << std::endl;

    Tracker t1;
    Tracker t2(1, "有参构造", Point<double>(1.0, 2.0, 3.0), Tracker::TrackerType::DYNAMIC);
    Tracker t3 = t2;
    Tracker t4 = std::move(t3);

    printf("------------------selectFunction()函数测试----------------------\n");
    Info info_0(0, 0, "../data/writeToFile.txt", "test");
    selectFunction(info_0);
    // splitString
    Info info_2(2, 0, "/usr/local/include", "/");
    selectFunction(info_2);
    // sortString
    Info info_3(3, 0, "was,asfasg,adgasdhads,as", "0");
    selectFunction(info_3);
    // findLongestSubstring
    Info info_5(5, 0, "asdgasgeraasdgsa", "");
    selectFunction(info_5);

    printf("------------------程序结束----------------------\n");
    return 0;
}


