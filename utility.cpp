//
//  utility.cpp
//  boost_t
//
//  Created by KevinLiu on 2018/11/17.
//  Copyright © 2018 KevinLiu. All rights reserved.
//

#include <stdio.h>
#include "stddefine.h"
#include <utility>
#include <boost/logic/tribool.hpp>
#include <boost/optional/optional.hpp>
#include <boost/operators.hpp>
using namespace boost;

namespace third_state
{
  BOOST_TRIBOOL_THIRD_STATE(unknow)
};

void check_status(tribool tb)
{
    if(tb){
        cout<<"is true"<<endl;
    }else if(!tb){
        cout<<"is false"<<endl;
    }else{
        cout<<"is indeterminated"<<endl;
    }
}

void check_status(optional<bool> b)
{
    if(!b){
        cout<<"is indeterminated"<<endl;
    }else if(b && *b){
        cout<<"is true"<<endl;
    }else{
        cout<<"is false"<<endl;
    }
}

class demo_c
{
public:
    demo_c(int n):x(n){}
    friend bool operator<(const demo_c &l, const demo_c &r)
    { return l.x < r.x; }
    
private:
    int  x;
};

//define compare
class point: boost::less_than_comparable<point>,
boost::equality_comparable<point>
{
public:
    explicit point(int a=0, int b=0, int c=0):
    x(a),y(b),z(c){ }
    void print()
    { cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;}
    friend bool operator<(const point &l, const point &r)
    {
        return (l.x*l.x + l.y*l.y + l.z*l.z) <
        (r.x*r.x + r.y*r.y + r.z*r.z);
    }
    friend bool operator==(const point &l, const point &r)
    {
        return l.x == r.x && l.y == r.y && l.z == r.z;
    }
    
private:
    int x, y, z;
};

void utility_demo()
{
    //use tri bools
    tribool tb1(true);
    tribool tb2(!tb1);
    tribool tb3 = indeterminate;
    
    check_status(tb1);
    check_status(tb2);
    check_status(tb3);
    
    //user define the 3rd state
    tribool tr4(third_state::unknow);
    if(third_state::unknow(tr4) /*&& tr4 == tribool::indeterminate_value*/){
        cout<<"unknow state"<<endl;
    }
    
    //use optional state
    cout<<"..optional bool"<<endl;
    optional<bool> b1;//non-init optional bool
    check_status(b1);
    b1 = false;
    check_status(b1);
    
    //use relation operator
    using namespace std::rel_ops; //auto add !=, >, <=, >=
    demo_c a1(10), a2(20);
    cout<<(a1 < a2)<<endl;
    cout<<(a2 >= a1)<<endl;
    
    //point
    point p1(1, 4, 6), p2(2, 3, 2);
    if(p1 == p2){
        cout<<"equal"<<endl;
    }
    
    if(p1 != p1){
        cout<<"inequal"<<endl;
    }
    
    if(p1 < p2){
        cout<<"less than"<<endl;
    }
}
