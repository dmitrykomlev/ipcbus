#include <boost/test/unit_test.hpp>
#include "ipc.h"

BOOST_AUTO_TEST_CASE (construct_test)
{
    std::string first_bus_name = "first_bus";
    std::string second_bus_name = "second_bus";
    auto bus1 = create_bus(first_bus_name);    
    auto bus2 = create_bus(second_bus_name);    
} 
