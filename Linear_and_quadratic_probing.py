def linear_probing(db,j,li,n):
    i = 0
    while True:
        index = (j+i)%n
        if db[index] == -1:
            db[index] = li
            return db
        i = i + 1
                
            
def quad_probing(db,j,li,n):
    i = 0
    while True:
        index = (j+(i*i))%n
        if db[index] != -1:
            i = i + 1
        else:
            db[index] = li
            return db
        if i == n**2:
            break;
    db = linear_probing(db,j,li,n)
    return db
def linear_searching(db,db1,name):
    c = 0
    flag = False
    print("---------------------------Using linear probing------------------------------------")
    for i in db:
        if i != -1:
            c += 1
            if i[0].upper() == name.upper():
                print("The name ,",name," is found with the phone number as ",i[1])
                print("The number of comparisons required were : ",c)
                flag = True
                break
    if not(flag):
        print("No such record found")
        flag = False
    c = 0
    print("---------------------------Using quadratic probing------------------------------------")
    for i in db1:
        if i != -1:
            c += 1
            if i[0].upper() == name.upper():
                print("The name ,",name," is found with the phone number as ",i[1])
                print("The number of comparisons required were : ",c)
                flag = True
                break
    if not(flag):
        print("No such record found")
    
def display(directory,directory1):
    print("---------------------------Using linear probing------------------------------------")
    print("{0:^50}||{1:^50}".format("Name","Telephone Number"))
    for i in directory:
        if(i != -1):
            print("{0:^50}||{1:^50}".format(i[0],i[1]))
    print("---------------------------Using quadratic probing------------------------------------")
    print("{0:^50}||{1:^50}".format("Name","Telephone Number"))
    for i in directory1:
        if i != -1:
            print("{0:^50}||{1:^50}".format(i[0],i[1]))
def delete_record(db,db1,name):
    c = 0
    flag = False
    print("---------------------------Using linear probing------------------------------------")
    for i in db:
        if i != -1:
            c += 1
            if i[0].upper() == name.upper():
                index = db.index(i)
                db[index] = -1
                print("The record is deleted")
                print("The number of comparisons required were : ",c)
                flag = True
                break
    if not(flag):
        print("No such record found")
        flag = False
    c = 0
    print("---------------------------Using quadratic probing------------------------------------")
    for i in db1:
        if i != -1:
            c += 1
            if i[0].upper() == name.upper():
                index = db1.index(i)
                db1[index] = -1
                print("The record is deleted")
                print("The number of comparisons required were : ",c)
                
                flag = True
                break
    if not(flag):
        print("No such record found")
def main():
    n = 10
    li = [-1 for i in range(10)]
    directory = [-1 for i in range(10)]
    directory1 = [-1 for i in range(10)]
    
    while True:
        print("-------------------------------------------------------------")
        print("Press 1 to create a new record")
        print("Press 2 to display the whole directory")
        print("Press 3 to search a record")
        print("Press 4 to delete a record")
        print("Press 0 to exit")
        print("-------------------------------------------------------------")
        ch = int(input())
        if ch == 1:
            name = input("Enter the name : ")
            tele = int(input("Enter the telephone number : "))
            li = [name,tele]
            j = tele % n
            if -1 not in directory and -1 not in directory1:
                print("The directory is full")
            else:
                directory = linear_probing(directory,j,li,n)
                directory1 = quad_probing(directory1,j,li,n)
        elif ch == 2:
            if all(p == -1 for p in directory) and all(q == -1 for q in directory1):
                print("The directory is empty")
            else:
                display(directory,directory1)
                
        elif ch == 3:
            if all(p == -1 for p in directory) and all(q == -1 for q in directory1):
                print("The directory is empty")
            else:
                name = input("Enter the name to be searched : ")
                linear_searching(directory,directory1,name)
        elif ch == 4:
            if all(p == -1 for p in directory) and all(q == -1 for q in directory1):
                print("The directory is empty")
            else:
                name = input("Enter the name to be deleted : ")
                delete_record(directory,directory1,name)
        elif ch == 0:
            print("Exited")
            break
        else:
            print("Invalid Choice!!! Please try again")
            
            
            
if __name__ == "__main__":
    main()
