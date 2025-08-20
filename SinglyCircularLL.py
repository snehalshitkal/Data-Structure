#           Singly Circular Linked List

#######################################################################################
class Node:
    def __init__(self,no):
        self.data = no
        self.next = None

#######################################################################################

class SinglyCircularLL:
    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

#######################################################################################

    def InsertFirst(self,no):
        newn = Node(no)
        if((self.first == None) & (self.last == None)):
            self.first = newn
            self.last = newn

            self.last.next = newn

        else:
            newn.next = self.first
            self.first = newn
            self.last.next = newn

        self.iCount  = self.iCount + 1

#######################################################################################

    def InsertLast(self,no):
        newn = Node(no)
        if((self.first == None) & (self.last == None)):
            self.first = newn
            self.last = newn

            self.last.next = newn

        else:
            self.last.next = newn
            self.last = newn
            newn.next = self.first

        self.iCount  = self.iCount + 1 

#######################################################################################

    def Display(self):
        temp  = self.first

        while True:
            print(f"| {temp.data} | -> ", end="")
            temp = temp.next
            if temp == self.first:
                break
        print()
       
#######################################################################################

    def Count(self):
        return self.iCount

#######################################################################################
    def DeleteFirst(self):
        if(self.first == None & self.last == None):
            return

        elif(self.first == self.last):
            del self.first
            self.first = None
            self.last = None

        else:
            self.first = self.first.next
            del self.last.next
            self.last.next = self.first 

        self.iCount  = self.iCount - 1

#######################################################################################
    def DeleteLast(self):
        if(self.first == None & self.last == None):
            return

        elif(self.first == self.last):
            del self.first
            self.first = None
            self.last = None

        else:
            temp = self.first

            while(temp.next != self.last):
                temp = temp.next

            del self.last
            self.last = temp
            self.last.next = self.first 

        self.iCount  = self.iCount - 1

#######################################################################################
    def InsertAtPos(self,no,pos):
        if(pos < 1 & pos > self.iCount + 1):
            print("Invalid position")
            return

        elif(pos == 1):
            return self.InsertFirst(no)

        elif(pos == self.iCount + 1):
            return self.InsertLast(no)
        
        else:
            newn = Node(no)
            temp = self.first

            for i in range(1,pos-1,1):
                temp = temp.next
            newn.next = temp.next
            temp.next = newn

        self.iCount  = self.iCount + 1
#######################################################################################
    def DeleteAtPos(self,pos):
        if(pos < 1 & pos > self.iCount):
            print("Invalid position")
            return

        elif(pos == 1):
            return self.DeleteFirst(no)

        elif(pos == self.iCount):
            return self.DeleteLast(no)
        
        else:
            temp = self.first
            for i in range(1,pos-1,1):
                temp = temp.next

            target = temp.next
            temp.next = target.next
            del target

        self.iCount  = self.iCount - 1
#######################################################################################
#starter
#######################################################################################
def main():
    print("Demonstration of Singly Circular Linear Linked List")

    sobj = SinglyCircularLL()

    sobj.InsertFirst(51)
    sobj.InsertFirst(21)
    sobj.InsertFirst(11)
  
    sobj.InsertLast(101)
    sobj.InsertLast(111)
    sobj.InsertLast(121)
  
    sobj.Display()

    iRet = sobj.Count()
    print(f"Number of nodes on Linked List are {iRet}")

    sobj.InsertAtPos(105,5)

    sobj.Display()

    iRet = sobj.Count()
    print(f"Number of nodes on Linked List are {iRet}")

    sobj.DeleteAtPos(5)
    sobj.Display()

    iRet = sobj.Count()
    print(f"Number of nodes on Linked List are {iRet}")

#######################################################################################
if __name__ == "__main__":
    main()