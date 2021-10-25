//#pragma once
//#include"Console.h"
//#include"Bird.h"
//
//class TrafficLight {
//	bool stop = false;
//	int milis = 0;
//	int start_time, end_time;
//public:
//	TrafficLight(int a, int b) {
//		start_time = a;
//		end_time = b;
//	}
//	bool getState() { return stop; }
//	void updateState(vector<Bird>& b) {
//		milis += 100;
//		if (stop == true) {
//			if (milis > start_time) stop = false, milis = 0;
//		}
//		else {
//			if (milis > end_time) stop = true, milis = 0;
//		}
//	}
//	
//
//};