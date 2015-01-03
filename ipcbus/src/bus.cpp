#include "detail/bus_impl.h"
#include "bus.h"

Bus::Bus(std::unique_ptr<BusImpl> pimpl) : _pimpl(std::move(pimpl))
{
}

Bus::Bus(Bus&& other): _pimpl(std::move(other._pimpl))
{
}

Bus& Bus::operator=(Bus&& rhs)
{
   _pimpl = std::move(rhs._pimpl);
   return *this;
}

Bus::~Bus()
{
}

void Bus::power_on()
{
    _pimpl->power_on();
}

void Bus::power_off()
{
   _pimpl->power_off();
}


