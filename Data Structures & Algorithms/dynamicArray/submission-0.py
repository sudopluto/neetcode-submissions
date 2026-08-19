class DynamicArray:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.buff = [0] * capacity


    def get(self, i: int) -> int:
        if i >= 0 and i < self.size:
            return self.buff[i]
        else:
            raise Exception("Tried to access invalid index: " + str(i))


    def set(self, i: int, n: int) -> None:
        if i >= 0 and i < self.size:
            self.buff[i] = n
        else:
            raise Exception("Tried to access invalid index: " + str(i))


    def pushback(self, n: int) -> None:
        if self.size == self.capacity:
            self.resize()

        self.buff[self.size] = n
        self.size += 1


    def popback(self) -> int:
        if self.size == 0:
            raise Exception("Can't pop element from empty list")
        else:
            ret = self.buff[self.size - 1]
            self.size -= 1
            return ret


    def resize(self) -> None:
        self.capacity *= 2
        new_buff = [0] * self.capacity
        for i in range(self.size):
            new_buff[i] = self.buff[i]
        self.buff = new_buff


    def getSize(self) -> int:
        return self.size


    def getCapacity(self) -> int:
        return self.capacity