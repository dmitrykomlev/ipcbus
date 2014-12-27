#include "ipc.h"
#include "detail/bus_impl.h"
Bus create_bus(std::string const& bus_name)
{
    return  Bus(std::unique_ptr<BusImpl>(new BusImpl(bus_name)));
}
