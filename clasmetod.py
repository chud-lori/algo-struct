class MyClass:
    """
    A simple class to demonstrate counting object creation using a class method.
    """
    object_count = 0  # Class variable to keep track of the number of objects

    def __init__(self):
        """
        Constructor for the MyClass. Increments the object_count.
        """
        MyClass.object_count += 1

    @classmethod
    def get_object_count(cls):
        """
        Class method to return the total number of objects created.
        """
        return cls.object_count

# Creating instances of MyClass
obj1 = MyClass()
obj2 = MyClass()
obj3 = MyClass()

# Accessing the object count using the class method
count = MyClass.get_object_count()
print(f"Total number of MyClass objects created: {count}")

# You can also access it through an instance, but it's generally better to use the class itself
count_via_instance = obj1.get_object_count()
print(f"Total number of MyClass objects created (via instance): {count_via_instance}")

print(f"HEHEHEHEH: {MyClass.object_count}")

