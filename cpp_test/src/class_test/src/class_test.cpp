//
// Created by zps on 23-10-21.
//

#include <class_test/class_test.h>

int Tracker::COUNT = 0;

Tracker::Tracker() {
    COUNT++;
    std::cout << "默认构造函数(COUNT: " << COUNT << ")" << std::endl;

    m_target_id = COUNT - 1;
    auto len = std::strlen("None Name") + 1;
    m_target_name = new char[len];

    std::strcpy(m_target_name, "None Name");
}

Tracker::Tracker(const int& target_id, const char* target_name,
                 const Point<double>& point,const Tracker::TrackerType& tracker_type)
    : m_target_id(target_id),
      m_target_name(new char[std::strlen(target_name) + 1]),
      m_target_content_point(point),
      m_tracker_type(tracker_type)
{
    COUNT++;
    std::cout << "有参构造函数(COUNT: " << COUNT << ")" << std::endl;

    std::strcpy(m_target_name, target_name);
}

Tracker::Tracker(const Tracker& other)
    : m_target_name(new char[std::strlen(other.m_target_name) + 1])
{
    COUNT++;
    std::cout << "复制构造函数(COUNT: " << COUNT << ")" << std::endl;

    std::strcpy(m_target_name, other.m_target_name);
}

Tracker::Tracker(Tracker&& other)
    : m_target_content_point(std::move(other.m_target_content_point)),
      m_target_id(other.m_target_id),
      m_tracker_type(other.m_tracker_type)
{
    COUNT++;
    std::cout << "移动构造函数(COUNT: " << COUNT << ")" << std::endl;

    m_target_name = other.m_target_name;
    other.m_target_name = nullptr;
}

Tracker::~Tracker() {
    COUNT--;
    std::cout << "析构函数(COUNT: " << COUNT << ")" << std::endl;

    delete[] m_target_name;
}

std::ostream& operator<<(std::ostream& os, const Tracker& tracker) {
    std::string tracker_type_string = tracker.m_tracker_type == Tracker::TrackerType::STATIC? "STATIC": "DYNAMIC";
    os << "[(Tracker)->COUNT: " << Tracker::COUNT
       << "; m_target_id: " << tracker.m_target_id
       << "; m_target_name: " << tracker.m_target_name
       << "; m_target_content_point: " << tracker.m_target_content_point
       << "; m_tracker_type: " << tracker_type_string;
    return os;
}


