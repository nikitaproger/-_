from abc import ABC, abstractmethod
class TreeInterface(ABC):
    @abstractmethod
    def contains(self, x):
        pass

    @abstractmethod
    def validate(self):
        pass

    @abstractmethod
    def insert(self, x):
        pass
