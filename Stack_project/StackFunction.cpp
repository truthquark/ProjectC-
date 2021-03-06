//--------------------------------------------------
//! @file StackFunction.cpp
//! Implements a stack class
//!
//! @author Mamontova Tatyana, Feb. 2017
//--------------------------------------------------

#include "StackHeader.h"
#include <assert.h>
#include <iostream>
#include <iomanip>

void MyStack::ASSERT_OK()
{
   if (!ok())
    {
        damp();
        assert(0);
    }
}


MyStack::MyStack()
{
    size_ = 0;

}

void MyStack::damp()
{
    if (! ok())
    {
        std::cout << "Stack(ERROR)" << std::endl;
    }
    else
    {
        std::cout << "Stack(OK)" << std::endl;
    }

    std::cout << "\t maximum_size =" << reserve_ << "\n" << "\t current_size =" << getSize()<< "\n" << " \t elements data" << std::endl;

    for (int i =0; i < reserve_; i++ )
    {
        std::cout << "\t\t [" << i << "]" << " " <<Data[i] << "\n";
    }
}


float& MyStack::operator[](const unsigned int _n)
{

    ASSERT_OK();
    if(_n >= size_)
    {
        std::cout << "You don't have such element in your stack" << std::endl;
        assert(0);
    }


    return Data[_n];
}


void MyStack::clr()
{
    size_ = 0;
}

MyStack::~MyStack()
{
    clr();
}

float MyStack::top()
{
    if(empty())
    {
        std::cout << "You don't have such element in your stack" << std::endl;
        return 0;
    }
    else
    {
        return Data[size_-1];
    }
}

bool MyStack::push(float _value)
{
    ASSERT_OK();
    if (size_ >= reserve_)
    {
        std::cout << "You can't push the new value" << std::endl;
        return false;
    }
    Data [size_++] = _value;

    ASSERT_OK();
    return true;
}

bool MyStack::empty()
{
    ASSERT_OK();

    if (size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyStack::pop()
{
    ASSERT_OK();

    if(empty())
    {
        std::cout << "You don't have enough elements" << std::endl;

    }
    else
    {
        unsigned int new_size = size_ - 1;

        float *pNewData = new float[size_ - 1];

        for (unsigned int i=0; i < size_ - 1; i++)
        {
            pNewData[i] = Data[i];
        }

        clr();

        size_ = new_size;

        for (unsigned int i=0; i < size_; i++)
        {
           Data[i] = pNewData[i];
        }

        ASSERT_OK();
    }

}
