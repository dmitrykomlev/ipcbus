#ifndef _BUS_DEVICE_H_
#define _BUS_DEVICE_H_

#include <boost/asio.hpp>

class BusDevice
{
public:
    BusDevice(boost::asio::io_service& service);
    BusDevice(BusDevice const& other) = delete;
    BusDevice& operator=(BusDevice const& rhs) = delete;

    BusDevice(BusDevice&& other);
    BusDevice& operator=(BusDevice&& rhs);
    
    boost::asio::ip::tcp::socket& socket();
private:
   boost::asio::ip::tcp::socket _socket;
};
#endif
