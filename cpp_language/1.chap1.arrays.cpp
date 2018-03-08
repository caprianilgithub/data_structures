#include "1.chap1.arrays.h"
#include "stdio.h"


OneDimensionalArrays::OneDimensionalArrays()
:m_array(NULL), m_arraydeviation(NULL), m_total(0), m_numelems(0)
{}

OneDimensionalArrays::OneDimensionalArrays(int numelems)
:m_numelems(numelems), m_total(0)
{
    m_array = new int[numelems];
    m_arraydeviation = new int[numelems];
}

error_t OneDimensionalArrays::read()
{
    cout << "Enter " << m_numelems << endl;
    for(int i = 0 ; i < m_numelems; i++){
        scanf("%d", (m_array + i));
        m_total = m_total + m_array[i];
    }
}

OneDimensionalArrays& OneDimensionalArrays::operator=(const OneDimensionalArrays& param)
{
    if(&param != this)
    {
        delete[] m_array;
        delete[] m_arraydeviation;
        m_array = NULL;
        m_arraydeviation = NULL;
    }
    
    return(*this);
}

void * OneDimensionalArrays::operator new(size_t size)
{
    cout << "Overloading new operator with size: " << size << endl;
    void * p = ::operator new(size);
    return p;
}

void OneDimensionalArrays::operator delete(void* p)
{
    cerr << "delete" << endl;
    ::operator delete(p);
}


error_t OneDimensionalArrays::calculateDeviation()
{
    for(int i = 0 ; i < m_numelems; i++){
        m_arraydeviation[i] = m_total - m_array[i];
    }
    return(0);
}

error_t OneDimensionalArrays::printdeviation()
{
    for(int i = 0 ; i < m_numelems; i++){
        cout << i << ": " << m_arraydeviation[i] - m_array[i]<< endl;
    }
}


OneDimensionalArrays::~OneDimensionalArrays()
{
    delete m_array;
    delete m_arraydeviation;
}


int main()
{
    OneDimensionalArrays array(10);
    array.read();
    array.calculateDeviation();
    array.printdeviation();
}
