#include <iostream>
#include <vector>
#include <sstream>

struct Time {
    int start_hour, start_minute, end_hour, end_minute;
};

bool isTimeOverlap(const Time& t1, const Time& t2) {
    return t1.start_hour < t2.end_hour && t1.end_hour > t2.start_hour &&
           t1.start_minute < t2.end_minute && t1.end_minute > t2.start_minute;
}

int main() {
    int num_class_time_slots;
    std::vector<Time> class_time_slots;

    std::cin >> num_class_time_slots;
    class_time_slots.resize(num_class_time_slots);

    for (int i = 0; i < num_class_time_slots; i++) {
        std::string input;
        std::getline(std::cin >> std::ws, input);
        std::istringstream iss(input);

        while (iss) {
            std::string time_slot_str;
            iss >> time_slot_str;

            if (time_slot_str.empty()) {
                continue;
            }

            char dummy;
            Time& time_slot = class_time_slots[i];
            std::istringstream ss(time_slot_str);
            ss >> time_slot.start_hour >> dummy >> time_slot.start_minute >> dummy
               >> time_slot.end_hour >> dummy >> time_slot.end_minute;
        }
    }

    int num_teachers, num_students;
    std::cin >> num_teachers;

    std::vector<std::vector<Time>> teacher_schedules(num_teachers);

    for (int i = 0; i < num_teachers; i++) {
        int num_time_zones;
        std::cin >> num_time_zones;
        teacher_schedules[i].resize(num_time_zones);

        for (int j = 0; j < num_time_zones; j++) {
            Time time_zone;
            std::cin >> time_zone.start_hour >> time_zone.start_minute
                >> time_zone.end_hour >> time_zone.end_minute;

            teacher_schedules[i][j] = time_zone;
        }
    }

    std::cin >> num_students;
    std::vector<std::vector<Time>> student_schedules(num_students);

    for (int i = 0; i < num_students; i++) {
        int num_time_zones;
        std::cin >> num_time_zones;
        student_schedules[i].resize(num_time_zones);

        for (int j = 0; j < num_time_zones; j++) {
            Time time_zone;
            std::cin >> time_zone.start_hour >> time_zone.start_minute
                >> time_zone.end_hour >> time_zone.end_minute;

            student_schedules[i][j] = time_zone;
        }
    }

    int max_lessons = 0;

    for (const Time& class_time : class_time_slots) {
        int lessons = 0;

        for (const std::vector<Time>& teacher_schedule : teacher_schedules) {
            for (const Time& teacher_time : teacher_schedule) {
                for (const std::vector<Time>& student_schedule : student_schedules) {
                    for (const Time& student_time : student_schedule) {
                        if (isTimeOverlap(teacher_time, class_time) && isTimeOverlap(student_time, class_time)) {
                            lessons++;
                        }
                    }
                }
            }
        }

        max_lessons = std::max(max_lessons, lessons);
    }

    std::cout << max_lessons << std::endl;

    return 0;
}