/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References

 1) convert all of the pointer usage (except for 'const char*') to reference
types or const reference types ** WHERE POSSIBLE ** hint: There is no reference
equivalent to nullptr. So don't try to convert nullptr, if nullptr is being
returned anywhere

 2) After you finish, click the [run] button.  Clear up any errors or warnings
as best you can.

 Commit your changes by clicking on the Source Control panel on the left,
entering a message, and click [Commit and push].

 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* displayName) : value(v), name(displayName) {} // 1
    // 2
    int value;
    // 3
    std::string name;
};

struct Comparator // 4
{
    T* compare(T& a, T& b) // 5
    {
        if (a.value < b.value)
            return &a;
        if (a.value > b.value)
            return &b;
        return nullptr;
    }
};

struct U
{
    float val1 {0}, val2 {0};
    float updateValue(const float& updatedValue) // 12
    {
        std::cout << "U's val1 value: " << val1 << std::endl;
        val1 = updatedValue;
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
    static float updateValue(U& that, const float& updatedValue) // 10
    {
        std::cout << "U's val1 value: " << that.val1 << std::endl;
        that.val1 = updatedValue;
        std::cout << "U's val1 updated value: " << that.val1 << std::endl;
        while (std::abs(that.val2 - that.val1) > 0.001f)
        {
            /*
             write something that makes the distance between that.val2 and
             that.val1 get smaller
             */
            that.val2 -= (that.val2 - that.val1) / 2;
        }
        std::cout << "U's val2 updated value: " << that.val2 << std::endl;
        return that.val2 * that.val1;
    }
};

int main()
{
    T t1(3, "3"); // 6
    T t2(4, "4"); // 6

    Comparator f; // 7
    if (auto* smaller = f.compare(t1, t2))
    {
        std::cout << "the smaller one is " << smaller->name << std::endl; // 9
    }

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: "
              << Updater::updateValue(u1, updatedValue) << std::endl; // 11

    U u2;
    std::cout << "[member func] u2's multiplied values: "
              << u2.updateValue(updatedValue) << std::endl;
}
