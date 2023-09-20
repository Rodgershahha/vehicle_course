#pragma once
#include <vector>
#include <string>
#include "SmartCar.h"
#include "Student.h"


// 从指定目录中读取智能小车信息文件并解析为SmartCar对象，存储在一个std::vector中并返回
std::vector<SmartCar> readSmartCarsFromDirectory(const std::string& directoryPath);

// 从给定文件路径中解析智能小车信息，并返回一个SmartCar对象
SmartCar parseSmartCarInfoFromFile(const std::string& filePath);

// 手动输入学生信息，包括学生ID和姓名，然后将信息设置到Student对象中
void inputStudentInfo(Student& student, std::string stuId, std::string name);

// 手动输入智能小车信息
void inputSmartCarInfo(SmartCar& car, std::string car_id);

// 生成指定长度的随机数字字符串
std::string generateRandomDigits(int n);

// 在学生数组中搜索指定ID的学生，并返回指向该学生的指针。如果未找到，则返回nullptr
Student* searchStuIfExist(Student students[], int n, std::string id);

// 生成指定长度的随机字母字符串
std::string generateRandomLetters(int length);

// 在终端显示给定的智能小车向量中的信息
void showCarVecInfoInTermial(std::vector<SmartCar> cars);

// 手动输入智能小车信息
void inputSmartCarInfoManually(SmartCar& car);

// 生成随机的中文姓名
std::string generateRandomChineseName();

// 提示用户是否执行自动操作（例如，生成随机信息），并根据用户输入返回true或false
bool isAutoOperation(const std::string& tip);

