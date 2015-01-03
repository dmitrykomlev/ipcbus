#include <future>
#include <iostream>
#include "detail/bus_impl.h"
#include "detail/bus_device.h"

#define START_PORT 8899

using namespace boost::asio;
using namespace boost::asio::ip;
BusImpl::BusImpl(std::string const& bus_name): _name(bus_name),
_acceptor(_service)
{
}

void BusImpl::power_on()
{
    _run_result = std::async(std::launch::async, [this]()
    {
        try
        {          
            auto acceptor = tcp::acceptor(_service,
		              tcp::endpoint(tcp::v4(), 
                              START_PORT));
            accept();
            std::cout << "begin running service" << std::endl;
            _service.run();
            std::cout << "end running service. finishing..." << std::endl;
            return 0;
        }
        catch(std::exception& e)
        {
                std::cerr << "error while running service" << e.what() << std::endl;
                return 1;
        }
    });
}

void BusImpl::power_off()
{
    std::cout  << "stopping bus..." << std::endl;
    _service.stop();
    auto result = _run_result.get();
    std::cout << "bus stopped. bus running result is " <<result << std::endl;
}

void BusImpl::accept()
{
    std::shared_ptr<BusDevice> device_ptr = std::make_shared<BusDevice>(_service);
    auto accept_handler = [device_ptr, this](boost::system::error_code ec)
    {
        if(ec != 0)
        {
            std::cerr << ec << std::endl;
        }
        
        device_ptr->socket();
        accept();
    };
    _acceptor.async_accept(device_ptr->socket(), accept_handler); 
}

