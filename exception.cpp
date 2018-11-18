//
//  exception.cpp
//  boost_t
//
//  Created by KevinLiu on 2018/11/17.
//  Copyright © 2018 KevinLiu. All rights reserved.
//

#include <stdio.h>
#include "stddefine.h"
#include <boost/exception/all.hpp>
#include <exception>

/*class cexception1 : public std::exception
{
public:
    cexception1(const char *msg, int err):
    std::exception(),err_no(err){ }
    
    int get_err_no() const
    { return err_no; }
private:
    int err_no;
};*/

//define two types of exception info
typedef boost::error_info<struct tag_err_no, int> err_no;
typedef boost::error_info<struct tag_err_str, string> err_str;

//define an exception class
//  use virtual inheritance
struct cexception2:
    virtual std::exception,
    virtual boost::exception
{ };

struct cexception3
{ };

void exception_demo()
{
    using namespace boost;
    cout<<"start....."<<endl;
    //use self-defined exception class
    try{
        try {
            //throw exception with err no 10
            throw cexception2() << err_no(10);
        } catch (cexception2 & e) {
            //get ptr to exception info
            cout << *get_error_info<err_no>(e)<<endl;
            cout << e.what() << endl;
            //add more info to exception
            e << err_str("other info");
            throw;
        }
    }catch(cexception2 &e){
        cout<<*get_error_info<err_str>(e)<<endl;
    }
    cout<<"end....."<<endl;
    
    //wrap exception
    try{
        throw enable_error_info(cexception3()) << errinfo_errno(11);
    }catch(boost::exception &e){
        cout<< *get_error_info<errinfo_errno>(e)<<endl;
    }
}
