#include <iostream>
#include "Chassis.h"
#include "Lidar.h"
#include "tool.h"

using namespace std;

int main() {
		Lidar lidar;
		Chassis chassis1;

		chassis1.setId("底盘");
		chassis1.attachLidar(&lidar);
		
		// 模拟障碍物状态的变化
		int obstacleIndex = 0;
		while (obstacleIndex!=4)
		{
			cout << "当前障碍物状态（输入1代表前方障碍，2代表左前方障碍，3代表右前方障碍，4代表结束程序）：";
			cin >> obstacleIndex;
			lidar.updateObstacleStatus(static_cast<ObstacleStatus>(obstacleIndex));
		}
		return 0;
}
