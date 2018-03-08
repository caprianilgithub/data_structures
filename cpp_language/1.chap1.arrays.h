#include <iostream>

using namespace std;

typedef int error_t;

class OneDimensionalArrays
{
    int m_numelems;
    int *m_array;
    int *m_arraydeviation;
    int m_total;

    public:
        OneDimensionalArrays();
        OneDimensionalArrays(int numelems);
        error_t read();
        error_t calculateDeviation();
        error_t printdeviation();
        void operator delete[]( void* ptr );
        OneDimensionalArrays& operator=(const OneDimensionalArrays& param);

        
        /*
         * operator new can be called explicitly as a regular function, but in C++, new is an 
         * operator with a very specific behavior: An expression with the new operator, first 
         * calls function operator new (i.e., this function) with the size of its type specifier as 
         * first argument, and if this is successful, it then automatically 
         * initializes or constructs the object (if needed). Finally, 
         * the expression evaluates as a pointer to the appropriate type.
         */
        /*
         * An expression with the delete[] operator, first calls the appropriate destructors for 
         * each element in the array (if these are of a class type), and then calls an array deallocation function.
         * The array deallocation function for a class object is a member function named operator delete[], if it exists. 
         * In all other cases * * it is a global function operator delete[] (i.e., this function -- or a more specific overload). 
         * If the delete[] expression is preceded by the scope operator (i.e., ::operator delete[]), only global array deallocation functions
         * are considered.
         */
        void* operator new(std::size_t count );
        

        void operator delete(void* p);
        ~OneDimensionalArrays();
};


