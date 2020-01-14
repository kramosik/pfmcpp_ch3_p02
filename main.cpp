/*
 Chapter 3 Part 2 - Make a new Repl.it
 Pointers

 Task: replace all of the <place holder> with proper names and types that will
 make this program compile and run.

 steps:

 0) press the Run button and work your way through all of the error messages.

 1) finish implementing the constructor for T. the constructor parameters need
 to initialize 2) and 3)

 2) provide a member variable in T of a type of your choosing that works with
 the compare function below T note the name of the variable used in the compare
 function

 3) provide a member variable of type std::string in T that works with the
 *first* cout statement in main(). note the name of the variable used in the
 *first* cout statement in main()

 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if
 statements. see 8) for a hint about what type to use.

 6) finish instantiating the two T instances being declared in main(), based on
 the constructor you finished implementing in T

 7) Declare 'f' with the proper type so the call to f.compare works

 8) call f.compare() with the correct arguments, based on 2) and 5)

 9) correct the cout that uses bigger's member variable with some safe pointer
 usage. the possible return values of the compare() function should give you a
 hint.

 10) complete the implementation for the static function in <structName2>

 11) call the <structName2> static function correctly in main()

 12) replicate the functionality of <structName2>'s static function by
 implementing a member function in U that does the same thing.

 After you finish, click the [run] button.  Clear up any errors or warnings as
 best you can.

 Commit your changes by clicking on the Source Control panel on the left,
 entering a message, and click [Commit and push].

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* name) : m_value(v), m_name(name) {} // 1
    // 2
    int m_value;
    // 3
    std::string m_name;
};

struct Comparator // 4
{
    T* compare(T* a, T* b) // 5
    {
        if (!a || !b)
            return nullptr;

        if (a->m_value < b->m_value)
            return a;
        if (a->m_value > b->m_value)
            return b;
        return nullptr;
    }
};

struct U
{
    float val1 {0}, val2 {0};
    float updateValue(const float* updatedValue) // 12
    {
        if (!updatedValue)
        {
            return 0.0f;
        }
        std::cout << "U's val1 value: " << val1 << std::endl;
        val1 = *updatedValue;
        std::cout << "U's val1 updated value: " << val1 << std::endl;
        while (std::abs(val2 - val1) > 0.001f)
        {
            /*
             write something that makes the distance between val2 and
             val1 get smaller
             */
            val2 -= (val2 - val1) / 2;
        }
        std::cout << "U's val2 updated value: " << val2 << std::endl;
        return val2 * val1;
    }
};

struct Updater
{
    static float updateValue(U* that, const float* updatedValue) // 10
    {
        if (!that && !updatedValue)
        {
            return 0.0f;
        }

        std::cout << "U's val1 value: " << that->val1 << std::endl;
        that->val1 = *updatedValue;
        std::cout << "U's val1 updated value: " << that->val1 << std::endl;
        while (std::abs(that->val2 - that->val1) > 0.001f)
        {
            /*
             write something that makes the distance between that->val2 and
             that->val1 get smaller
             */
            that->val2 -= (that->val2 - that->val1) / 2;
        }
        std::cout << "U's val2 updated value: " << that->val2 << std::endl;
        return that->val2 * that->val1;
    }
};

int main()
{
    T t1(3, "3"); // 6
    T t2(4, "4"); // 6

    Comparator f;                        // 7
    auto* smaller = f.compare(&t1, &t2); // 8
    if (smaller)
    {
        std::cout << "the smaller one is " << smaller->m_name << std::endl; // 9
    }

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: "
              << Updater::updateValue(&u1, &updatedValue) << std::endl; // 11

    U u2;
    std::cout << "[member func] u2's multiplied values: "
              << u2.updateValue(&updatedValue) << std::endl;
}
