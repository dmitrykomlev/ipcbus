#include <string>
class BusImpl
{
public:
    BusImpl(std::string const& bus_name):_name(bus_name){}

private:
    std::string _name;
};
