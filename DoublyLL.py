
#                           Doubly Linked List

###################################################################################
class Node:
    def __init__(self,no):
        self.data = no
        self.next = None
        self.prev = None

###################################################################################

class DoublyLL:
    def __init__(self):
        self.first = None
        self.iCount = 0

###################################################################################

    def InsertFirst(self,No):
        newn = Node(No)
        if(self.first == None):
            self.first = newn
        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.iCount  = self.iCount + 1

###################################################################################
    def InsertLast(self,No):
        newn = Node(No)
        if(self.first == None):
            self.first = newn
        else:
            temp = self.first
            while(temp.next != None):
                temp = temp.next

            temp.next = newn
            newn.prev =  temp
    
        self.iCount = self.iCount + 1

###################################################################################
    def DeleteFirst(self):
        if(self.first == None):
            return
        elif(self.first.next == None):
            del self.first
            self.first = None
        else:
            temp = self. first
            self.first = self.first.next
            del temp

        self.iCount = self.iCount - 1

###################################################################################
    def DeleteLast(self):
        if(self.first == None):
            return

        elif(self.first.next == None):
            del self.first
            self.first = None

        else:
            temp = self. first
            while(temp.next == None):
                temp = temp.next
            temp.next.prev = None
            del temp

        self.iCount = self.iCount - 1

######################################################################  
    def InsertAtPos(self,No,pos):
        if(pos < 1 or pos > self.iCount+1):
            print("Invalid Position")
            return

        if(pos == 1):
            self.InsertFirst(No)

        elif(pos == self.iCount+1):
            self.InsertLast(No)

        else:
            newn = Node(No)
            temp = self.first

            for i in range(1,pos-1,1):
                temp = temp.next

            newn.next = temp.next
            temp.next.prev = newn
            temp.next = newn
            newn.prev = temp

        self.iCount = self.iCount + 1


######################################################################  
    def DeleteAtPos(self,pos):
        if((pos < 1) or (pos > self.iCount)):
            print("Invalid Position")
            return

        if(pos == 1):
            self.DeleteFirst()

        elif(pos == iCount):
            self.DeleteLast()

        else:
            temp = self.first

            target = self.first

            for i in range(1,pos-1,1):
                temp = temp.next

            target = temp.next
            temp.next = target.next
            target.next.prev = temp
            del target

        self.iCount = self.iCount - 1

###################################################################################
    def Display(self):
        temp = self.first

        while(temp != None):
            print(f"| {temp.data} | ->",end="")
            temp = temp.next
        print("None")


###########################################################################

    def Count(self):
        return self.iCount

###################################################################################
def main():
    print("Demonstration of Doubly Linked List")
    dobj = DoublyLL()
    dobj.InsertFirst(51)
    dobj.InsertFirst(21)
    dobj.InsertFirst(11)

    dobj.InsertLast(101)
    dobj.InsertLast(111)
    dobj.InsertLast(21)
    
    dobj.Display()
    iRet = dobj.Count()
    print(f"Number of Node are:{iRet}")

    dobj.InsertAtPos(101,4)
    dobj.Display()


###################################################################################
#               Starter
###################################################################################
if __name__ == "__main__":
    main()