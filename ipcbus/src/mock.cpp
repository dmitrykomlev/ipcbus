#include <iostream>
#include "mock.h"
#include <boost/filesystem.hpp>
int mock()
{
	boost::filesystem::path curr;
	std::cout << "this is mock from dbus lib" <<  std::endl;
	return 0;

}