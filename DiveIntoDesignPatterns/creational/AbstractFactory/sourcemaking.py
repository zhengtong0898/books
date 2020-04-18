#py 3.8


class Widget(object):

    def draw(self):
        raise NotImplementedError


class LinuxButton(Widget):

    def draw(self):
        print("LinuxButton")


class LinuxMenu(Widget):

    def draw(self):
        print("LinuxMenu")


class WindowsButton(Widget):

    def draw(self):
        print("WindowsButton")


class WindowsMenu(Widget):

    def draw(self):
        print("WindowsMenu")


class Factory(object):

    def create_button(self):
        raise NotImplementedError

    def create_menu(self):
        raise NotImplementedError


class LinuxFactory(Factory):

    def create_button(self):
        return LinuxButton()

    def create_menu(self):
        return LinuxMenu()


class WindowsFactory(Factory):

    def create_button(self):
        return WindowsButton()

    def create_menu(self):
        return WindowsMenu()


class Client(object):

    def __init__(self, factory: Factory):
        self.factory = factory

    def display_window_one(self):
        factories = [self.factory.create_button(),
                     self.factory.create_menu()]
        factories[0].draw()
        factories[1].draw()

    def display_window_two(self):
        factories = [self.factory.create_menu(),
                     self.factory.create_button()]
        factories[0].draw()
        factories[1].draw()

    def draw(self):
        factory = self.factory.create_button()
        factory.draw()

        self.display_window_one()
        self.display_window_two()


def main(platform):
    if platform == "linux":
        factory = LinuxFactory()
    else:
        factory = WindowsFactory()

    client = Client(factory)
    client.draw()


if __name__ == '__main__':
    main("linux")
