#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SmartCar.h"
#include "Student.h"
#include "tool.h"

#define TOTAL_CARS  10

using namespace std;

int main() {
        std::vector<SmartCar> cars;
        cars.resize(TOTAL_CARS) ;
        Student students[TOTAL_CARS];
        if (isAutoOperation("是否自动生成智能小车信息？(y/n)：")){
			// 自动生成智能小车信息
			for (int i = 0; i < TOTAL_CARS; ++i) {
				std::string rand_car_id = "cqusn" + generateRandomDigits(16) + generateRandomLetters(2);
				inputSmartCarInfo(cars[i], rand_car_id);
				std::cout << "----------智能小车" << rand_car_id << "信息已生成----------" << std::endl;
			}
        }
        else {
			for (int i = 0; i < TOTAL_CARS; ++i) {
                std::cout << "----------请录入小车信息----------" << std::endl;
                inputSmartCarInfoManually(cars[i]);
				std::cout << "----------智能小车" << cars[i].getId() << "已录入----------" << std::endl;
			}
        }

        bool isAutoFlag = isAutoOperation("是否自动随机生成学生信息？(y/n)：");
        // 录入学生信息
        for (int i = 0; i < TOTAL_CARS; ++i) {
            std::string stuId;
            std::string name;
            bool flag = true;
            while (flag){
				if (isAutoFlag) {
					stuId = generateRandomDigits(2);
					name = generateRandomChineseName();
				}
				else {
					std::cout << "输入学生信息:\n";
					std::cout << "Student ID: ";
					std::cin >> stuId;
					std::cout << "Name: ";
					std::cin >> name;
				}  
                if (searchStuIfExist(students, TOTAL_CARS, stuId) == nullptr)
                    flag = false;
                else
                    std::cout << "学生id已存在，请重新输入！！！:\n";
            }
            std::cout << "已录入学生 id: " << stuId << "  姓名：" << name << std::endl;
            inputStudentInfo(students[i], stuId, name);
        }
    
        // 分配小车给学生
        isAutoFlag = isAutoOperation("是否自动分配小车给学生？(y/n)：");
        for (int i = 0; i < TOTAL_CARS; ++i) {
            bool flag = true;
            while (flag){
                std::string inputID;
                if (isAutoFlag) {
                    inputID = students[i].getStudentID();
                }
                else{
					std::cout << "智能小车" << cars[i].getId() << "分配给学生的id为";
					std::cin >> inputID;
                }
                Student* stu = searchStuIfExist(students, TOTAL_CARS, inputID);
                if (stu != nullptr) {
                    cars[i].setStudentInfo(*stu);
                    std::cout << "智能小车" << cars[i].getId() << "已经分配给学生id："<< cars[i].getStudentInfo().getStudentID()<<std::endl;
    				std::ofstream file("./data/" +cars[i].getId() + ".txt");
                    if (file.is_open()) {
                        cars[i].save(file);
                    }
                    flag = false;
                }
                else {
                    std::cout << "学生信息不存在，请重新分配!!!" << std::endl;
                }
            }
        }
   
        // 显示智能小车信息
        showCarVecInfoInTermial(cars);
        
        //是否读取小车文件并载入
		if (isAutoOperation("是否读取小车信息文件载入？(y/n)：")) {
			std::vector<SmartCar> cars_vec = readSmartCarsFromDirectory("./data");
			showCarVecInfoInTermial(cars_vec);
		}
        return 0;
}
