#include <iostream>
#include <map>
#include <string>

using namespace std;

// 학생 정보를 저장할 구조체
struct Student {
    float midterm;
    float final;
};

int main() {
    int studentCount;
    map<string, Student> students; // 학생 이름을 키로 하고, Student 구조체를 값으로 저장하는 맵

    // 학생 수 입력
    cout << "학생 수를 입력하세요: ";
    cin >> studentCount;

    // 학생 정보 입력
    for (int i = 0; i < studentCount; i++) {
        string name;
        Student student;

        cout << "학생 " << (i + 1) << "의 이름을 입력하세요: ";
        cin >> name;
        cout << "학생 " << (i + 1) << "의 중간 점수를 입력하세요: ";
        cin >> student.midterm;
        cout << "학생 " << (i + 1) << "의 기말 점수를 입력하세요: ";
        cin >> student.final;

        // 학생 정보 추가
        students[name] = student;
    }

    // 학생 정보 출력
    cout << "\n학생 정보 (이름 순서):\n";
    for (const auto& entry : students) {
        cout << "이름: " << entry.first 
             << ", 중간 점수: " << entry.second.midterm 
             << ", 기말 점수: " << entry.second.final << endl;
    }

    return 0;
}

