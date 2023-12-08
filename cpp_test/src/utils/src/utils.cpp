/**
 * @projectName
 * @file utils.cpp
 * @brief 
 * 
 * @author yx 
 * @date 2023-09-21 18:03
 */

#include <utils/utils.h>

template <>
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

template <>
std::string toString(const std::vector<SubstringInfo>& vec) {
    std::string result;
    for (const auto& item: vec)
        result += item.toString() + "\n\t";

    return result;
}

void writeToFile(const std::string& filename, const std::string& mess) {
    std::ofstream file_handle(filename);
    if (!file_handle) {
        std::cerr << "No Open File: " << filename << std::endl;
        return;
    }

    file_handle << mess;
    file_handle.close();
}

void splitString(const std::string& str, const std::string& c, std::vector<std::string>* substrings) {
    size_t find_start_index = 0;
    size_t fined_index = 0;
    while (find_start_index < str.length()) {
        fined_index = str.find(c, find_start_index);
        // 开头匹配到
        if (fined_index == 0) {
            find_start_index++;
            substrings->emplace_back("");
            continue;
        }
        // 找到
        if (fined_index != std::string::npos) {
            substrings->emplace_back(str.substr(find_start_index, fined_index - find_start_index));
            find_start_index = fined_index + 1;
        } else {  // 没有匹配直接取到结尾
            substrings->emplace_back(str.substr(find_start_index));
            break;
        }
    }
}

void splitString(const std::string& str, const char& c, std::vector<std::string>* substring) {
    splitString(str, std::string(1, c), substring);
}

void sortString(std::vector<std::string>& str_vec, const SortType& type) {
    auto min_to_max = [](std::string& a, std::string& b){
        return a.length() < b.length();
    };
    auto max_to_min = [](std::string& a, std::string& b){
        return a.length() > b.length();
    };
    switch (type) {
        case SortType::MIN_TO_MAX: {
            std::sort(str_vec.begin(), str_vec.end(), min_to_max);
            break;
        }
        case SortType::MAX_TO_MIN: {
            std::sort(str_vec.begin(), str_vec.end(), max_to_min);
            break;
        }
        default: {
            std::cout << "Failed strSort(): Unknown Type -> " << type << std::endl;
            return;
        }
    }
}

std::vector<SubstringInfo> findLongestSubstring(const std::string& str) {
    std::vector<SubstringInfo> result;
    std::vector<SubstringInfo> all;
    std::string substring{};

    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (substring.find(str[j]) != std::string::npos) {
                all.emplace_back(substring);
                break;
            }
            substring +=  str[j];
        }
        substring = "";
    }

    std::sort(all.begin(), all.end(), [](const SubstringInfo& a, const SubstringInfo& b){
        return a > b;
    });

    for (int i = 0; i < all.size(); i++) {
        result.push_back(all[i]);
        if (all[i].length != all[i + 1].length)
            break;
    }
    return result;
}

void selectFunction(const Info& info) {
    if (info.id == 0) {
        std::string info_string;
        info_string += "info: ";
        info_string += "\n\tfun_code: " + std::to_string(info.fun_code);
        info_string += "\n\tid: " + std::to_string(info.id);
        info_string += "\n\tmess: ";
        info_string += "\n\t\tmess_1: " + info.mess_1;
        info_string += "\n\t\tmess_2: " + info.mess_2;
        info_string += "\nresult: \n\t";
        switch (info.fun_code) {
            case 0: {
                printf("You called the writeToFile function\n");
                writeToFile(info.mess_1, info_string + info.mess_2);
                break;
            }
            case 2: {
                printf("You called the splitString function\n");
                std::vector<std::string> result;
                splitString(info.mess_1, info.mess_2, &result);
                writeToFile("../data/splitString.txt", info_string + toString(result));
                break;
            }
            case 3: {
                printf("You called the sortString function\n");

                std::vector<std::string> result;
                splitString(info.mess_1, ",", &result);
                SortType sort_type = info.mess_2 == "0"? SortType::MIN_TO_MAX: SortType::MAX_TO_MIN;
                sortString(result, sort_type);
                writeToFile("../data/sortString.txt", info_string + toString(result));
                break;
            }
            case 5:{
                printf("You called the findLongestSubstring function\n");

                auto result = findLongestSubstring(info.mess_1);
                writeToFile("../data/findLongestSubstring.txt", info_string + toString(result));
                break;
            }
        }
    }
}
