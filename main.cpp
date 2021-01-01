#include <boost/lambda/lambda.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/use_future.hpp>
#include <boost/asio/write.hpp>
#include <iostream>
#include <boost/phoenix/operator.hpp>
#include <iterator>
#include <algorithm>
#include "base/Request.hpp"
#include "base/Config.hpp"
#include "Server.hpp"
#include <chrono>
#include <atomic>


void StartApp(){
	uint32_t port = 8080;
	Server svr;
	auto init_ret = svr.Init(port);
	
	if(init_ret != 0)
	{
		LOG("App init error with ret:{}", init_ret);
		return;
	}

	svr.Start();
}

int main(){
	InitLog();
	ConfigMgr::Instance()->InitConfigFile("test.config");
	LOG("Start the App");
	auto start = std::chrono::steady_clock::now();

	StartApp();

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::cout << "elapsed time: "<< elapsed_seconds.count() << "s\n";
	LOG("App closed");
	return 1;
}
