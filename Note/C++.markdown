#### 1.5 头文件

 **Definition of  a class**

1. separated .h and .cpp files are used to define one class

2. class declaration and prototypes in that class are in the header file (.h)

3. All the bodies of these functions are in the source of file (.cpp)

**The header files**

1. If a funtion is declared in a header file, you must include the header file everywhere the function is used and where the function is defined.
2. If a class if declared in a header file, you must include the header file everywhere the class if used and where class member functions are defined.

**Declarations vs Definitions** 

1. A.cpp file is a compile unit 

2. Only declarations are allowed to be in .h (otherwise there will be an error when you union two .cpp that include the same .h)

   What exactly declarations are?  

   1. extern variables 
   2. function prototypes 
   3. class/struct declaration

**#include** 

#include is to insert the included file into the .cpp file at where the #include statement is.

1. #include "xx.h" first search in the current directory, then the directories declared somewhere

2. #include <xx.h> search in the specified directories 

3. #include <xx> is the same as #include <xx.h>

**Tips for header** 

1. One class declaration per header file

2. Associated with one source file in the same prefix of file name

3. The contents of a header file is surrounded with #ifndef #define #endif (otherwise it may be defined repeatly)

#### 1.6 时钟的例子

We need to create 2 class. One class is named ClockDisplay and the other is named NumberDisplay.The ClockDisplay includes 2 NumberDisplay to represent minute and hour.

The whole project has 5 file.Each class have 2 file and there is a  main.cpp.

```c++
class NumberDisplay {
    int limit;
    int value;
    //constructor and methods omitted.
}
```



```c++
class ClockDisplay {
    NumberDisplay minute;
    NumberDisplay hour;
    //constructor and methods omiited 
}
```

#### 1.7 成员变量

**Fields, parameters,local variables**

parameters is mostly the same as local variables.

**this:the hidden parameter** 

**this** is a hidden parameter for all member functions, with the type of the class.

**this** is a natural local variable of all class member functions that you can not define, but can use it directly.

the functions are belong to one class,but the fields are belong to one object.

#### 1.8 构造与析构

**Guaranteed initialization with the constructor**

- If a class has a constructor , the compiler automatically calls that constructor at the point an object is created, before client programmers get their hands on the object.

- The name of the constructor is the same as the class

- The constructor can have arguments to allow you to specify how an object is created, give it initialization values, and so on.

**The destructor**

- In C++, clean up is as important as initalization  and is therefore guaranteed with the destructor.

- The destructor is named after the name of the class with a leading tilde(~). The destructor never has any arguments.

  **When is a destructor called?**

  - The destructor is called automatically by the compiler when the object goes out of the scope.
  
  - The only evidence for a destructor call is the closing brace of the scope that surrounds the object.
  
#### 1.9 对象初始化

**Storage allocation** 

- The compiler allocates all the storage for a scope at the opening brace of that scope.

- The constructor call doesn`t happen until the consequence point where the object is defined.

We must pay attention on the default constructor.

#### 1.10 Dynamic memory allocation 

**new and delete**

- new is the way to allocate memory as a program runs.Pointers become the only access to that memory.

- delete enables you to return memory to the memory pool when you are finished with it.

  ````c++
  int * psome = new int[10];
  //The new operator returns the address of the first element of the block.
  delete [] psome;
  //The presence of the brackets tells the program that it shoule free the whole array, not just the element.
  ````

**Tips for new and delete**

- Don‘t use **delete** to free memory that **new** didn’t allocate.

- Don't use **delete** to free the same block of memory twice in succession.

- Use **delete []** if you used  new [] to allocate an array.

- Use **delete**(no brackets) if you usel  to allocate a single entity.

- It's safe to apply **delete** to the null pointer(nothings happens).

**somethings about class**

When you use new to create a object, the constructor of the class will be called as the memory of the object allocated.

And if you use delete to free a object,program will call the destructor first and then free the memory.

#### 1.11 访问限制

**C++ access control** 

- The members of a class can be cataloged, marked as 

  **public, private, protected** 

**private**

The **private** keyword means that no one can access that member except inside function members of that type.

**Friends**

- to explicitly grant access to a function that isn't a member of the structure.
- The class itself controls which code has access to its members.
- Can declare a global function as a friend, as well as a member function of another class, or even an entire class, as a friend.

**class vs struct** 

- class defaults to private. 
- struct defaults to public.


#### 1.12 初始化列表

**Initializer list**

example :

```c++
class Point {
    private:
    	const float x, y;
    Point(float xa=0.0, float ya=0.0) : y(ya), x(xa) {}
};
```

It is different with initialization in the { ...}.

The Initializer list is worked before constructor. 

**Initialization vs assignment**

```c++
Student:: Student (string s): name(s) {}
```

initialization list 

before constructor

```c++
Student:: Student (string s) {name=s;}
```

assignment  inside constructor

not a initialization 

string must have a default constructor

#### 1.13 对象组合

**Composition**

- construct new object with existing objects

- It is the relationship of "has-a"

Ways of inclusion 

- Fully , the other object is inside this one.

- By reference , is't inside this object, but we can visit it.

```c++
class Person {...};
class Currency {...};
class SavingsAccount {
public : 
    SavingsAccount (const char *name, const char *address, int cents);
    ~SacingsAccount ();
    void print();
private : 
    Person m_saver;
    Currency m_balance;//the 2 objects is inside the SavingsAccount
}


SavingsAccount :: SavingsAccount (const char *name, const char *address, int cents) : m_saver(name ,address), m_balance(0, cents) {}
//use initializer list 
//if you don't have this , it will call default constructor
void SavingsAccount :: print() {
    m_saver.print();
    m_balance.print();
}
```

#### 1.14 继承 

**Reusing the interface**

Inheritance is to take the existing class, clone it, and then take additions and modifications to the clone.

**Inheritance**

The ability to define the behavior or implementation of one class as a superset of another class.

![](Picture/1-14-1.PNG)

**protected functions and variables** 

only child class and itself can access.

![](Picture/1-14-2.PNG)

#### 1.16 子类父类关系

