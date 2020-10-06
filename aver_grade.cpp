#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Stu {
private:
    string name;
    vector<int> grades;
    double aver_grade;
public:
    Stu(string name) : name(name) {}
    void set_grade(int grade) {
        grades.push_back(grade);
    }
    void set_aver() {
        double sum = 0;
        int n = grades.size();
        if (grades.size() > 5) {
            nth_element(grades.begin(), grades.begin() + n - 5, grades.end());
            for (int i = n - 5; i < n; i++) {
                sum += grades[i];
            }
            aver_grade = sum / 5;
        } else {
            for (int i = 0; i < n; i++) {
                sum += grades[i];
            }
            aver_grade = sum / n;
        }
    }
    string get_name() {
        return name;
    }
    double get_aver() {
        return aver_grade;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Stu*> stus;
    unordered_map<string, int> flag;
    for (int i = 0; i < n; i++) {
        string name;
        int grade;
        cin >> name >> grade;
        if (flag[name]) {
            stus[flag[name] - 1]->set_grade(grade);
        } else {
            auto stu = new Stu(name);
            stu->set_grade(grade);
            stus.push_back(stu);
            flag[name] = stus.size();
        }
    }
    for (auto stu : stus) {
        stu->set_aver();
    }
    sort(stus.begin(), stus.end(), [](Stu *a, Stu *b) {
        if (a->get_aver() == b->get_aver()) return a->get_name() < b->get_name();
        return a->get_aver() > b->get_aver();
    });
    for (int i = 0; i < stus.size(); i++) {
        printf ("%s %.2lf\n", stus[i]->get_name().c_str(), stus[i]->get_aver());
    }
    return 0;
}
