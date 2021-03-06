# py3.8


###########################################################
#                                                         #
#                        运输                             #
#                                                         #
###########################################################
class Transport(object):

    def deliver(self):
        raise NotImplementedError


class Truck(Transport):

    def deliver(self):
        print("Truck: deliver")


class Ship(Transport):

    def deliver(self):
        print("Ship: deliver")


###########################################################
#                                                         #
#                        物流                             #
#                                                         #
###########################################################
class Logistics(object):

    def planDelivery(self):
        transport = self.createTransport()
        transport.deliver()

    def createTransport(self) -> Transport:
        raise NotImplementedError


class RoadLogistics(Logistics):

    def createTransport(self) -> Transport:
        return Truck()


class SeaLogistics(Logistics):

    def createTransport(self) -> Transport:
        return Ship()


if __name__ == '__main__':
    road_logistics = RoadLogistics()
    road_logistics.planDelivery()
    print("page074")
