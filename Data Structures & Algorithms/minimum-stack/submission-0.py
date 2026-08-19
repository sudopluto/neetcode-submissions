class MinStack:
    def __init__(self):
        self.main_stack: list[int] = []
        self.min_stack: list[int] = []

    def push(self, val: int) -> None:
        self.main_stack.append(val)
        if len(self.min_stack) == 0:
            self.min_stack.append(val)
        else:
            self.min_stack.append(min(val, self.min_stack[-1]))

    def pop(self) -> None:
        _ = self.main_stack.pop()
        _ = self.min_stack.pop()

    def top(self) -> int:
        return self.main_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]