#include <memory>
class BusImpl;
class Bus 
{
public:
    explicit Bus(std::unique_ptr<BusImpl> pimpl);
    Bus(Bus const& other) = delete;
    Bus(Bus&& other);
    Bus& operator=(Bus const& rhs) = delete;
    Bus& operator=(Bus&& rhs);
    ~Bus();
    
    void power_on();
    void power_off();
private:
    std::unique_ptr<BusImpl> _pimpl;
};
