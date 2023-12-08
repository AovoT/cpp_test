//
// Created by zps on 23-10-19.
//

#include <basic/basic.h>
#include <set>

float calculate(float head) {
    float result = 0.0f;
    if (head > 99.5 || head < 1.5)
        return result;

    int symbol = 1;
    for (float i = head; i < 99.5; i += 2.0f) {
        result += static_cast<float>(symbol) * i;
        symbol = -symbol;
    }

    return result;
}

std::vector<int> addRows(const Matrix& arr2D) {
    std::vector<int> result;
    int rows = arr2D.size();
    int cols = arr2D[0].size();

    int row_total{};
    for (int row = 0; row < rows; ++row) {
        row_total = 0;
        for (int col = 0; col < cols; ++col)
            row_total += arr2D[row][col];
        result.push_back(row_total);
    }
    return result;
}

std::vector<int> addCols(const Matrix& arr2D) {
    std::vector<int> result;
    int rows = arr2D.size();
    int cols = arr2D[0].size();

    int current_col_total{};
    for (int col = 0; col < cols; ++col) {
        current_col_total = 0;
        for (int row = 0; row < rows; ++row)
            current_col_total += arr2D[row][col];
        result.push_back(current_col_total);
    }
    return result;
}

float addRet(const Matrix& arr2D) {
    // find max value
    int max_val = arr2D[0][0];
    for (int i = 0; i < arr2D.size(); ++i) {
        for (int j = 0; j < arr2D[i].size(); ++j) {
            if (arr2D[i][j] > max_val)
                max_val = arr2D[i][j];
        }
    }
    return calculate(static_cast<float>(max_val));
}

MatrixFloat normalArray2D(const Matrix& arr2D) {
    MatrixFloat normal_result;
    int rows = arr2D.size();
    int cols = arr2D[0].size();
    normal_result.resize(rows);

    for (int i = 0; i < rows; ++i) {
        normal_result[i].resize(cols);
        for (int j = 0; j < cols; ++j)
            normal_result[i][j] = static_cast<float>(arr2D[i][j]) / 255.0f;
    }
    return normal_result;
}

StudentInfoResult studentStatistics(StudentInfo student_info[], const int& n) {
    int age_total{};
    if (n >= 3)
        age_total = student_info[0].age + student_info[2].age;

    std::set<std::string> founded_students;
    auto insert_if = [](std::set<std::string>& set, std::string& element) {
        if (set.find(element) == set.end())
            set.insert(element);
    };
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (student_info[i].college == student_info[j].college) {
                insert_if(founded_students, student_info[i].name);
                insert_if(founded_students, student_info[j].name);
            }
        }
    }
    std::string names;
    for (const auto& item: founded_students)
        names += item + ", ";
    return StudentInfoResult(age_total, static_cast<int>(founded_students.size()), names);
}
