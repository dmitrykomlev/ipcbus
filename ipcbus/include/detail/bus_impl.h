#ifndef _BUS_IMPL_H_
#define _BUS_IMPL_H_

#include <string>
#include <future>
#include <boost/asio.hpp>
class BusImpl
{
public:
   explicit BusImpl(std::string const& bus_name);
   ~BusImpl(){};

   void power_on();
   void power_off();

private:
    void accept();

    std::string _name;
    boost::asio::io_service _service;
    std::future<int> _run_result;
    boost::asio::ip::tcp::acceptor _acceptor;
};
#endif
