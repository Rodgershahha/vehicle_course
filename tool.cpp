#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "SmartCar.h"
#include "Student.h"

#ifdef _WIN32
#include <windows.h> // Windows headers
#include <filesystem>
#else
#include <dirent.h>  // Linux headers
#endif

std::string generateRandomLetters(int length) {
	// 定义字母表
	const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// 生成随机字母串
	std::string random_letters;
	for (int i = 0; i < length; ++i) {
		int random_index = std::rand() % alphabet.length();
		random_letters += alphabet[random_index];
	}

	return random_letters;
}

Student* searchStuIfExist(Student students[], int n, std::string id)
{
	for (size_t i = 0; i < n; i++) {
		if (students[i].getStudentID() == id)
			return &students[i];
	}
	return nullptr;
}

// 生成n位随机数字
std::string generateRandomDigits(int n) {
	// 生成随机数字串
	std::string random_digits;
	for (int i = 0; i < n; ++i) {
		int random_digit = std::rand() % 10;  // 生成0到9之间的随机数字
		random_digits += std::to_string(random_digit);
	}

	return random_digits;
}

void inputSmartCarInfo(SmartCar& car, std::string car_id) {
	// 填充智能小车信息，包括底盘、AGX套件、双目摄像头、激光雷达、陀螺仪、液晶显示屏、电池模块
	car.setId(car_id);

	Chassis chassis;
	chassis.setId("dp" + generateRandomDigits(8) + generateRandomLetters(2));
	chassis.setModel("SCOUT MINI");
	chassis.setWheelbase("451.0");
	chassis.setTrack("490.0");
	chassis.setGroundClearance("115.0");
	chassis.setTurningRadius("0.0");
	chassis.setDriveType("四轮四驱");
	chassis.setMaxTravel("10.0");
	chassis.setTireModel("公路轮");
	chassis.setTireSize("175.0");

	AGXKit agxKit;
	agxKit.setModel("AGX Xavier");
	agxKit.setAIPerformance("32.0");
	agxKit.setCudaCores("512");
	agxKit.setTensorCores("64");
	agxKit.setMemory("32.0");
	agxKit.setStorage("32.0");

	Camera camera;
	camera.setModel("RealSense D435i");
	camera.setCameraType("D430");
	camera.setResolution("1920x1080");
	camera.setFrameRate("30");
	camera.setFOV("87.58");
	camera.setDepthFrameRate("90");

	Lidar lidar;
	lidar.setModel("RS-Helios-16p");
	lidar.setChannels("16");
	lidar.setRange("100.0");
	lidar.setPowerConsumption("8.0");

	Gyroscope gyroscope;
	gyroscope.setModel("CH110");
	gyroscope.setManufacturer("NXP");

	Display display;
	display.setSize("11.6");
	display.setModel("super");

	Battery battery;
	battery.setParameters("24V/15Ah");
	battery.setExternalPower("24.0");
	battery.setChargingDuration("2.0");

	car.setChassis(chassis);
	car.setAGXKit(agxKit);
	car.setCamera(camera);
	car.setLidar(lidar);
	car.setGyroscope(gyroscope);
	car.setDisplay(display);
	car.setBattery(battery);
}


void inputStudentInfo(Student& student, std::string stuId, std::string name) {
	student.setStudentID(stuId);
	student.setName(name);
}

void inputSmartCarInfoManually(SmartCar& car) {

	// 输入智能小车编号
	std::cout << "请输入智能小车编号: ";
	std::string carID;
	std::cin >> carID;
	car.setId(carID);

	// 输入底盘信息
	Chassis chassis;
	std::cout << "请输入底盘编号: ";
	std::string chassisNumber;
	std::cin >> chassisNumber;
	chassis.setId(chassisNumber);

	std::cout << "请输入底盘型号: ";
	std::string chassisModel;
	std::cin >> chassisModel;
	chassis.setModel(chassisModel);

	std::cout << "请输入底盘轴距 (mm): ";
	std::string wheelbase;
	std::cin >> wheelbase;
	chassis.setWheelbase(wheelbase);

	std::cout << "请输入底盘轮距 (mm): ";
	std::string track;
	std::cin >> track;
	chassis.setTrack(track);

	std::cout << "请输入最小离地间隙 (mm): ";
	std::string groundClearance;
	std::cin >> groundClearance;
	chassis.setGroundClearance(groundClearance);

	std::cout << "请输入最小转弯半径 (m): ";
	std::string turningRadius;
	std::cin >> turningRadius;
	chassis.setTurningRadius(turningRadius);

	std::cout << "请输入驱动形式: ";
	std::string driveType;
	std::cin >> driveType;
	chassis.setDriveType(driveType);

	std::cout << "请输入最大行程 (KM): ";
	std::string maxTravel;
	std::cin >> maxTravel;
	chassis.setMaxTravel(maxTravel);

	// 输入轮胎信息
	std::cout << "请输入轮胎型号: ";
	std::string tireModel;
	std::cin >> tireModel;
	chassis.setTireModel(tireModel);

	std::cout << "请输入轮胎尺寸 (mm): ";
	std::string tireSize;
	std::cin >> tireSize;
	chassis.setTireSize(tireSize);

	// 输入AGX套件信息
	AGXKit agxKit;
	std::cout << "请输入AGX套件型号: ";
	std::string agxKitModel;
	std::cin >> agxKitModel;
	agxKit.setModel(agxKitModel);

	std::cout << "请输入AI性能 (TOPS): ";
	std::string aiPerformance;
	std::cin >> aiPerformance;
	agxKit.setAIPerformance(aiPerformance);

	std::cout << "请输入CUDA核心数: ";
	std::string cudaCores;
	std::cin >> cudaCores;
	agxKit.setCudaCores(cudaCores);

	std::cout << "请输入Tensor CORE数: ";
	std::string tensorCores;
	std::cin >> tensorCores;
	agxKit.setTensorCores(tensorCores);

	std::cout << "请输入显存 (G): ";
	std::string memory;
	std::cin >> memory;
	agxKit.setMemory(memory);

	std::cout << "请输入存储 (G): ";
	std::string storage;
	std::cin >> storage;
	agxKit.setStorage(storage);

	// 输入相机信息
	Camera camera;
	std::cout << "请输入相机型号: ";
	std::string cameraModel;
	std::cin >> cameraModel;
	camera.setModel(cameraModel);

	std::cout << "请输入相机类型: ";
	std::string cameraType;
	std::cin >> cameraType;
	camera.setCameraType(cameraType);

	std::cout << "请输入相机分辨率: ";
	std::string resolution;
	std::cin >> resolution;
	camera.setResolution(resolution);

	std::cout << "请输入相机帧率: ";
	std::string frameRate;
	std::cin >> frameRate;
	camera.setFrameRate(frameRate);

	std::cout << "请输入FOV: ";
	std::string fov;
	std::cin >> fov;
	camera.setFOV(fov);

	std::cout << "请输入深度帧率: ";
	std::string depthFrameRate;
	std::cin >> depthFrameRate;
	camera.setDepthFrameRate(depthFrameRate);

	// 输入激光雷达信息
	Lidar lidar;
	std::cout << "请输入激光雷达型号: ";
	std::string lidarModel;
	std::cin >> lidarModel;
	lidar.setModel(lidarModel);

	std::cout << "请输入激光雷达通道数: ";
	std::string channels;
	std::cin >> channels;
	lidar.setChannels(channels);

	std::cout << "请输入激光雷达测试范围 (m): ";
	std::string testRange;
	std::cin >> testRange;
	lidar.setRange(testRange);

	std::cout << "请输入激光雷达功耗 (W): ";
	std::string powerConsumption;
	std::cin >> powerConsumption;
	lidar.setPowerConsumption(powerConsumption);

	// 输入陀螺仪信息
	Gyroscope gyroscope;
	std::cout << "请输入陀螺仪型号: ";
	std::string gyroscopeModel;
	std::cin >> gyroscopeModel;
	gyroscope.setModel(gyroscopeModel);

	std::cout << "请输入陀螺仪制造商: ";
	std::string gyroscopeManufacturer;
	std::cin >> gyroscopeManufacturer;
	gyroscope.setManufacturer(gyroscopeManufacturer);

	// 输入液晶显示屏信息
	Display display;
	std::cout << "请输入液晶显示屏尺寸 (英寸): ";
	std::string displaySize;
	std::cin >> displaySize;
	display.setSize(displaySize);

	std::cout << "请输入液晶显示屏型号: ";
	std::string displayModel;
	std::cin >> displayModel;
	display.setModel(displayModel);

	// 输入电池模块信息
	Battery battery;
	std::cout << "请输入电池参数: ";
	std::string batteryParameters;
	std::cin >> batteryParameters;
	battery.setParameters(batteryParameters);

	std::cout << "请输入外部电源电压 (V): ";
	std::string externalPower;
	std::cin >> externalPower;
	battery.setExternalPower(externalPower);

	std::cout << "请输入充电时长 (H): ";
	std::string chargingDuration;
	std::cin >> chargingDuration;
	battery.setChargingDuration(chargingDuration);

	// 输入学生信息
	Student studentInfo;
	std::cout << "请输入学生姓名: ";
	std::string studentName;
	std::cin >> studentName;
	studentInfo.setName(studentName);

	std::cout << "请输入学生学号: ";
	std::string studentID;
	std::cin >> studentID;
	studentInfo.setStudentID(studentID);

	// 将所有输入的信息设置到智能小车类中
	car.setChassis(chassis);
	car.setAGXKit(agxKit);
	car.setCamera(camera);
	car.setLidar(lidar);
	car.setGyroscope(gyroscope);
	car.setDisplay(display);
	car.setBattery(battery);
	car.setStudentInfo(studentInfo);
}


SmartCar parseSmartCarInfoFromFile(const std::string& filePath) {
	SmartCar car;

	std::ifstream file(filePath);
	Chassis chassis;
	AGXKit agxKit;
	Camera camera;
	Lidar lidar;
	Gyroscope gyroscope;
	Display display;
	Battery battery;
	Student studentInfo;

	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string key, value;
			std::getline(iss, key, ':');
			std::getline(iss, value);

			if (key == "智能小车编号")
				car.setId(value);
			else if (key == "底盘编号")
				chassis.setId(value);
			else if (key == "底盘型号")
				chassis.setModel(value);
			else if (key == "轴距")
				chassis.setWheelbase(value);
			else if (key == "轮距")
				chassis.setTrack(value);
			else if (key == "最小离地间隙")
				chassis.setGroundClearance(value);
			else if (key == "最小转弯半径")
				chassis.setTurningRadius(value);
			else if (key == "驱动形式")
				chassis.setDriveType(value);
			else if (key == "最大行程")
				chassis.setMaxTravel(value);
			else if (key == "轮胎信息") {
				std::getline(iss, key, ':');
				std::getline(iss, value);
				if (key == "轮胎型号") {
					chassis.setTireModel(value);
				}
				else if (key == "尺寸") {
					chassis.setTireSize(value);
				}
			}
			else if (key == "AGX套件型号")
				agxKit.setModel(value);
			else if (key == "AI性能")
				agxKit.setAIPerformance(value);
			else if (key == "CUDA核心数")
				agxKit.setCudaCores(value);
			else if (key == "Tensor CORE数")
				agxKit.setTensorCores(value);
			else if (key == "显存")
				agxKit.setMemory(value);
			else if (key == "存储")
				agxKit.setStorage(value);
			else if (key == "双目摄像头型号")
				camera.setModel(value);
			else if (key == "摄像头类型")
				camera.setCameraType(value);
			else if (key == "RGB帧分辨率")
				camera.setResolution(value);
			else if (key == "RGB帧率")
				camera.setFrameRate(value);
			else if (key == "FOV")
				camera.setFOV(value);
			else if (key == "深度帧率")
				camera.setDepthFrameRate(value);
			else if (key == "多线激光雷达型号")
				lidar.setModel(value);
			else if (key == "通道数")
				lidar.setChannels(value);
			else if (key == "测试范围")
				lidar.setRange(value);
			else if (key == "功耗")
				lidar.setPowerConsumption(value);
			else if (key == "9轴陀螺仪型号")
				gyroscope.setModel(value);
			else if (key == "制造商")
				gyroscope.setManufacturer(value);
			else if (key == "液晶显示屏尺寸")
				display.setSize(value);
			else if (key == "液晶显示屏型号")
				display.setModel(value);
			else if (key == "电池参数")
				battery.setParameters(value);
			else if (key == "外部电源")
				battery.setExternalPower(value);
			else if (key == "充电时长")
				battery.setChargingDuration(value);
			else if (key == "学生姓名")
				studentInfo.setName(value);
			else if (key == "学号")
				studentInfo.setStudentID(value);
		}
		car.setChassis(chassis);
		car.setAGXKit(agxKit);
		car.setCamera(camera);
		car.setDisplay(display);
		car.setGyroscope(gyroscope);
		car.setLidar(lidar);
		car.setStudentInfo(studentInfo);
		car.setBattery(battery);
		file.close();
		std::cout << "已载入小车信息" << car.getId() << std::endl;
	}

	return car;
}

std::vector<SmartCar> readSmartCarsFromDirectory(const std::string& directoryPath) {
	std::vector<SmartCar> cars;

#ifdef _WIN32
	for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
		if (entry.is_regular_file()) {
			std::string filePath = entry.path().string();
			SmartCar car = parseSmartCarInfoFromFile(filePath);
			cars.push_back(car);
		}
	}
#else
	DIR* dir = opendir(directoryPath.c_str());
	if (dir != nullptr) {
		struct dirent* entry;
		while ((entry = readdir(dir))) {
			if (entry->d_type == DT_REG) {
				std::string filePath = directoryPath + "/" + entry->d_name;
				SmartCar car = parseSmartCarInfoFromFile(filePath);
				cars.push_back(car);
			}
		}
		closedir(dir);
	}
#endif

	return cars;
}

void showCarVecInfoInTermial(std::vector<SmartCar> cars)
{
	std::cout << "----------显示智能小车信息----------" << std::endl;
	char choice;
	int current_car = 0;
	do {
		cars[current_car].print();
		std::cout << "按‘n’表示下一辆车，按‘p’表示上一辆车，按‘q’表示退出 :";
		std::cin >> choice;

		if (choice == 'n' && current_car < cars.size() - 1) {
			current_car++;
		}
		else if (choice == 'p' && current_car > 0) {
			current_car--;
		}

	} while (choice != 'q');
}

// 随机生成中文姓名
std::string generateRandomChineseName() {
	// 姓氏列表
	std::vector<std::string> first_names = {
		"赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈",
		"褚", "卫", "蒋", "沈", "韩", "杨", "朱", "秦", "尤", "许",
		"何", "吕", "施", "张", "孔", "曹", "严", "华", "金", "魏"
	};

	// 名字列表
	std::vector<std::string> last_names = {
		"伟", "娜", "敏", "静", "强", "亮", "磊", "军", "洋", "芳",
		"梅", "秀", "慧", "丽", "明", "超", "霞", "平", "杰", "勇"
	};

	// 随机选择姓氏和名字
	std::string first_name = first_names[rand() % first_names.size()];
	std::string last_name = last_names[rand() % last_names.size()];

	// 返回生成的中文姓名
	return first_name + last_name;
}

bool isAutoOperation(const std::string &tip)
{
	// 是否自动生成智能小车信息
	std::string strFlag;
	std::cout << tip;
	std::cin >> strFlag;
	if (strFlag == "y" || strFlag == "Y") {
		return true;
	}
	return false;
}