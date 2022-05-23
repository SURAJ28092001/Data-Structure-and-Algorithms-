'''Implement all the functions of a dictionary (ADT) using hashing and handle collisions using chaining with / without replacement. Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique Standard Operations: Insert(key, value), Find(key), Delete(key)'''
class Hash_Table:
    __li = []
    __li = [[] for i in range(10)]
    def insert(self,key,value):
        print("----------------------------------------------------------")
        for i in self.__li[key]:
            if i[0] == value[0]:
                print("The roll number already exists")
                return
        self.__li[key].append(value)
        print("The data is inserted.")
        print("----------------------------------------------------------")

    def find(self,key,value):
        print("----------------------------------------------------------")
        if self.__li[key] == []:
            print("No such record found.")
            return
        else:
            for i in range(len(self.__li[key])):
                if value == self.__li[key][i][0]:
                    print("Found the record with the following details : ")
                    print("{0:^50}||{1:^50}".format("Roll Number","Name"))
                    print("{0:^50}||{1:^50}".format(value,self.__li[key][i][1]))
                    return
            else:
                print("No such record found.")
        print("----------------------------------------------------------")
    def delete(self,key,value):
        print("----------------------------------------------------------")
        if self.__li[key] == []:
            print("No such record found.")
            return
        else:
            for i in range(len(self.__li[key])):
                if value == self.__li[key][i][0]:
                    self.__li[key].pop(i)
                    print("The record is deleted")
                    return
            else:
                print("No such record found.")
        print("----------------------------------------------------------")
            
    def display(self):
        print("----------------------------------------------------------")
        print("{0:^50}||{1:^50}".format("Roll Number","Name"))
        for i in self.__li:
            for j in i:
                
                print("{0:^50}||{1:^50}".format(j[0],j[1]))
        print("----------------------------------------------------------")
            
            
def main():
    ht = Hash_Table()
    while True:
        print("----------------------------------------------------------")
        print("Press 1 to insert data : ")
        print("Press 2 to display data : ")
        print("Press 3 to search a data : ")
        print("Press 4 to delete a  data : ")
        print("Press 0 to Exit ")
        print("----------------------------------------------------------")
        c = int(input())
        if c == 1:
            roll = int(input("Enter the roll number : "))
            name = input("Enter the name of the Student : ")
            key = roll % 10
            ht.insert(key,[roll,name])
        elif c == 2:
            ht.display()
        elif c == 3:
            roll = int(input("Enter the roll number to be searched : "))
            key = roll % 10
            ht.find(key,roll)
        elif c == 4:
            roll = int(input("Enter the roll number to be deleted : "))
            key = roll % 10
            ht.delete(key,roll)
        elif c == 0:
            print("Exited")
            break
        else:
            print("Invalid Input !!! Please try again")
        
    
if __name__ == "__main__":
    main()
