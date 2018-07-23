//
//  main.cpp
//  CalVolume
//
//  Created by coriander on 6/9/17.
//  Copyright © 2017 xiaowoCorp. All rights reserved.
//

#include <iostream>
#include <vector>
#include<cmath>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<algorithm>
#include <opencv2/opencv.hpp>
class Tetranhedron
{
private:
	cv::Point3d p1,p2,p3,p4;
public:
    Tetranhedron(cv::Point3d p1,cv::Point3d p2,cv::Point3d p3,cv::Point3d p4):p1(p1),p2(p2),p3(p3),p4(p4){}
    double volume() {
    	cv::Vec3d e1(p2 - p1);
    	cv::Vec3d e2(p3 - p1);
		cv::Vec3d h(p4 - p1);
		cv::Vec3d s = e1.cross(e2);
		double r=s.ddot(h)/6;
		return std::abs(r);
	}
};
double calulatePentahedronVolume(cv::Point3d& pt1,cv::Point3d& pt2,cv::Point3d& pt3,
		cv::Point3d& pt4,cv::Point3d& pt5,cv::Point3d& pt6){
    Tetranhedron t1(pt1,pt2,pt3,pt4);
    Tetranhedron t2(pt2,pt3,pt4,pt5);
    Tetranhedron t3(pt2,pt4,pt5,pt6);
    return t1.volume()+t2.volume()+t3.volume();
}

int main(int argc, const char * argv[]) {
	return 0;
}
