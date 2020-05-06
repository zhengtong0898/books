"""
Chain of responsibility pattern example.
"""
from abc import ABCMeta, abstractmethod
from enum import Enum, auto


class LogLevel(Enum):
    """ Log Levels Enum."""
    NONE = auto()
    INFO = auto()
    DEBUG = auto()
    WARNING = auto()
    ERROR = auto()
    FUNCTIONAL_MESSAGE = auto()
    FUNCTIONAL_ERROR = auto()
    ALL = auto()


class Logger(object):
    """Abstract handler in chain of responsibility pattern."""
    __metaclass__ = ABCMeta

    next = None

    def __init__(self, levels) -> None:
        """Initialize new logger.

        Arguments:
            levels (list[str]): List of log levels.
        """
        self.log_levels = []

        for level in levels:
            self.log_levels.append(level)

    def set_next(self, next_logger: Logger):
        """Set snext responsible logger in the chain.

        Arguments:
            next_logger (Logger): Next responsible logger.
        Returns: Logger: Next responsible logger.
        """
        self.next = next_logger
        return self.next

    def message(self, msg: str, severity: LogLevel) -> None:
        """Message writer handler.

        Arguments:
            msg (str): Message string.
            severity (LogLevel): Severity of message as log level enum.
        """
        if LogLevel.ALL in self.log_levels or severity in self.log_levels:
            self.write_message(msg)

        if self.next is not None:
            self.next.message(msg, severity)

    @abstractmethod
    def write_message(self, msg: str) -> None:
        """Abstract method to write a message.

        Arguments:
            msg (str): Message string.
        Raises: NotImplementedError
        """
        raise NotImplementedError("You should implement this method.")


class ConsoleLogger(Logger):
    def write_message(self, msg: str) -> None:
        """Overrides parent's abstract method to write to console.

        Arguments:
            msg (str): Message string.
        """
        print("Writing to console:", msg)


class EmailLogger(Logger):
    """Overrides parent's abstract method to send an email.

    Arguments:
        msg (str): Message string.
    """
    def write_message(self, msg: str) -> None:
        print(f"Sending via email: {msg}")


class FileLogger(Logger):
    """Overrides parent's abstract method to write a file.

    Arguments:
        msg (str): Message string.
    """
    def write_message(self, msg: str) -> None:
        print(f"Writing to log file: {msg}")


def main():
    """Building the chain of responsibility."""
    logger = ConsoleLogger([LogLevel.ALL])
    email_logger = logger.set_next(
        EmailLogger([LogLevel.FUNCTIONAL_MESSAGE, LogLevel.FUNCTIONAL_ERROR])
    )
    # As we don't need to use file logger instance anywhere later
    # We will not set any value for it.
    email_logger.set_next(
        FileLogger([LogLevel.WARNING, LogLevel.ERROR])
    )

    # ConsoleLogger will handle this part of code since the message
    # has a log level of all
    logger.message("Entering function ProcessOrder().", LogLevel.DEBUG)
    logger.message("Order record retrieved.", LogLevel.INFO)

    # ConsoleLogger and FileLogger will handle this part since file logger
    # implements WARNING and ERROR
    logger.message(
        "Customer Address details missing in Branch DataBase.",
        LogLevel.WARNING
    )
    logger.message(
        "Customer Address details missing in Organization DataBase.",
        LogLevel.ERROR
    )

    # ConsoleLogger and EmailLogger will handle this part as they implement
    # functional error
    logger.message(
        "Unable to Process Order ORD1 Dated D1 for customer C1.",
        LogLevel.FUNCTIONAL_ERROR
    )
    logger.message("OrderDispatched.", LogLevel.FUNCTIONAL_MESSAGE)


if __name__ == "__main__":
    main()