#include "detail/bus_device.h"
using namespace boost::asio;
BusDevice::BusDevice(boost::asio::io_service& service) : 
_socket(service)
{
}

BusDevice::BusDevice(BusDevice&& other) : 
_socket(std::move(other._socket))
{
}

BusDevice& BusDevice::operator=(BusDevice&& rhs)
{
    _socket = std::move(rhs._socket);
    return *this;
}

ip::tcp::socket& BusDevice::socket()
{
    return _socket;
}
