// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
	class Timer
	{
	public:
		Timer();
		double GetMilisecondsElapsed();
		void Restart();
		bool Stop();
		bool Start();
	
	private:
		bool isRunning_ = false;
		std::chrono::time_point<std::chrono::steady_clock> start_;
		std::chrono::time_point<std::chrono::steady_clock> stop_;
	};
}