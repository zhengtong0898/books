#include <iostream>
#include <memory>

/******************************************************
**                                                   **
**                       运输                        **
**                                                   **
*******************************************************/
class Transport {
public:
    virtual ~Transport() {};
    virtual void deliver() = 0;
};


class Truck: public Transport {
public:
    void deliver() {
        std::cout << "Truck: deliver." << std::endl;
    }
};


class Ship: public Transport {
public:
    void deliver() {
        std::cout << "Ship: deliver." << std::endl;
    }
};


/******************************************************
**                                                   **
**                       物流                        **
**                                                   **
*******************************************************/
class Logistics {
public:
    void planDelivery() {
        std::shared_ptr<Transport> transport = this->createTransport();
        transport->deliver();
    }
    virtual std::shared_ptr<Transport> createTransport() = 0;
};


class RoadLogistics: public Logistics {
public:
    std::shared_ptr<Transport> createTransport() {
        return std::shared_ptr<Transport>(new Truck);
    }
};


class SeaLogistics : public Logistics {
public:
    std::shared_ptr<Transport> createTransport() {
        return std::shared_ptr<Transport>(new Ship());
    }
};


int main(void) {
    Logistics * logistics = new RoadLogistics;
    logistics->planDelivery();
    std::cout << "page074" << std::endl;

    return 0;
}