class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LL:
    def __init__(self):
        self.head = None
        self.size = 0

    def insertAtBeginning(self, data):
        newnode = Node(data)
        newnode.next = self.head
        self.head = newnode
        self.size += 1
        self.display()

    def insertAtEnd(self, data):
        newnode = Node(data)
        if self.head is None:
            self.head = newnode
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = newnode
        self.size += 1
        self.display()

    def insertAtIndex(self, data, index):
        if index == 0:
            self.insertAtBeginning(data)
            return
        if index == self.size:
            self.insertAtEnd(data)
            return
        newnode = Node(data)
        temp = self.head
        for i in range(1, index - 1):
            temp = temp.next
        newnode.next = temp.next
        temp.next = newnode
        self.size += 1
        self.display()

    def deleteFirst(self):
        if self.head is None:
            print("List already empty")
            return
        current = self.head
        self.head = self.head.next
        self.size -= 1
        print("Value Removed: ", current.data)
        return current.data

    def deleteLast(self):
        if self.size <= 1:
            return self.deleteFirst()
        secondLast = self.get(self.size - 2)
        val = self.get(self.size - 1).data
        secondLast.next = None
        self.size -= 1
        print("Value Removed: ", val)
        self.display()

    def deleteAtIndex(self, index):
        if index == 0:
            return self.deleteFirst()
        if index == self.size:
            return self.deleteLast()
        prev = self.get(index - 1)
        value = prev.next.data
        prev.next = prev.next.next
        self.size -= 1
        print("Value Removed: ", value)
        self.display()

    def get(self, index):
        newnode = self.head
        for i in range(index):
            newnode = newnode.next
        return newnode

    def display(self):
        if self.head is None:
            print("List is empty")
            print("The size is :", self.size)
            return
        current = self.head
        while current:
            print(current.data, end="->")
            current = current.next
        print("END")
        print("The size is :", self.size)


newLL = LL()
newLL.insertAtBeginning(10)
newLL.insertAtEnd(13)
newLL.insertAtEnd(12)
newLL.insertAtBeginning(3)
newLL.deleteFirst()
print("Value at index 2 is:", newLL.get(2).data)
newLL.insertAtIndex(31, 4)
newLL.insertAtEnd(43)
newLL.deleteLast()
newLL.deleteLast()
newLL.insertAtBeginning(89)
newLL.insertAtBeginning(34)
newLL.deleteAtIndex(3)
newLL.insertAtBeginning(45)
newLL.deleteAtIndex(1)
newLL.insertAtBeginning(67)
print("Final LL: ")
newLL.display()
