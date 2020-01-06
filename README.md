# Applications-of-Linked-List-Singly-Doubly-Linked-Lists-
I have implemented the applications of singly and doubly linked lists using Employee and Date classes. One of the most demanding and applicable applications that can be used insisde any firm or institute to keep the record of employee of a firm

Appropriate member function for all the user-defined classes.
Singly Linked list after five insertions;

Each emp is object of Employee class and holds its functionality.
Structure
The data items form a linear structure in which list data items follow one after the other, from the
beginning of the list to its end. The ordering of the data items is determined by when and where
each data item is inserted into the list and is not a function of the data contained in the list data
items. At any point in time, one data item in any nonempty list is marked using the list’s cursor.
You travel through the list using operations that change the position of the cursor.
Operations

##  List ( int ignored = 0 )
Requirements:
None
Results:
Constructor.
Creates an empty list.

## ~List ()
Requirements:
None
Results:
Destructor.
Deallocates (frees) the memory used to store a list.

## void insert ( const Employee &emp )
Requirements:
None.
Results:
If the list is not empty, then inserts emp at the end.

## Void remove (EmployeeID id)
Requirements:
List is not empty.
Results:
Removes the data item whose employee id matched the parameter id. If the id doesn’t exist display
a message “Record does not exist”

## voidUpdateSalary ( const int &salary, EmployeeID id)
Requirements:
List is not empty.
Results:
Locate the data item whose employee id matches the parameter id, then update the respective data
item salary member with the parameter salary.

## void UpdateBonus ( const int &bonus, EmployeeID id)
Requirements:
List is not empty.
Results:
Locate the data item whose employee id matches the parameter id, then update the respective data
item bonus member with the parameter bonus.

## void clear ()
Requirements:
None
Results:
Removes all the data items in a list.

## boolisEmpty ()
Requirements:
None
Results:
Returns true if a list is empty. Otherwise, returns false.

## void display ()
Requirements:
List is not empty.
Results:
Display the data items separated with two empty lines.

## void sort ()
Requirements:
List is not empty.
Results:
Display the sorted data items on the basis of the employee salary.

The code to sort the nodes on the basis of their data items. I.e. do not copy the data of
nodes to each other.
